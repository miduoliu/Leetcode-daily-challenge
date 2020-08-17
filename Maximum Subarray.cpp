/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = INT_MIN;
        int fin = 0;
        for (auto n : nums) {
            fin = fin + n;
            if (cur < fin) //Through this process, let cur become the first num in numms;
                cur = fin; //Check if the sum of cur and next num in nums is larger than cur;  
            if (fin < 0) 
                fin = 0; // Add a negative number is less that a num itself, so convert fin to 0, jump over the cur number in nums.
        }
        return cur;
    }
};
