#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3) { s21_create_matrix(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  s21_create_matrix();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  s21_create_matrix();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  matrix_ = nullptr;
}

int S21Matrix::get_rows() const { return rows_; }

int S21Matrix::get_cols() const { return cols_; }

void S21Matrix::set_rows(int new_rows) {
  if (new_rows != rows_) {
    S21Matrix temp(new_rows, cols_);
    for (int i = 0; i < std::min(new_rows, rows_); ++i) {
      for (int j = 0; j < cols_; ++j) {
        temp.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(temp);
  }
}

void S21Matrix::set_cols(int new_cols) {
  if (new_cols != cols_) {
    S21Matrix temp(rows_, new_cols);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < std::min(new_cols, cols_); ++j) {
        temp.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(temp);
  }
}

void S21Matrix::s21_create_matrix() {
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

bool S21Matrix::eq_matrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  bool flag = true;
  for (int i = 0; i < rows_ && flag; i++) {
    for (int j = 0; j < cols_ && flag; j++) {
      flag = matrix_[i][j] == other.matrix_[i][j];
    }
  }
  return flag;
}

void S21Matrix::sum_matrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::sub_matrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::mul_matrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Incorrect input, the number of columns of the first matrix is not "
        "equal to the number of rows of the second matrix.");
  }
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      result.matrix_[i][j] = 0;
      for (int k = 0; k < other.rows_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::get_minor_matrix(int skip_row, int skip_col) const {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  int minor_row = 0;
  for (int i = 0; i < rows_; i++) {
    if (i == skip_row) continue;
    int minor_col = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == skip_col) continue;
      minor.matrix_[minor_row][minor_col] = matrix_[i][j];
      minor_col++;
    }
    minor_row++;
  }
  return minor;
}

double S21Matrix::determinant() {
  if (cols_ != rows_) {
    throw std::out_of_range("Incorrect input, matrix must be square.");
  }
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    result = 0;
    for (int k = 0; k < rows_; k++) {
      S21Matrix minor = get_minor_matrix(0, k);
      result += pow(-1, k) * matrix_[0][k] * minor.determinant();
    }
  }
  return result;
}

S21Matrix S21Matrix::calc_complements() {
  if (cols_ != rows_) {
    throw std::out_of_range("Incorrect input, matrix must be square.");
  }

  if (rows_ == 1) {
    S21Matrix result(1, 1);
    result.matrix_[0][0] = 1;
    return result;
  }

  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor = get_minor_matrix(i, j);
      double minor_det = minor.determinant();
      result.matrix_[i][j] = pow(-1, i + j) * minor_det;
    }
  }
  return result;
}

S21Matrix S21Matrix::inverse_matrix() {
  double det = determinant();
  if (det == 0) {
    throw std::runtime_error(
        "Incorrect input, determinant should not be equal 0.");
  }
  S21Matrix result = this->transpose().calc_complements();
  result.mul_number(1.0 / det);
  return result;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;

    rows_ = other.rows_;
    cols_ = other.cols_;
    s21_create_matrix();
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  sum_matrix(other);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.sum_matrix(other);
  return result;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  sub_matrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.sub_matrix(other);
  return result;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  mul_matrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  mul_number(num);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.mul_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.mul_number(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) { return eq_matrix(other); }
