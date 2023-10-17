#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, minLeft = 0, minRight = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            if(height[i] < minRight) continue;
            minLeft = 0;
            for(int j = 0; j < i; j++){
                if(height[j] < minLeft) continue;
                maxArea = max(maxArea, min(height[i], height[j]) * (i - j));
                minLeft = max(minLeft, height[j]);
            }
            minRight = max(minRight, height[i]);
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8,3,7}; // Input vector
    int result = solution.maxArea(height); // Call the function

    // Print the output
    cout << "Output: " << result << endl;

    return 0;
}
