TESTS = tests
IGNORE_ERROR = || true

PROJECT_DIR				= ../src
PROJECT_HEADERS_DIR		= $(PROJECT_DIR)/includes/
PROJECT_INCLUDES		= -I$(PROJECT_HEADERS_DIR)
PROJECT_SRCS			:= $(filter-out $(PROJECT_DIR)/main.cpp, \
								$(shell find $(PROJECT_DIR) -name "*.cpp"))
PROJECT_OBJS			= $(patsubst %.cpp, %.o, $(PROJECT_SRCS))

TESTS_DIR				= unitTests
TESTS_SRCS				= $(shell find $(TESTS_DIR) -name "*.cpp")
TESTS_OBJS				= $(patsubst %.cpp, %.o, $(TESTS_SRCS))
TESTS_DFILES			= $(patsubst %.cpp, %.d, $(TESTS_SRCS))

ALL_SRCS				= $(PROJECT_SRCS) $(TESTS_SRCS)
ALL_OBJECTS				= $(PROJECT_OBJS) $(TESTS_OBJS)

GTEST_DIR				= dependencies
GTEST_DIR_REPOSITORY	= $(GTEST_DIR)/googletest
GTEST_HEADERS_DIR		= $(GTEST_DIR)/gtest
GTEST_INCLUDES			= -I$(GTEST_HEADERS_DIR)
GTEST_LIB				= -pthread $(GTEST_DIR)/lib/libgtest_main.a $(GTEST_DIR)/lib/libgtest.a

CPPFLAGS += -isystem -std=c++17
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++17

all:
	@rm -rf $(GTEST_DIR)/lib
	@cd $(GTEST_DIR_REPOSITORY)
	@rm -rf build
	@mkdir build
	@cd build
	@cmake ..
	@make
	@make install
	@mv lib ../../
	@cd ../../..
	run

clean:
	@rm -f $(TESTS_OBJS) $(TESTS_DFILES)
	@cd $(PROJECT_DIR) && $(MAKE) clean

fclean: clean
	@rm -f $(TESTS)
	@cd $(PROJECT_DIR) && $(MAKE) fclean

re: fclean all

$(PROJECT_OBJS):
	cd $(PROJECT_DIR) && $(MAKE) objects
	rm -f $(PROJECT_DIR)/main.o $(PROJECT_DIR)/main.d

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(GTEST_INCLUDES) $(PROJECT_INCLUDES) $< -o $@ -MMD

$(TESTS): $(PROJECT_OBJS) $(TESTS_OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ALL_OBJECTS) $(GTEST_LIB) $(GTEST_INCLUDES) -o $@

run : $(TESTS)
	./$(TESTS) $(IGNORE_ERROR)
	$(MAKE) fclean

# TODO: поизучать, как правильно
# считать покрытие тестами: https://stackoverflow.com/questions/2359344/google-test-code-coverage
# coverage: $(TESTS)
# 	gcov $(PROJECT_SRCS)

include $(wildcard $(TESTS_DFILES))

.PHONY: all clean fclean re coverage run
