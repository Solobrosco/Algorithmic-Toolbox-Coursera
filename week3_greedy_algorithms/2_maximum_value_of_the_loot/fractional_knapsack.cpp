#include <iostream>
#include <vector>

using std::vector;

void my_Sort(vector<double> &b, vector<int> &v, vector<int> &w){
  for(int i = 0; i < b.size(); i++){
    int max = i;
    for(int j = i+1; j < b.size(); j++){
      if(b[j] > b[max]){
        max = j;
      }
    }
    if(max != i){
      std::iter_swap(b.begin()+i, b.begin()+max);
      std::iter_swap(v.begin()+i, v.begin()+max);
      std::iter_swap(w.begin()+i, w.begin()+max);
    }
  } 
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  int n = weights.size();
  vector<double> ben(n);
  for(int i = 0; i < n; i++){
    ben[i] = (values[i]/ (double)weights[i]);
  }
  my_Sort(ben,values,weights);
  for(int i = 0; i < n; i++){
    int seen = std::min(capacity,weights[i]);
    int res = capacity - seen;
    if(res >= 0){
      capacity = res;
      value += ben[i] * seen;
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
