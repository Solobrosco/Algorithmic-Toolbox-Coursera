#include <iostream>

int get_change(int m) {
  //write your code here
  int value[] = {10, 5, 1};
  int k;
  for(int i = 0; m > 0; i++){
    k += m / value[i];
    m %= value[i];
  }
  return k;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
