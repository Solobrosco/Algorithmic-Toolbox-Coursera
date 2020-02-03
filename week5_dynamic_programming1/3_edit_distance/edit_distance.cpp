#include <iostream>
#include <string>
#include <vector>

using std::string;


int edit_distance(const string &str1, const string &str2){
  int n_1 = str1.length() + 1;
  int n_2 = str2.length() + 1;
  //write your code here
  std::vector<std::vector<int>> edit_distance(n_1, std::vector<int>(n_2,0));
  for(size_t i = 0; i < n_1; ++i){
    edit_distance[i][0] = i;
  }
  for(size_t i = 0; i < n_2; ++i){
    edit_distance[0][i] = i;
  }
  for(size_t i = 1; i < n_1; ++i){
    for(size_t j = 1; j < n_2; ++j){
      int ins = 1 + edit_distance[i - 1][j];
      int del = 1 + edit_distance[i][j - 1];
      int match = edit_distance[i - 1][j - 1];
      if(str1[i - 1] != str2[j - 1]){
        match += 1;
      }
      edit_distance[i][j] = std::min(match, std::min(ins, del));
    }  
  }
  return edit_distance[n_1 - 1][n_2 - 1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
