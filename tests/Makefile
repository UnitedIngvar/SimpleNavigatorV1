TESTS = tests
IGNORE_ERROR = || true

PROJECT_DIR				= ../src
PROJECT_HEADERS_DIR		= $(PROJECT_DIR)/includes/
PROJECT_INTERFACES_DIR	= $(PROJECT_DIR)/interfaces/
PROJECT_INCLUDES		= -I$(PROJECT_HEADERS_DIR) -I$(PROJECT_INTERFACES_DIR)
PROJECT_SRCS			:= $(filter-out $(PROJECT_DIR)/main.cpp, \
								$(shell find $(PROJECT_DIR) -name "*.cpp"))
PROJECT_OBJS			= $(patsubst %.cpp, %.o, $(PROJECT_SRCS))

TESTS_DIR				= unitTests
TESTS_INCLUDES			=
TESTS_SRCS				= $(shell find $(TESTS_DIR) -name "*.cpp")
TESTS_OBJS				= $(patsubst %.cpp, %.o, $(TESTS_SRCS))
TESTS_DFILES			= $(patsubst %.cpp, %.d, $(TESTS_SRCS))

ALL_SRCS				= $(PROJECT_SRCS) $(TESTS_SRCS)
ALL_OBJECTS				= $(PROJECT_OBJS) $(TESTS_OBJS)

GTEST_DIR				= dependencies
GTEST_DIR_REPOSITORY	= $(GTEST_DIR)/googletest
GTEST_HEADERS_DIR		= $(GTEST_DIR_REPOSITORY)/googletest/include/gtest
GTEST_INCLUDES			= -I$(GTEST_HEADERS_DIR)
GTEST_LIB				= -pthread $(GTEST_DIR)/lib/libgtest_main.a $(GTEST_DIR)/lib/libgtest.a

GMOCK_DIR				= dependencies
GMOCK_HEADERS_DIR		= $(GTEST_DIR_REPOSITORY)/googlemock/include/gmock
GMOCK_INCLUDES			= -I$(GMOCK_HEADERS_DIR)
GMOCK_LIB				= -pthread $(GTEST_DIR)/lib/libgmock_main.a $(GTEST_DIR)/lib/libgmock.a

CPPFLAGS += -isystem
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++17 #-fsanitize=address,undefined -fno-sanitize-recover -fstack-protector -O0

all: build_gtest run

leaks: build_gtest run_leaks

build_gtest:
	@cd $(GTEST_DIR_REPOSITORY); \
	mkdir -p build && cd build; \
	cmake .. && make && make install; \
	mv lib ../.. >/dev/null 2>&1 || cd ../..

clean:
	@rm -f $(TESTS_OBJS) $(TESTS_DFILES)
	@cd $(PROJECT_DIR) && $(MAKE) clean

fclean: clean
	@rm -f $(TESTS)
	@rm -rf $(GTEST_DIR)/lib $(GTEST_DIR_REPOSITORY)/build
	@cd $(PROJECT_DIR) && $(MAKE) fclean

re: fclean all

$(PROJECT_OBJS):
	cd $(PROJECT_DIR) && $(MAKE) objects
	rm -f $(PROJECT_DIR)/main.o $(PROJECT_DIR)/main.d

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(GTEST_INCLUDES) $(GMOCK_INCLUDES) $(PROJECT_INCLUDES) $< -o $@ -MMD

$(TESTS): $(PROJECT_OBJS) $(TESTS_OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ALL_OBJECTS) $(GTEST_LIB) $(GMOCK_LIB) $(GTEST_INCLUDES) $(GMOCK_INCLUDES) -o $@

run : $(TESTS)
	./$(TESTS) $(IGNORE_ERROR)
	$(MAKE) fclean

run_leaks : $(TESTS)
	leaks --atExit -- ./$(TESTS) $(IGNORE_ERROR)
	$(MAKE) fclean

# TODO: поизучать, как правильно
# считать покрытие тестами: https://stackoverflow.com/questions/2359344/google-test-code-coverage
#coverage: $(TESTS)
#		gcov $(PROJECT_SRCS)

include $(wildcard $(TESTS_DFILES))

.PHONY: all clean fclean re coverage build_gtest run
