/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.
 

Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false´
Explanation: No possible partition.
*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map <int,int> hm;
        int mincom = INT_MAX;
        for (auto n : deck)
            hm[n]++;
        for (auto n : hm)
            if (n.second < mincom)
                mincom = n.second;
        if (mincom < 2) return false;
        for (int i = 2; i <= mincom; i++) {
            bool okay = true;
            for (auto n : hm) {
                if (n.second % i != 0) {
                    okay = false;
                    break;
                }
            }
            if (okay) return true;
        }
        return false;
    }
};
