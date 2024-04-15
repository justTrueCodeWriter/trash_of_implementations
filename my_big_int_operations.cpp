#include <iostream>
#include <string>
#include <algorithm>

std::string plus(std::string value_1, std::string value_2) {
  int value_1_size = value_1.size(), value_2_size = value_2.size();


  if (value_2_size > value_1_size) {
    std::string tmp = value_1;
    value_1 = value_2;
    value_2 = tmp;
    value_1_size = value_1.size();
    value_2_size = value_2.size();
  }

  //int diff = value_1_size - value_2_size;

  int sum, tmp = 0;
  std::string result;
  for (int i = value_1_size-1, k=value_2_size-1; i >= 0; i--, k--) {
    if (k >= 0)
      sum = (value_1[i]-'0'+value_2[k]-'0')+tmp;
    else
      sum = value_1[i]-'0'+tmp;
    tmp = sum / 10;
    std::cout << "TMP" << tmp << std::endl;
    result.push_back(sum%10+'0');
    std::cout << "SUM" << sum << std::endl;
  }
  if (tmp)
    result.push_back('1');
  std::reverse(result.begin(), result.end());

  return result;
}
std::string minus(std::string value_1, std::string value_2) {
  std::string result;
  return result;
}
std::string multiply(std::string value_1, std::string value_2) {
  std::string result;
  return result;
}
std::string divide(std::string value_1, std::string value_2) {
  std::string result;
  return result;
}
std::string pow(std::string value_1, std::string value_2) {
  std::string result;
  return result;
}

int main() {
  std::string result;
  result = plus("123", "123");
  std::cout << "Plus: " << result << std::endl;
  result = minus("123", "123");
  std::cout << "Minus: " << result << std::endl;
  result = multiply("123", "123");
  std::cout << "Multiply: " << result << std::endl;
  result = divide("123", "123");
  std::cout << "Divide: " << result << std::endl;
  result = pow("123", "2");
  std::cout << "Pow: " << result << std::endl;

}
