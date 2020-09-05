/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
*/





class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret,pos(26,0);
        for (auto i = 0; i < S.length(); i++)
            pos[S[i] - 'a'] = i; //record the last occurence of the char
        int max_idx = 0, last_idx = 0;
        for (auto i = 0; i < S.length(); i++) {
            max_idx = max(max_idx,pos[S[i] - 'a']); //store from the first char in the string to check the partition point.
            if (i == max_idx) {
                ret.push_back(max_idx - last_idx + 1);
                last_idx = i + 1; //find the next partition
            }
        }
        return ret;
    }
};
