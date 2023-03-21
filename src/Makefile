NAME					= graph

LIB_DIR					= ./lib
GRAPH_LIB				= $(LIB_DIR)/libGraph.a
ALGOS_LIB				= $(LIB_DIR)/libAlgos.a

APP_DIR					= app
APP_HEADERS_DIR			= $(APP_DIR)/includes
APP_INCLUDES			= -I$(APP_HEADERS_DIR)
APP_SRCS				= $(shell find $(APP_DIR) -name "*.cpp")
APP_OBJS				= $(patsubst %.cpp, %.o, $(APP_SRCS))
APP_D_FILES				= ${patsubst %.cpp, %.d, ${APP_SRCS}}


## s21_graph.h static library sources
GRAPH_DIR				= graph
GRAPH_HEADERS_DIR		= $(GRAPH_DIR)/includes
GRAPH_INTERFACES_DIR	= $(GRAPH_DIR)/interfaces
GRAPH_INCLUDES			= -I$(GRAPH_HEADERS_DIR) -I$(GRAPH_INTERFACES_DIR)
GRAPH_SRCS				:= $(shell find $(GRAPH_DIR) -name "*.cpp")
GRAPH_OBJS				= $(patsubst %.cpp, %.o, $(GRAPH_SRCS))
GRAPH_D_FILES					= ${patsubst %.cpp, %.d, ${GRAPH_SRCS}}

## s21_graph_algorithms.h static library sources
ALGOS_DIR				= graph_algorithms
ALGOS_HEADERS_DIR		= $(ALGOS_DIR)/includes $()
ALGOS_INCLUDES			= -I$(ALGOS_HEADERS_DIR) $(GRAPH_INCLUDES)
ALGOS_SRCS				:= $(shell find $(ALGOS_DIR) -name "*.cpp")
ALGOS_OBJS				= $(patsubst %.cpp, %.o, $(ALGOS_SRCS))
ALGOS_D_FILES			= ${patsubst %.cpp, %.d, ${ALGOS_SRCS}}

CC				= clang++
CFLAGS			= -Werror -Wall -Wextra -std=c++17 #-fsanitize=address,undefined -fno-sanitize-recover -fstack-protector -g -O0
AR				= ar -rcs

all: $(NAME)

$(LIB_DIR):
		mkdir $(LIB_DIR)

libs: $(ALGOS_LIB) $(GRAPH_LIB)

$(GRAPH_DIR)/%.o: $(GRAPH_DIR)/%.cpp
		$(CC) $(CFLAGS) -c $(GRAPH_INCLUDES) $< -o $@ -MMD

$(GRAPH_LIB): $(GRAPH_OBJS) $(LIB_DIR)
		$(AR) $(GRAPH_LIB) $(GRAPH_OBJS)


$(ALGOS_DIR)/%.o: $(ALGOS_DIR)/%.cpp
		$(CC) $(CFLAGS) -c $(ALGOS_INCLUDES) $< -o $@ -MMD

$(ALGOS_LIB): $(ALGOS_OBJS)
		$(AR) $(ALGOS_LIB) $(ALGOS_OBJS)


$(NAME): $(GRAPH_LIB) $(ALGOS_LIB) $(APP_SRCS)
		$(CC) $(CFLAGS) $(APP_SRCS) $(GRAPH_LIB) $(ALGOS_LIB) $(APP_INCLUDES) $(ALGOS_INCLUDES) -o $(NAME)

clean:
		@rm -f $(GRAPH_OBJS) $(ALGOS_OBJS) $(APP_OBJS) \
		$(APP_D_FILES) $(GRAPH_D_FILES) $(ALGOS_D_FILES) $(GRAPH_LIB) $(ALGOS_LIB)

fclean: clean
		@rm -f $(NAME)

re:		fclean all

test:
	cd ../tests && ${MAKE}

include $(wildcard $(APP_D_FILES) $(GRAPH_D_FILES) $(ALGOS_D_FILES))

.PHONY: all clean fclean re
