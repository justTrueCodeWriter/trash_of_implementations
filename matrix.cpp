#include <iostream>
#include <string>

class Matrix {
  public:
  int** matr;
  
  Matrix(int rows, int cols) {
    matr = new int*[rows];
    for (int i = 0; i < rows; i++)
      matr[i] = new int[cols];
  }
  void add() {
    
  }
};

std::string plus(int** matr_1, int** matr_2) {
  

  std::string result;
  return result;
}
std::string minus(int** matr_1, int** matr_2) {
  std::string result;
  return result;
}
std::string multiply(int** matr_1, int** matr_2) {
  std::string result;
  return result;
}
std::string divide(int** matr_1, int** matr_2) {
  std::string result;
  return result;
}
std::string pow(int** matr_1, int value) {
  std::string result;
  return result;
}

int main() {
  std::string result;

  Matrix *matr_1 = new Matrix(2, 2);
  Matrix *matr_2 = new Matrix(2, 2);

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
