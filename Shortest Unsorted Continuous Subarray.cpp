/* 
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector <int> ret = nums;
        sort(ret.begin(),ret.end());
        int ans = 0, start = 0, end = 0;
        int l = nums.size();
        if (ret == nums)
            return 0;
        for (int i = 0; i < l; i++) {
            if (nums[i] != ret[i]) {
                start = i;
                break;
            }
        }
        for (int j = l - 1; j > 0; j--) {
            if (nums[j] != ret[j]) {
                end = j;
                break;
            }
        }
        ans = end - start + 1;
        return ans;
    }
};
