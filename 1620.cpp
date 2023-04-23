#include <iostream>
#include <string>
#include <unordered_map>

int main(){

  int n, m;
  std::cin >> n >> m;

  std::unordered_map<int, std::string> pokemon_map;

  for(int i=0; i<n; i++){
    std::string input;
    std::cin >> input;
    pokemon_map[i+1] = input;
  }

  for(int i=0; i<m; i++){
    std::string input;
    std::cin >> input;
    
    if(pokemon_map.find(std::stoi(input)) != pokemon_map.end()){
      std::cout << pokemon_map[std::stoi(input)] << "\n";
    } else {
      for(auto item : pokemon_map){
        if(item.second == input){
          std::cout << item.first << "\n";
          break;
        }
      }
    }
  }

  return 0;
}