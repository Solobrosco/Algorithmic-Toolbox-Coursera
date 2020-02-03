#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int ave, int right) {
  long long number_of_inversions = 0;
  size_t i = left, j = ave, k = left;
  while(i <= ave - 1 && j <= right){
    if(a[i] <= a[j]){
      b[k] = a[i];
      i++;
    }else{
      b[k] =a[j];
      number_of_inversions += ave - i;
      j++;
    }
    k++;
  }
  while(i <= ave - 1){
    b[k] = a[i];
    i++;
    k++;
  }
  while(j <= right){
    b[k] = a[j];
    j++;
    k++;
  }
  for(int left; i <= right; i++){
    a[i] = b[i];
  }
  return number_of_inversions;
}

long long merge_Sort(vector<int> &a, vector<int> &b, int L, int R){
  long long count = 0;
  if(R <= L){
    return count;
  }
  int a = L + (R - L) / 2;
  count += merge_Sort(a, b, L, a);
  count += merge_Sort(a, b, a + 1, R);
  count += get_number_of_inversions(a, b, L, a + 1, R);
  return count;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << merge_Sort(a, b, 0, a.size() - 1) << '\n';
}
