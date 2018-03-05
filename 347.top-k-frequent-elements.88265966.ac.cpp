/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (49.52%)
 * Total Accepted:    95.6K
 * Total Submissions: 193K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * 
 * Note: 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mul;
        for(auto i:nums)
        {
            mul[i]++;
        }
        vector<vector<int>> bucket(nums.size()+1,vector<int>());
        for(auto i:mul)
        {
            bucket[i.second].push_back(i.first);
        }
        vector<int> res;
        for(int i=nums.size();i>=0&&res.size()<k;i--)
        {
            if(bucket[i].size()!=0)
            {
                std::copy(bucket[i].begin(),bucket[i].end(),back_inserter(res));
            }
        }
        return res;
    }
};
