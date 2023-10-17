#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1, three = 1;
        for (int i = 2; i < n + 1; i++) {
            three = one + two;
            one = two;
            two = three;
        }
        return three;
    }
};

int main() {
    // Example input
    int n = 5;

    // Create a solution object
    Solution solution;

    // Call the climbStairs function
    int result = solution.climbStairs(n);

    // Print the output
    cout << "Distinct Ways to Climb Stairs: " << result << endl;

    return 0;
}
