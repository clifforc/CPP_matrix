# s21_matrix+

## Description

s21_matrix+ is an implementation of a library for working with matrices in C++. The project is developed as part of an educational program aimed at deepening the understanding of matrix operations, object-oriented programming, and working with C++.

- The library is developed in C++ language standard C++17 using the gcc compiler;
- The library is designed as a static library named `s21_matrix_oop.a`;
- The project is fully covered with unit tests using the Google Test (gtest) library.

## Implemented Methods and Operators

### Constructors and Destructor
1. Basic constructor;
2. Parameterized constructor;
3. Copy constructor;
4. Move constructor;
5. Destructor.

### Overloaded Operators
- `+`: Addition of two matrices;
- `-`: Subtraction of one matrix from another;
- `*`: Matrix multiplication and multiplication of a matrix by a number;
- `==`: Checking matrices for equality;
- `=`: Assigning the values of one matrix to another;
- `+=`: Addition assignment;
- `-=`: Subtraction assignment;
- `*=`: Multiplication assignment;
- `(int i, int j)`: Indexing matrix elements.

### Public Methods
1. `eq_matrix`: Comparing matrices;
2. `sum_matrix`: Adding matrices;
3. `sub_matrix`: Subtracting matrices;
4. `mul_number`: Multiplying a matrix by a number;
5. `mul_matrix`: Multiplying matrices;
6. `transpose`: Transposing a matrix;
7. `calc_complements`: Calculating the matrix of algebraic complements;
8. `determinant`: Calculating the determinant of a matrix;
9. `inverse_matrix`: Finding the inverse matrix.

## Building and Usage

A Makefile is used to build the library and run tests with the following targets:

- `make all`: build the entire project (create a static library);
- `make clean`: clean build files;
- `make test`: run unit tests;
- `make s21_matrix_oop.a`: build the static library;
- `make gcov_report`: generate a test coverage report;
- `make cpp`: check the code using cppcheck;
- `make rebuild`: rebuild the project (clean + build).

## License

This project is part of the educational program at [School21](https://21-school.ru/) - an educational project by Sber for developers.