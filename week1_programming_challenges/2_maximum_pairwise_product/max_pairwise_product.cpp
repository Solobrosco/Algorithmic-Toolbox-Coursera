#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();
    int maxNum1 = 0;
    int maxNum2 = 0;
	if(n >= 2){
        // find 2 largest numbers and multiply them
        for(int i = 0; i < n; i++){
            if(numbers[i] > maxNum1){
                maxNum1 = numbers[i];    
            }
        }
        for(int i = 0; i < n; i++){
            if(numbers[i] > maxNum2){
                if(numbers[i] == maxNum1){
                    continue;
                }
                maxNum2 = numbers[i];
            }
        }
	}else{
        std::cout << "No Pairs" << std::endl;
        return 1;
    }
    return (long long)maxNum1 * maxNum2 ;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    std::cout << result << std::endl;
    return 0;
}
