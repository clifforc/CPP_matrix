#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

class S21MatrixTest : public ::testing::Test {
 protected:
  void SetUp() override {
    matrix1 = S21Matrix(3, 3);
    matrix2 = S21Matrix(3, 3);
    matrix3 = S21Matrix(3, 3);
    matrix4 = S21Matrix(1, 3);
    matrix5 = S21Matrix(1, 1);
    matrix6 = S21Matrix(3, 1);

    matrix1(0, 0) = 1;
    matrix1(0, 1) = 2;
    matrix1(0, 2) = 3;
    matrix1(1, 0) = 4;
    matrix1(1, 1) = 5;
    matrix1(1, 2) = 6;
    matrix1(2, 0) = 7;
    matrix1(2, 1) = 8;
    matrix1(2, 2) = 9;

    matrix2(0, 0) = 11;
    matrix2(0, 1) = 12;
    matrix2(0, 2) = 13;
    matrix2(1, 0) = 14;
    matrix2(1, 1) = 15;
    matrix2(1, 2) = 16;
    matrix2(2, 0) = 17;
    matrix2(2, 1) = 18;
    matrix2(2, 2) = 19;

    matrix3(0, 0) = 1;
    matrix3(0, 1) = 2;
    matrix3(0, 2) = 3;
    matrix3(1, 0) = 4;
    matrix3(1, 1) = 5;
    matrix3(1, 2) = 6;
    matrix3(2, 0) = 7;
    matrix3(2, 1) = 8;
    matrix3(2, 2) = 9;

    matrix4(0, 0) = 1;
    matrix4(0, 1) = 2;
    matrix4(0, 2) = 3;

    matrix5(0, 0) = 5;

    matrix6(0, 0) = 1;
    matrix6(1, 0) = 2;
    matrix6(2, 0) = 3;
  }

  S21Matrix matrix1;
  S21Matrix matrix2;
  S21Matrix matrix3;
  S21Matrix matrix4;
  S21Matrix matrix5;
  S21Matrix matrix6;
};

TEST_F(S21MatrixTest, AssignmentOperator) {
  matrix1 = matrix2;
  EXPECT_EQ(matrix1(0, 0), matrix2(0, 0));
  EXPECT_EQ(matrix1(0, 1), matrix2(0, 1));
  EXPECT_EQ(matrix1(0, 2), matrix2(0, 2));
  EXPECT_EQ(matrix1(1, 0), matrix2(1, 0));
  EXPECT_EQ(matrix1(1, 1), matrix2(1, 1));
  EXPECT_EQ(matrix1(1, 2), matrix2(1, 2));
  EXPECT_EQ(matrix1(2, 0), matrix2(2, 0));
  EXPECT_EQ(matrix1(2, 1), matrix2(2, 1));
  EXPECT_EQ(matrix1(2, 2), matrix2(2, 2));
}

TEST_F(S21MatrixTest, AdditionAssignmentOperator) {
  matrix1 += matrix2;
  EXPECT_EQ(matrix1(0, 0), 12);
  EXPECT_EQ(matrix1(0, 1), 14);
  EXPECT_EQ(matrix1(0, 2), 16);
  EXPECT_EQ(matrix1(1, 0), 18);
  EXPECT_EQ(matrix1(1, 1), 20);
  EXPECT_EQ(matrix1(1, 2), 22);
  EXPECT_EQ(matrix1(2, 0), 24);
  EXPECT_EQ(matrix1(2, 1), 26);
  EXPECT_EQ(matrix1(2, 2), 28);
}

TEST_F(S21MatrixTest, AdditionOperator) {
  S21Matrix result = matrix1 + matrix2;
  EXPECT_EQ(result(0, 0), 12);
  EXPECT_EQ(result(0, 1), 14);
  EXPECT_EQ(result(0, 2), 16);
  EXPECT_EQ(result(1, 0), 18);
  EXPECT_EQ(result(1, 1), 20);
  EXPECT_EQ(result(1, 2), 22);
  EXPECT_EQ(result(2, 0), 24);
  EXPECT_EQ(result(2, 1), 26);
  EXPECT_EQ(result(2, 2), 28);
}

TEST_F(S21MatrixTest, SubstractionAssignmentOperator) {
  matrix2 -= matrix1;
  EXPECT_EQ(matrix2(0, 0), 10);
  EXPECT_EQ(matrix2(0, 1), 10);
  EXPECT_EQ(matrix2(0, 2), 10);
  EXPECT_EQ(matrix2(1, 0), 10);
  EXPECT_EQ(matrix2(1, 1), 10);
  EXPECT_EQ(matrix2(1, 2), 10);
  EXPECT_EQ(matrix2(2, 0), 10);
  EXPECT_EQ(matrix2(2, 1), 10);
  EXPECT_EQ(matrix2(2, 2), 10);
}

