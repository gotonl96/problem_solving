
#include <iostream>
#include <array>

int main(){

  int fee_a, fee_b, fee_c;
  std::cin >> fee_a >> fee_b >> fee_c;

  std::array<int, 101> time_table = {};

  for(int i=0; i <3; i++){
    int start_time;
    int end_time;

    std::cin >> start_time >> end_time;

    for(int j=start_time; j < end_time; j++){
      time_table[j]++;
    }
  }

  int result = 0;
  for(int i=0; i < time_table.size(); i++){
    if(time_table[i] == 1){
      result += 1 * fee_a;
    }

    if(time_table[i] == 2){
      result += 2 * fee_b;
    }

    if(time_table[i] == 3){
      result += 3 * fee_c;
    }
  }

  std::cout << result << std::endl;

  return 0;
}