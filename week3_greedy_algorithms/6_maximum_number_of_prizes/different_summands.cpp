#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int num = n;
  for(int i = 1; i <= n; i++){
    int res = num - i;
    if(res == 0){
      summands.push_back(i);
      break;
    }else{
      if(res - (i + 1) >= 0){
        summands.push_back(i);
        num = res;
      }
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
