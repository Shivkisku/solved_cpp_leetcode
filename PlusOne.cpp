#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0 && digits[i] == 9) {
            digits[i--] = 0;
        }
        if (i < 0) {
            digits.insert(digits.begin(), 1);
        } else {
            digits[i]++;
        }
        return digits;
    }
};

// Function to print the vector
void printVector(vector<int>& vec) {
    cout << "Output: ";
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // Example vector
    vector<int> digits = {1, 2, 3};

    // Create a solution object
    Solution solution;

    // Call the plusOne function
    vector<int> result = solution.plusOne(digits);

    // Print the output
    printVector(result);

    return 0;
}
