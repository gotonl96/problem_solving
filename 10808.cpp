#include <iostream>
#include <string>
#include <array>

int main(){

  std::string input;
  std::cin >> input;

  std::array<int, 26> alphabet = {};
  for(auto item : input){
    alphabet.at(static_cast<int>(item) - 97)++;
  }

  for(auto item : alphabet){
    std::cout << item << ' ';
  }

  return 0;
}