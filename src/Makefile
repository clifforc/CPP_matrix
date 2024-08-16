DATE = $(shell date -R)
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -pedantic -g

DB = -g -O0
OBJ = obj
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(OBJ)/%.o, $(SOURCES))
TEST = s21_test
TEST_DIR = ./tests/
RM_EXTS := o a out gcno gcda gcov info html css

OS := $(shell uname)
UBUNTU := $(shell hostnamectl | grep -o 'Ubuntu')
MAC_X86 := $(shell uname -a | grep -o _X86_64)
MAC_ARM := $(shell uname -a | grep -o _ARM64)

GTEST_INCLUDE = $(shell brew --prefix googletest)/include
GTEST_LIB = $(shell brew --prefix googletest)/lib
GTEST_FLAGS = -DGTEST_HAS_PTHREAD=1 -I$(GTEST_INCLUDE) -L$(GTEST_LIB) -lgtest

ifeq ($(OS), Linux)
    TEST_LIBS = $(GTEST_FLAGS) -lpthread
    MATH = -lm
    OPEN = xdg-open
else ifeq ($(UBUNTU), Ubuntu)
    TEST_LIBS = $(GTEST_FLAGS) -lpthread
    OPEN = open
endif

ifeq ($(MAC_ARM), _ARM64)
    TEST_LIBS := $(GTEST_FLAGS)
    OPEN = open
endif
ifeq ($(MAC_X86), _X86_64)
    TEST_LIBS = $(GTEST_FLAGS) -lpthread
    OPEN = open
endif

all: s21_matrix_oop.a

build: all

repo:
	mkdir -p $(OBJ)

$(OBJ)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

s21_matrix_oop.a: repo $(OBJECTS)
	ar rcs s21_matrix_oop.a $(OBJ)/*.o
	ranlib s21_matrix_oop.a

test: s21_matrix_oop.a
	$(CXX) $(CXXFLAGS) $(TEST_DIR)test_matrix.cpp *.cpp s21_matrix_oop.a $(TEST_LIBS) -o $(TEST)
	./$(TEST)

ifeq ($(OS),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST)
else
	leaks --atExit -- ./$(TEST)
endif


gcov_flag:
	$(eval CXXFLAGS += --coverage)

gcov_report: clean s21_matrix_oop.a
	$(CXX) $(CXXFLAGS) $(GTEST_FLAGS) --coverage *.cpp $(TEST_DIR)test_matrix.cpp s21_matrix_oop.a $(TEST_LIBS) -o report.out
	./report.out
	gcovr --html-details -o report.html --exclude 'tests/.*'
	$(OPEN) report.html


cpp: reset
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c++17 --language=c++ --suppress=unusedFunction --suppress=unusedStructMember ./*.cpp *.h ./tests/*.cpp ./tests/*.h

rebuild: clean build

clean:
	rm -rf $(TEST) *.o *.a *.gcno *.gcda *.gcov *.info report a.out *.dSYM $(OBJ)
	@for ext in $(RM_EXTS); do \
	find ./ -type f -name "*.$$ext" -exec rm {} \;; \
	done
	@rm -rf ./report
	@rm -rf ./$(OBJ)

.PHONY: clean
reset:
	reset | bash