#include <iostream>
#include <string>
#include <vector>
#include <queue>

std::vector<std::vector<int>> visited;
std::vector<std::string> matrix;

int direct_y[4] {0, 0, 1, -1} ;
int direct_x[4] {1, -1, 0, 0} ;
int cnt = 0;
int n, m;

struct Location {
  int y;
  int x; 

  Location(int _y, int _x) { y = _y; x = _x;  }
};


void bfs(Location u){
  std::queue<Location> q;
  q.push(u);
  visited[u.y][u.x] = true;

  while(!q.empty()){
    Location now = q.front(); q.pop();
    
    for(int i=0; i<4; i++){
      int v_x = now.x + direct_x[i];
      int v_y = now.y + direct_y[i];

      if((v_x >= 0 && v_x < m) && (v_y >= 0 && v_y < n)){
        if((visited[v_y][v_x] == 0) && (matrix[v_y][v_x] == '1')){
          visited[v_y][v_x] = visited[now.y][now.x] + 1;
          q.push(Location(v_y, v_x));
        }
      }
    }

  }
}

int main(){

  std::cin >> n >> m;

  visited.resize(n, std::vector<int>(m, 0));
  
  //* data input
  for(int i=0; i<n; i++){
    std::string input;
    std::cin >> input;
    matrix.push_back(input);
  }

  //* bfs
  bfs(Location(0, 0));

  //* result
  std::cout << visited[n-1][m-1];

  return 0;
}