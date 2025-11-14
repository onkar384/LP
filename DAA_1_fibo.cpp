
#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int i, n, t1 = 0, t2 = 1, nT;

    cout << "Fibonacci Series in C++ Without Using Recursion";
    cout << "\nEnter any number: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    for (i = 1; i <= n; ++i) {
        cout << t1 << " ";
        nT = t1 + t2;
        t1 = t2;
        t2 = nT;
    }

    cout << "\n\nFibonacci Series in C++ Using Recursion";
    cout << "\nEnter any number: ";
    int p;
    cin >> p;

    cout << "Fibonacci number at position " << p << " is: " << fibonacci(p);

    return 0;
}

