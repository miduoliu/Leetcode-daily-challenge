/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector <int> ret;
        int z_count = 0;
        for (auto n : nums) {
            if (n != 0)
                ret.push_back(n);
            else
                z_count++;
        }
        while (z_count) {
            ret.push_back(0);
            z_count--;
        }
        nums = ret;
    }
};
