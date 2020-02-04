#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size() + 1;
  int m = W + 1;
  vector<vector<int>> sack(n, vector<int>(m,0));
  for(size_t i = 1; i < n; ++i){
    for(size_t j = 1; j < m; ++j){
      sack[i][j] = sack[i - 1][j];
      if(w[i - 1] <= j){
        int num = sack[i - 1][j - w[i - 1]] + w[i - 1];
        sack[i][j] = std::max(num, sack[i][j]);
      }
    }
  }
  return sack[n -1][m - 1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
