/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (38.00%)
 * Total Accepted:    140K
 * Total Submissions: 368.4K
 * Testcase Example:  '0'
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * 
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * 
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        temp.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> test=temp;
            temp.clear();
            temp.push_back(1);
            for(int j=1;j<i;j++)
            {
                temp.push_back(test[j]+test[j-1]);
            }
            temp.push_back(1);
        }
        return temp;
    }
};
