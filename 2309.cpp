
#include <algorithm>
#include <array>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::array<unsigned short, 9> heights;
  unsigned short sum = 0;
  // input data
  for (auto &height : heights) {
    std::cin >> height;
    sum += height;
  }

  // sorting asending
  std::sort(heights.begin(), heights.end());

  // find nanjangee
  for (int i = 0; i < heights.size() - 1; i++) {
    for (int j = i + 1; j < heights.size(); j++) {
      if (sum - heights[i] - heights[j] == 100) {
        for (int k = 0; k < heights.size(); k++) {
          if (k == i || k == j) continue;
          std::cout << heights[k] << ' ';
        }
      }
    }
  }

  return 0;
}