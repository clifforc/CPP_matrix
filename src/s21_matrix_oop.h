#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cmath>
#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  // attributes
  int rows_, cols_;
  double **matrix_;

  // private methods
  void s21_create_matrix();
  S21Matrix get_minor_matrix(int skip_row, int skip_col) const;

 public:
  S21Matrix();                        // default constructor
  S21Matrix(int rows, int cols);      // parameterized constructor
  S21Matrix(const S21Matrix &other);  // copy cnstructor
  S21Matrix(S21Matrix &&other);       // move cnstructor
  ~S21Matrix();                       // destructor

  // operators overloads
  S21Matrix &operator=(const S21Matrix &other);
  double &operator()(int row, int col);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix &operator*=(const double num);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix operator*(const double num);
  S21Matrix operator*(const S21Matrix &other);
  bool operator==(const S21Matrix &other);

  // public methods
  bool eq_matrix(const S21Matrix &other);
  void sum_matrix(const S21Matrix &other);
  void sub_matrix(const S21Matrix &other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix &other);
  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

  int get_rows() const;
  int get_cols() const;
  void set_rows(int new_rows);
  void set_cols(int new_cols);
};

#endif
