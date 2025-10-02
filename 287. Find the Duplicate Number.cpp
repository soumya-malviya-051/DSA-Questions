#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        // Phase 1: Detect cycle
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        // Phase 2: Find entrance of cycle (duplicate number)
        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) break;
        }

        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2}; // Example input
    cout << "Duplicate number: " << sol.findDuplicate(nums) << endl;
    return 0;
}
