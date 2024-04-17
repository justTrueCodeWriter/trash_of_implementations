#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

class Matrix {
  public:
  int rows_ = 0;
  int cols_ = 0;
  int** matr;
  
  Matrix(int rows, int cols) {
    rows_ = rows, cols_ = cols;
    matr = new int*[rows];
    for (int i = 0; i < rows; i++)
      matr[i] = new int[cols];
  }
  ~Matrix() {
    for (int i = 0; i < rows_; i++)
      delete[] matr[i];
  }

  void print() {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        std::cout << matr[i][j] << " ";
      }
      std::cout << "\n";
    }
      std::cout << "\n";
  }

  std::string toString() {
    std::string result;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        result.push_back(matr[i][j]);
        result.push_back(' ');
      }
      result.push_back('\n');
    }
    return result;
  }
};

void fill_matrix(Matrix* matr) {
  int value = 1;
  for (int i = 0; i < matr->rows_; i++) {
    for (int j = 0; j < matr->cols_; j++) {
      matr->matr[i][j] = value++;
    }
  }
  matr->print();
}

std::string plus(Matrix* matr_1, Matrix* matr_2) {

  if (matr_1->rows_ != matr_2->rows_ && matr_1->cols_ != matr_2->cols_) return "Invalid size of matrix";

  std::string result;

  for (int i = 0; i < matr_1->rows_; i++) {
    for (int j = 0; j < matr_1->cols_; j++) {
      result.push_back(matr_1->matr[i][j]+matr_2->matr[i][j]+'0');
      result.push_back(' ');
    }
    result.push_back('\n');
  }

  return result;
}
std::string minus(Matrix* matr_1, Matrix* matr_2) {

  if (matr_1->rows_ != matr_2->rows_ && matr_1->cols_ != matr_2->cols_) return "Invalid size of matrix";

  std::string result;

  for (int i = 0; i < matr_1->rows_; i++) {
    for (int j = 0; j < matr_1->cols_; j++) {
      result.push_back(matr_1->matr[i][j]-matr_2->matr[i][j]+'0');
      result.push_back(' ');
    }
    result.push_back('\n');
  }
  return result;
}
std::string multiply(Matrix* matr_1, Matrix* matr_2) {
  if (matr_1->cols_!=matr_2->rows_) return "Invalid size for multiply";

  Matrix* tmp = new Matrix(matr_1->rows_, matr_2->cols_);
  std::string result;
  for (int i = 0; i < matr_1->rows_; i++)
    for (int j = 0; j < matr_2->cols_; j++)
      for (int k = 0; k < matr_1->cols_; k++)
        tmp->matr[i][j] += matr_1->matr[i][k] * matr_2->matr[k][j];

  tmp->print();
  result = tmp->toString();
  delete tmp;

  return result;
}
std::string divide(Matrix* matr_1, Matrix* matr_2) {
  std::string result = "Invalid operation";
  return result;
}
std::string pow(Matrix* matr_1, int value) {
  std::string result;
  return result;
}

int main() {
  std::string result;

  Matrix *matr_1 = new Matrix(2, 2);
  Matrix *matr_2 = new Matrix(2, 2);

  fill_matrix(matr_1);
  fill_matrix(matr_2);

  result = plus(matr_1, matr_2);
  std::cout << "Plus: " << result << std::endl;
  result = minus(matr_1, matr_2);
  std::cout << "Minus: " << result << std::endl;
  result = multiply(matr_1, matr_2);
  std::cout << "Multiply: " << result << std::endl;
  result = divide(matr_1, matr_2);
  std::cout << "Divide: " << result << std::endl;
  result = pow(matr_1, 2);
  std::cout << "Pow: " << result << std::endl;
}
