#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> min_S(n + 1);
  std::vector<int> parent(n + 1);
  for(size_t i = 2; i <= n; ++i){
    int p = -1;
    int min = 10000000000;
    if(i % 2 == 0){
      int m = 1 + min_S[i / 2];
      if(m < min){
        min = m;
        p = i / 2;
      }
    }
    if(i % 3 == 0){
      int m = 1 + min_S[i / 3];
      if(m < min){
        min = m;
        p = i / 3;
      }
    }
    if(i - 1 > 0){
      int m = 1 + min_S[i - 1];
      if(m < min){
        min = m;
        p = i - 1;
      }
    }
    min_S[i] = min;
    parent[i] = p;
  }
  while (n > 0) {
    sequence.push_back(n);
    n = parent[n];
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
