/*
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (31.54%)
 * Total Accepted:    12.8K
 * Total Submissions: 40.7K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * 
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 * 
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size=nums.size();
        if(!size)
            return size;
        vector<pair<int,int>> res;
        vector<int> dp(size,1);
        vector<int> count(size,1);
        for(int i=0;i<nums.size();i++){
            res.push_back({nums[i],i});
        }
        std::sort(res.begin(),res.end());
        for(int i=1;i<size;i++)
            for(int j=i-1;j>=0;j--){
            {
                if(res[j].first<res[i].first && res[j].second<res[i].second)
                {
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                }
            }
        }
        int max=*max_element(dp.begin(),dp.end());
        int result=0;
        for(int i=0;i<size;i++){
            if(max==dp[i])
                result+=count[i];
        }
        return result;
    }
};
