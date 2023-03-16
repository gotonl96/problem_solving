#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  
  int n, k;
  std::cin >> n >> k;

  std::vector<int> array;
  for(int i=0; i<n; i++){
    int input;
    std::cin >> input;
    array.push_back(input);
  }

  std::vector<int> prefix_sum_list = {0};
  int sum = 0;

  for(auto item : array){
    sum += item;
    prefix_sum_list.push_back(sum);
  }

  int result = -9999999;
  for(int i=0; i <= n-k; i++){
    if( prefix_sum_list.at(k+i) - prefix_sum_list.at(i) > result) {
      result = prefix_sum_list.at(k+i) - prefix_sum_list.at(i);
    }
  }   

  std::cout << result;

  return 0;
}