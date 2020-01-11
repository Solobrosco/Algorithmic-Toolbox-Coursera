#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long fibonacci_fast(long long n) {
    // write your code here
    if(n <= 1){
        return n;
    }
    long long f1, f2, ans;
    f1 = 0;
    f2 = 1;
    for(int i = 2; i <= n; i++){
        ans = f1 + f2;
        f1 = f2;
        f2 = ans;
    }
    return ans;
}

int period_length(long long m){
    long long f1 = 0;
    long long f2 = 1;
    long long f = f1 + f2;
    for(int i = 0; i < m * m; i++){
        f = (f1 + f2) % m;
        f1 = f2;
        f2 = f;
        if(f1 == 0 && f2 == 1){
            return i + 1;
        }
    }
}

int get_fibonacci_huge_fast(long long n, long long m){
    long long r = n % period_length(m);
    return fibonacci_fast(r) % m;
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

long long get_fibonacci_partial_sum_fast(long long from, long long to){
    long long from_end;
    long long to_end;
    if(from == to){
        return get_fibonacci_last_digit_fast(from % 60);
    }else {
        from = from % 60;
        to = to % 60;
        from_end = get_fibonacci_huge_fast(from + 1, 10) - 1;
        to_end = get_fibonacci_huge_fast(to + 2, 10) - 1;
    }
    return (to_end - from_end) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
