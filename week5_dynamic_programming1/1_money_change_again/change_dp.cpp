#include <iostream>
#include <vector>

int get_change(int m) {
  int sizeValue = 3;
  //write your code here
  std::vector<int> change(m + 1);
  std::vector<int> value = {1, 3, 4};
  for(size_t i = 1; i <= m; ++i){
    int min = 1000000000;
    for(size_t j = 0; j < sizeValue; ++j){
      if(i >= value[j]){
        int coin = 1 + change[i - value[j]];
        if(coin < min){
          min = coin;
        }
      }
    }
    change[i] = min;
  }
  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
