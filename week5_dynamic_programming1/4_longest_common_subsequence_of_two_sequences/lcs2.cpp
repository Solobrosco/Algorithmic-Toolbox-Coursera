#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int n_1 = a.size() + 1;
  int n_2 = b.size() + 1;
  std::vector<std::vector<int>> lcs2(n_1, std::vector<int>(n_2,0));
  for(size_t i = 1; i < n_1; ++i){
    for(size_t j = 1; j < n_2; ++j){
      int ins = 1 + lcs2[i - 1][j];
      int del = 1 + lcs2[i][j - 1];
      int match = lcs2[i - 1][j - 1];
      if(a[i - 1] != b[j - 1]){
        match += 1;
      }
      lcs2[i][j] = std::min(match, std::min(ins, del));
    }  
  }
  return lcs2[n_1 - 1][n_2 - 1];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