TEST_F(S21MatrixTest, SubstractionOperator) {
  S21Matrix result = matrix2 - matrix1;
  EXPECT_EQ(result(0, 0), 10);
  EXPECT_EQ(result(0, 1), 10);
  EXPECT_EQ(result(0, 2), 10);
  EXPECT_EQ(result(1, 0), 10);
  EXPECT_EQ(result(1, 1), 10);
  EXPECT_EQ(result(1, 2), 10);
  EXPECT_EQ(result(2, 0), 10);
  EXPECT_EQ(result(2, 1), 10);
  EXPECT_EQ(result(2, 2), 10);
}

TEST_F(S21MatrixTest, MultiplicationNumberAssignmentOperator) {
  matrix1 *= 2;
  EXPECT_EQ(matrix1(0, 0), 2);
  EXPECT_EQ(matrix1(0, 1), 4);
  EXPECT_EQ(matrix1(0, 2), 6);
  EXPECT_EQ(matrix1(1, 0), 8);
  EXPECT_EQ(matrix1(1, 1), 10);
  EXPECT_EQ(matrix1(1, 2), 12);
  EXPECT_EQ(matrix1(2, 0), 14);
  EXPECT_EQ(matrix1(2, 1), 16);
  EXPECT_EQ(matrix1(2, 2), 18);
}

TEST_F(S21MatrixTest, MultiplicationMatrixAssignmentOperator) {
  matrix1 *= matrix2;
  EXPECT_EQ(matrix1(0, 0), 90);
  EXPECT_EQ(matrix1(0, 1), 96);
  EXPECT_EQ(matrix1(0, 2), 102);
  EXPECT_EQ(matrix1(1, 0), 216);
  EXPECT_EQ(matrix1(1, 1), 231);
  EXPECT_EQ(matrix1(1, 2), 246);
  EXPECT_EQ(matrix1(2, 0), 342);
  EXPECT_EQ(matrix1(2, 1), 366);
  EXPECT_EQ(matrix1(2, 2), 390);
}

TEST_F(S21MatrixTest, MultiplicationNumberOperator) {
  S21Matrix result = matrix1 * 2;
  EXPECT_EQ(result(0, 0), 2);
  EXPECT_EQ(result(0, 1), 4);
  EXPECT_EQ(result(0, 2), 6);
  EXPECT_EQ(result(1, 0), 8);
  EXPECT_EQ(result(1, 1), 10);
  EXPECT_EQ(result(1, 2), 12);
  EXPECT_EQ(result(2, 0), 14);
  EXPECT_EQ(result(2, 1), 16);
  EXPECT_EQ(result(2, 2), 18);
}

TEST_F(S21MatrixTest, MultiplicationMatrixOperator) {
  S21Matrix result = matrix1 * matrix2;
  EXPECT_EQ(result(0, 0), 90);
  EXPECT_EQ(result(0, 1), 96);
  EXPECT_EQ(result(0, 2), 102);
  EXPECT_EQ(result(1, 0), 216);
  EXPECT_EQ(result(1, 1), 231);
  EXPECT_EQ(result(1, 2), 246);
  EXPECT_EQ(result(2, 0), 342);
  EXPECT_EQ(result(2, 1), 366);
  EXPECT_EQ(result(2, 2), 390);
}

