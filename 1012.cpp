#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> matrix;
std::vector<std::vector<int>> visited;

int testcase, n, m, size;
int direct_x[4] = {0, 0, -1, 1};
int direct_y[4] = {-1, 1, 0, 0};
int cnt;

struct Location{
  int x;
  int y;
};

void bfs(Location location){

  std::queue<Location> q;
  q.push(location);
  visited[location.x][location.y] = 1;

  while(q.empty() == false){
    auto curr_location = q.front();
    q.pop();
 
    for(int i=0; i<4; i++){
      Location next_location;
      next_location.x = curr_location.x + direct_x[i];
      next_location.y = curr_location.y + direct_y[i];

      if(next_location.x >= 0 && next_location.x < n && next_location.y >= 0 && next_location.y < m){
        if(matrix[next_location.x][next_location.y] == 1 && visited[next_location.x][next_location.y] == false){
          visited[next_location.x][next_location.y]++;
          q.push(next_location);
        }
      }
    }
  }

}

int main(){

  std::cin >>  testcase;

  while(testcase-- > 0){
    std::cin >> m >> n >> size;
    matrix = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
    visited = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
    cnt = 0;

    for(int i=0; i<size; i++){
      int x, y;
      std::cin >> x >> y;
      matrix[y][x] = 1;
    }

    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        Location curr;
        curr.x = j;
        curr.y = i;
        if(visited[j][i] == 0 && matrix[j][i] == 1){
          bfs(curr);
          cnt++;
        }
      }
    }

    std::cout << cnt << "\n";
  }

  return 0;
}