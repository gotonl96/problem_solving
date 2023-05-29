#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>

bool compare(const std::pair<int, int> a, const std::pair<int, int> b){
  if(a.second > b.second) {
    return true;
  } else if(a.second == b.second){
    return (a.first < b.first);
  } else {
    return false;
  }  
}

int main(){

  //* input variable
  int n, c;
  std::cin >> n >> c;

  // * input_variable
  std::map<int, int> num_cnt;
  std::map<int, int> num_order;

  for(int i=0; i<n; i++){
    int input;
    std::cin >> input;
    
    if(num_cnt.find(input) == num_cnt.end()) num_cnt[input] = 1;
    else num_cnt[input] = num_cnt[input] + 1;

    if(num_order.find(input) == num_order.end()) num_order[input] = i;
  }

  // 첫번째로 빈도가 높은 순서를 찾고,
  // 두번째로 순서가 빠른 순서를 찾으면 될거라고 생각했음.
  // 최댓값을 찾으면 되는 문제처럼 풀었음
  // 최대값 찾을때 모든값을 계속 확인할 것이기 때문에 최댓값이라고 찾은것들은 아예 초기화 시켜버렸음

  std::vector<int> answer_list;
  std::map<int, int> num_cnt_copy = num_cnt;
  for(auto num1 : num_cnt){
    int max = num1.first;
    for(auto num2 : num_cnt){
      if(num2.second > num_cnt[max]) max = num2.first;
      if(num2.second == num_cnt[max]) max = (num_order[num2.first] < num_order[max]) ? num2.first : max;
    }
    num_cnt[max] = 0;
    answer_list.push_back(max);
  }

  for(auto item : answer_list){
    for(int i=0; i<num_cnt_copy[item]; i++){
      std::cout << item << " ";
    }
  }


}