TEST_F(S21MatrixTest, EqualityOperator) {
  EXPECT_TRUE(matrix1 == matrix3);
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(S21MatrixTest, IndexOperator) {
  EXPECT_EQ(matrix1(0, 0), 1);
  matrix1(0, 0) = 10;
  EXPECT_EQ(matrix1(0, 0), 10);
}

TEST_F(S21MatrixTest, IndexOperatorThrows) {
  EXPECT_THROW(matrix1(3, 3), std::out_of_range);
  EXPECT_THROW(matrix1(-1, 0), std::out_of_range);
  EXPECT_THROW(matrix1(0, -1), std::out_of_range);
}

TEST_F(S21MatrixTest, MoveConstructor) {
  S21Matrix result(std::move(matrix1));

  EXPECT_EQ(result(0, 0), 1);
  EXPECT_EQ(result(0, 1), 2);
  EXPECT_EQ(result(0, 2), 3);
  EXPECT_EQ(result(1, 0), 4);
  EXPECT_EQ(result(1, 1), 5);
  EXPECT_EQ(result(1, 2), 6);
  EXPECT_EQ(result(2, 0), 7);
  EXPECT_EQ(result(2, 1), 8);
  EXPECT_EQ(result(2, 2), 9);
}

TEST_F(S21MatrixTest, Exceptions) {
  EXPECT_FALSE(matrix1.eq_matrix(matrix2));
  EXPECT_FALSE(matrix1.eq_matrix(matrix4));
  EXPECT_FALSE(matrix1.eq_matrix(matrix6));

  EXPECT_THROW(matrix1.sum_matrix(matrix4), std::out_of_range);
  EXPECT_THROW(matrix4.sum_matrix(matrix1), std::out_of_range);
  EXPECT_THROW(matrix1.sum_matrix(matrix6), std::out_of_range);
  EXPECT_THROW(matrix6.sum_matrix(matrix4), std::out_of_range);

  EXPECT_THROW(matrix6.sub_matrix(matrix4), std::out_of_range);
  EXPECT_THROW(matrix4.sub_matrix(matrix6), std::out_of_range);

  EXPECT_THROW(matrix1.mul_matrix(matrix4), std::out_of_range);

  EXPECT_THROW(matrix4.determinant(), std::out_of_range);
  EXPECT_THROW(matrix4.calc_complements(), std::out_of_range);
  EXPECT_THROW(matrix1.inverse_matrix(), std::runtime_error);
}

TEST_F(S21MatrixTest, Transpose) {
  S21Matrix result = matrix4.transpose();
  EXPECT_EQ(result(0, 0), 1);
  EXPECT_EQ(result(1, 0), 2);
  EXPECT_EQ(result(2, 0), 3);
}

TEST_F(S21MatrixTest, CalcComplements) {
  S21Matrix expected1(3, 3);
  S21Matrix expected3(3, 3);

  expected1(0, 0) = 1;

  expected3(0, 0) = -3;
  expected3(0, 1) = 6;
  expected3(0, 2) = -3;
  expected3(1, 0) = 6;
  expected3(1, 1) = -12;
  expected3(1, 2) = 6;
  expected3(2, 0) = -3;
  expected3(2, 1) = 6;
  expected3(2, 2) = -3;

  S21Matrix result3 = matrix1.calc_complements();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(result3(i, j), expected3(i, j));
    }
  }

  S21Matrix result1 = matrix5.calc_complements();
  EXPECT_EQ(result1(0, 0), expected1(0, 0));
}

TEST_F(S21MatrixTest, Determinant) {
  S21Matrix det1(1, 1);
  S21Matrix det2(2, 2);
  S21Matrix det3(3, 3);

  det1(0, 0) = 5;

  det2(0, 0) = 4;
  det2(0, 1) = 3;
  det2(1, 0) = 6;
  det2(1, 1) = 3;

  det3(0, 0) = 2;
  det3(0, 1) = 5;
  det3(0, 2) = 7;
  det3(1, 0) = 6;
  det3(1, 1) = 3;
  det3(1, 2) = 4;
  det3(2, 0) = 5;
  det3(2, 1) = -2;
  det3(2, 2) = -3;

  EXPECT_DOUBLE_EQ(det1.determinant(), 5);
  EXPECT_DOUBLE_EQ(det2.determinant(), -6);
  EXPECT_DOUBLE_EQ(det3.determinant(), -1);
}

TEST_F(S21MatrixTest, InverseMatrix) {
  S21Matrix matr(3, 3);
  S21Matrix expected(3, 3);

  matr(0, 0) = 2;
  matr(0, 1) = 5;
  matr(0, 2) = 7;
  matr(1, 0) = 6;
  matr(1, 1) = 3;
  matr(1, 2) = 4;
  matr(2, 0) = 5;
  matr(2, 1) = -2;
  matr(2, 2) = -3;

  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;
  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;
  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;

  S21Matrix result = matr.inverse_matrix();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(result(i, j), expected(i, j));
    }
  }
}

TEST_F(S21MatrixTest, GetRows) { EXPECT_EQ(matrix1.get_rows(), 3); }

TEST_F(S21MatrixTest, GetCols) { EXPECT_EQ(matrix1.get_cols(), 3); }

TEST_F(S21MatrixTest, SetRows) {
  matrix1.set_rows(3);
  matrix1.set_rows(4);
  for (int i = 3; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(matrix1(i, j), 0);
    }
  }
}

TEST_F(S21MatrixTest, SetCols) {
  matrix1.set_cols(3);
  matrix1.set_cols(4);
  for (int i = 0; i < 3; i++) {
    for (int j = 3; j < 4; j++) {
      EXPECT_EQ(matrix1(i, j), 0);
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}