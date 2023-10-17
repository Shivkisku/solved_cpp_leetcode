#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return x;
        }
        int lo = 1, hi = x;
        while (true) {
            int mid = lo + (hi - lo) / 2;
            if (mid > x / mid) {
                hi = mid - 1;
            } else if (mid + 1 > x / (mid + 1)) {
                return mid;
            } else {
                lo = mid + 1;
            }
        }
    }
};

int main() {
    // Example input
    int x = 8;

    // Create a solution object
    Solution solution;

    // Call the mySqrt function
    int result = solution.mySqrt(x);

    // Print the output
    cout << "Square Root: " << result << endl;

    return 0;
}
