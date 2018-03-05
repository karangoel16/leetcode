/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (46.88%)
 * Total Accepted:    85.1K
 * Total Submissions: 181.4K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * 
 * 
 * ⁠Example 1:
 * Input:  k = 3,  n = 7
 * Output: 
 * 
 * [[1,2,4]]
 * 
 * 
 * ⁠Example 2:
 * Input:  k = 3,  n = 9
 * Output: 
 * 
 * [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
public:
    void support(int i,int n,int k)
    {
        if(i>10)
        {
            return ;
        }
        if(n>45)
        {
            return;
        }
        if(n<=0)
        {
            if(k==temp.size())
            {
                res.push_back(temp);
                //temp.clear();
            }
            return ;
        }
        for(int j=i;j<=n;j++)
        {
            //std::cout<<"*";
            temp.push_back(j);
            support(j+1,n-j,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        temp.clear();
        support(1,n,k);
        return res;
        
    }
};
