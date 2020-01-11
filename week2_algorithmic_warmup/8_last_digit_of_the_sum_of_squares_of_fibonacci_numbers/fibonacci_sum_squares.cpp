#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int get_fibonacci_last_digit_fast(long long n){
    if(n <= 1){
        return n;
    }
    int b = 0, a = 1;
    for(int i = 0; i < n - 1; ++i){
        int temp = b % 10;
        b = a % 10;
        a = temp + a % 10; 
    } 
    return a % 10;
}

int fibonacci_sum_squares_fast(long long n){
    int last;
    if(n <= 1){
        return n;
    }
    long long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    long long sum = (fib[0] * fib[0]) + (fib[1] * fib[1]);
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        sum += (fib[i] * fib[i]);
    }
    last = get_fibonacci_last_digit_fast(sum);
    return last;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
