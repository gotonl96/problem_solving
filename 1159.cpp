#include <algorithm>
#include <iostream>
#include <map>
#include <string>

int main() {
  int people_cnt;
  std::cin >> people_cnt;

  std::map<char, int> first_name_table;
  for (int i = 0; i < people_cnt; i++) {
    std::string name;
    std::cin >> name;

    first_name_table[name.front()]++;
  }

  std::string name_list;
  for (auto iter : first_name_table) {
    if (iter.second >= 5) {
      name_list += iter.first;
    }
  }

  if (name_list.empty()) {
    std::cout << "PREDAJA";
  } else {
    std::sort(name_list.begin(), name_list.end());
    std::cout << name_list << std::endl;  
  }

  return 0;
}