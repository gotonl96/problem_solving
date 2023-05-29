#include <iostream>
#include <algorithm>
#include <vector>

int main(){

  //* input variable
  int n, m;
  std::cin >> n >> m;

  //* input variable
  int j;
  std::cin >> j;

  //* input variable
  std::vector<int> apple_locations;
  for(int i=0; i<j; i++){
    int input;
    std::cin >> input;
    apple_locations.push_back(input);
  }

  //* solve problem
  int result = 0;
  int box_location = 1;
  int size = m;

  for(auto apple_location : apple_locations){
    if(apple_location < box_location){
      result += box_location - apple_location;
      box_location = box_location - (box_location - apple_location);
    } 
    else if( box_location <= apple_location && apple_location <= (box_location + size - 1)){
      continue;
    }
    else {
      result += apple_location - (box_location + size -1);
      box_location = box_location + apple_location - (box_location + size -1);
    }
  }

  std::cout << result;

  return 0;
}