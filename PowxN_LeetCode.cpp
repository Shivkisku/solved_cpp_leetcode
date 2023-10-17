#include <iostream>
#include <climits>

using namespace std;

// Iterative
class Solution1 {
public:
    double myPow(double x, int n) {
        if (x == 1) return x;
        if (x == -1) return n % 2 ? -1 : 1;
        if (x < 1 && (n == INT_MAX || n == INT_MIN)) return 0;
        double res = 1;
        if (n < 0) x = 1/x, n = -n;
        while (n > 0) {
            res = res * x;
            n--;
        }
        return res;
    }
};

// Recursive
class Solution2 {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        if (x == -1) return n % 2 ? -1 : 1;
        if (n == INT_MIN) return 0;
        if (n == 0) return 1;
        if (n < 0) return 1 / myPow(x, -n);
        if (n % 2) return x * myPow(x, n - 1);
        else {
            double d = myPow(x, n / 2);
            return d * d;
        }
    }
};

// More concise recursive solution
class Solution3 {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double t = myPow(x, n / 2);
        if (n % 2) return n < 0 ? 1 / x * t * t : x * t * t;
        else return t * t;
    }
};

int main() {
    Solution1 sol1;
    double x1 = 2.00000;
    int n1 = 10;
    cout << "Output using iterative solution: " << sol1.myPow(x1, n1) << endl;

    Solution2 sol2;
    double x2 = 2.10000;
    int n2 = 3;
    cout << "Output using recursive solution: " << sol2.myPow(x2, n2) << endl;

    Solution3 sol3;
    double x3 = 2.00000;
    int n3 = -2;
    cout << "Output using concise recursive solution: " << sol3.myPow(x3, n3) << endl;

    return 0;
}
