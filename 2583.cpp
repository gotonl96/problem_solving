#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int m, n, k;
std::vector<std::vector<int>> matrix;
std::vector<std::vector<int>> visited;
int direct_x[4] = {0, 0,-1, 1};
int direct_y[4] = {1, -1, 0, 0};
std::vector<int> results;

void printMatrix(std::vector<std::vector<int>> p){
  for(int i=0; i<p.size(); i++){
    for(int j=0; j<p[i].size(); j++){
      std::cout << p[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n\n";
}

void bfs(int x, int y){

  int cnt = 1;

  visited[x][y] = cnt;
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(x, y));

  while(!q.empty()){
    auto location = q.front();
    q.pop();
    // printMatrix(matrix);
    // printMatrix(visited);
    
    for(int i=0; i<4; i++){
      int new_x = location.first + direct_x[i];
      int new_y = location.second + direct_y[i];

      if(new_x >= 0 && new_x <m && new_y >= 0 && new_y < n){
        if(matrix[new_x][new_y] == 0 && visited[new_x][new_y] == false){
          q.push(std::make_pair(new_x, new_y));
          visited[new_x][new_y] = ++cnt;
        }
      }
    }
  }

  results.push_back(cnt);
}

int main(){

  std::cin >> m >> n >> k;

  // resize
  matrix.resize(m, std::vector<int>(n, 0));
  visited.resize(m, std::vector<int>(n, 0));

  // set matrix
  for(int i=0; i<k; i++){
    int row_left_x, row_left_y, high_right_x, high_right_y;
    std::cin >> row_left_x >> row_left_y >> high_right_x >> high_right_y;

    for(int x=row_left_x; x<high_right_x; x++){
      for(int y=row_left_y; y<high_right_y; y++){
        matrix[y][x] = 1;
      }
    }
  }
  // printMatrix(matrix);

  // bfs
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(matrix[i][j] == 0 && visited[i][j] == false)
        bfs(i, j);
    }
  }

  // result
  std::sort(results.begin(), results.end());
  std::cout << results.size() << "\n";
  for(auto result : results){
    std::cout << result << " ";
  }

  return 0;
}