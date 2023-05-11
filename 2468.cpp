#include <iostream>
#include <vector>

int n;
std::vector<std::vector<int>> height_map;
std::vector<std::vector<int>> matrix;
std::vector<std::vector<int>> visited;
int direct_x[4] = {0, 0, -1, 1};
int direct_y[4] = {-1, 1, 0, 0};
int result = 0;

void printMatrix(){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void printVisited(){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      std::cout << visited[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}


void dfs(int x, int y){
  visited[x][y] = 1;
  printVisited();

  for(int i=0; i<4; i++){
    int next_x = x + direct_x[i];
    int next_y = y + direct_y[i];

    if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n){
      if(visited[next_x][next_y] == false && matrix[next_x][next_y] == 1){
        dfs(next_x, next_y);
      }
    }
  }
}

int main(){

  std::cin >> n;
  height_map.resize(n, std::vector<int>(n, 0));

  int min = 100;
  int max = 0;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int height;
      std::cin >> height;
      min = std::min(min, height);
      max = std::max(max, height);      
      height_map[i][j] = height;
    }
  }
  
  if(min == max){
    std::cout << 1 << "\n";
    return 0;
  }

  for(int rain = min; rain < max; rain++){

    // reset  
    matrix = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    visited = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    int cnt = 0;

    // set matrix 
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        matrix[i][j] = (rain < height_map[i][j]) ? 1 : 0; 
      }
    }

    printMatrix();
    
    // get maximum safe zone
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(matrix[i][j] == 1 && visited[i][j] == false){
          dfs(i, j);
          cnt++;
        }
      }
    }

    if(result < cnt ) result = cnt;
  }


  std::cout << result;

  return 0;
}