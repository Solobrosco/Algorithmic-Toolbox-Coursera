#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int get_fibonacci_last_digit_fast(long long n){
    if(n <= 1){
        return n;
    }
    int a = 0, b = 1;
    for(int i = 0; i < n - 1; ++i){
        int temp = b % 10;
        b = a % 10;
        a = temp + a % 10;
    }
    return a % 10;
}

int fibonacci_sum_fast(long long n){
    int x = (n + 2) % 60;
    int x_end = get_fibonacci_last_digit_fast(x);
    if(x_end == 0){
        return 9;
    }else{
        return x_end - 1;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
