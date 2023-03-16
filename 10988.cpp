#include <iostream>
#include <algorithm>
#include <string>

int main(){

  std::string input;
  std::cin >> input;

  std::string reverse_input = input;
  std::reverse(reverse_input.begin(), reverse_input.end());

  if(input == reverse_input){
    std::cout << "1";
  } else {
    std::cout << "0";
  }

  return 0;
}