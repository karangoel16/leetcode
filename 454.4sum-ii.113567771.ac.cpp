/*
 * [454] 4Sum II
 *
 * https://leetcode.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (47.75%)
 * Total Accepted:    28.6K
 * Total Submissions: 59.9K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * Given four lists A, B, C, D of integer values, compute how many tuples (i,
 * j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 * 
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤
 * N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is
 * guaranteed to be at most 231 - 1.
 * 
 * Example:
 * 
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 * 
 * 
 */
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp;
        for(auto i:A)
        {
            for(auto j:B)
            {
                mp[i+j]++;
            }
        }
        int res=0;
        for(auto i:C)
        {
            for(auto j:D)
            {
                if(mp.find(-1*(i+j))!=mp.end())
                {
                    res+=mp[-1*(i+j)];
                }
            }
        }
        return res;
    }
};
