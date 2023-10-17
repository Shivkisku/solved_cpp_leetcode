#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n(gas.size()), sum(0), total(0), res(0);
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                res = i + 1;
                sum = 0;
            }
            total += gas[i] - cost[i];
        }
        return total >= 0 ? res : -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int result = sol.canCompleteCircuit(gas, cost);
    cout << "Output: " << result << endl;
    return 0;
}
