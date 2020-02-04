#include <iostream>
#include <vector>

using std::vector;

void removeElements(vector<int> &a, const vector<bool> &use){
  for(int i = 0; i < a.size(); ++i){
    if(use[i] == true){
      a.erase(a.begin() + i);
    }
  }
}

int optimal_weight(int W, const vector<int> &w, vector<bool> &use){
  int n = w.size() + 1;
  int m = W + 1;
  vector<vector<int>> sack(n, vector<int>(m,0));
  for(size_t i = 1; i < n; ++i){
    for(size_t j = 1; j < m; ++j){
      sack[i][j] = sack[i - 1][j];
      if(w[i -1] <= j){
        int num = sack[i - 1][j - w[i - 1]] + w[i - 1];
        sack[i][j] = std::max(num, sack[i][j]);
      }
    } 
  }
  for(int i = w.size() - 1, j = n - 1, k = m - 1; i >= 0; --i ){
    if(sack[j][k] == (sack[j - 1][k - w[i]] + w[i])){
      use[i] = true;
      j = j - 1;
      k = k - w[i];
    }else{
      j -= 1;
    }
  }
  return sack[n - 1][m - 1];
}

int partition3(vector<int> &A) {
  //write your code here
  int r = 1;
  int s = 0;
  for(auto i : A){
    s += i;
  }
  if(s % 3 != 0){
    r = 0;
  }else{
    vector<bool> use(A.size());
    int w = s / 3;
    for(int i = 0; i < 3; ++i){
      int x = optimal_weight(w, A, use);
      if(x != w && i != 0){
        r = 0;
      }
      removeElements(A, use);
      use = vector<bool>(A.size());
    }
  }
  return r;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
