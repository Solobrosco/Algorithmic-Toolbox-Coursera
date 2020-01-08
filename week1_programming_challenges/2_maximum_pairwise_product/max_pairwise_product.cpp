#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProductMax2(const std::vector<int>& numbers) {
    int n = numbers.size();

    int index1 = -1;
    for (int i = 0; i < n; ++i){
        if ((index1 == -1) || (numbers[i] > numbers[index1])){
            index1 = i;
        }
    }
    int index2 = -1;
    for (int j = 0; j < n; ++j){
        if ((j != index1) && ((index2 == -1) || (numbers[j] > numbers[index2]))){
            index2 = j;
        }
    }
    return ((long long) (numbers[index1])) * numbers[index2];
}

long long MaxPairwiseProductSort(const std::vector<int>& numbers){
    int n = numbers.size();
    std::sort(numbers.begin(), numbers.end());
    return (long long)numbers[n-1] * numbers[n-2];;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProductSort(numbers);
    std::cout << result << std::endl;
    return 0;
}
