#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long period_length(long long m){
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

long long get_fibonacci_huge_fast(long long n, long long m){
    long long r = n % period_length(m);
    long long f1 = 0;
    long long f2 = 1;
    long long f = r;
    for(int i = 1; i < r; i++){
        f = (f1 + f2) % m;
        f1 = f2;
        f2 = f;
    }
    return f % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
