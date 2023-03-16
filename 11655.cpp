#include <iostream>
#include <string>

int main(){

  std::string input;
  getline(std::cin, input);

  for(auto &item : input){

    int alphabet_idx = static_cast<int>(item);
    if(alphabet_idx >= 'A' && alphabet_idx <= 'Z'){
      int rot13_alphabet_idx = static_cast<int>('A') + (alphabet_idx - static_cast<int>('A') + 13 ) % 26;
      item = static_cast<char>(rot13_alphabet_idx);
    } else if(alphabet_idx >= 'a' && alphabet_idx <= 'z'){
      int rot13_alphabet_idx = static_cast<int>('a') + (alphabet_idx - static_cast<int>('a') + 13 ) % 26;
      item = static_cast<char>(rot13_alphabet_idx);
    }
  }

  std::cout << input << std::endl;

  return 0;
}