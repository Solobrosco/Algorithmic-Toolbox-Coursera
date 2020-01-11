#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_euclidian(long a, long b){
  int div = a >= b ? a : b;
  int dd = a <= b ? a : b;
  while(div != 0){
    int r = dd % div;
    dd = div;
    div = r;
  }
  return dd;
}

long long lcm_with_gcd(long long a, long long b){
  return (a * b) / gcd_euclidian(a, b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_with_gcd(a, b) << std::endl;
  return 0;
}
