/*
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (42.17%)
 * Total Accepted:    27.2K
 * Total Submissions: 64.4K
 * Testcase Example:  '13'
 *
 * 
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * 
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * 
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
class Solution {
public:
    void helper(int start,int end,int &n, vector<int> &num){
        for(int i=start;i<=end && i<=n;i++){
            num.push_back(i);
            helper(i*10,i*10+9,n,num);
        }
    
    }
    vector<int> lexicalOrder(int n) {
        vector<int> nums;
        helper(1,9,n,nums);
        return nums;
    }
};
