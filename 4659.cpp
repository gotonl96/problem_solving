#include <iostream>
#include <string>

void printResult(std::string input, bool status){
  if(status == true){
    std::cout << "<" << input << "> is acceptable.\n";
  } else {
    std::cout << "<" << input << "> is not acceptable.\n";
  }
}

bool checkVowels(std::string input){

}

bool checkConsecutive(std::string input){
  int cnt = 0;

  for(auto s : input){
    if(s == 'a' || s == 'i' || s == 'o' || s == 'e' || s == 'u'){
      cnt++;
    }



  }
}

int main(){

  while(1){
    std::string input;
    std::cin >> input;
    
    if(input == "end"){
      break;
    }

    //* check 모음
    
    //* check 연속 3개



  }

  return 0;
}