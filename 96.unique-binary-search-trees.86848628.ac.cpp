/*
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (41.81%)
 * Total Accepted:    144.4K
 * Total Submissions: 345.4K
 * Testcase Example:  '1'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1...n?
 * 
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
int helper(int val,vector<int> &dp)
{
    int sum=0;
    for(int i=1;i<=val;i++)
    {
        sum+=dp[i-1]*dp[val-i];
    }
    dp[val]=sum;
    //std::cout<<val<<" "<<dp[val]<<"\n";
    return 0;
}
class Solution {
public:
    int numTrees(int n) {
        vector<int> temp(n+1,0);
        temp[0]=1;
        for(int i=1;i<=n;i++)
        {
            helper(i,temp);
        }
        return temp[n];
    }
};
