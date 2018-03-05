/*
 * [532] K-diff Pairs in an Array
 *
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Easy (28.17%)
 * Total Accepted:    33.8K
 * Total Submissions: 119.9K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 * 
 * Given an array of integers and an integer k, you need to find the number of
 * unique k-diff pairs in the array. Here a k-diff pair is defined as an
 * integer pair (i, j), where i and j are both numbers in the array and their
 * absolute difference is k.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [3, 1, 4, 1, 5], k = 2
 * Output: 2
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3,
 * 5).Although we have two 1s in the input, we should only return the number of
 * unique pairs.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:[1, 2, 3, 4, 5], k = 1
 * Output: 4
 * Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3,
 * 4) and (4, 5).
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [1, 3, 1, 5, 4], k = 0
 * Output: 1
 * Explanation: There is one 0-diff pair in the array, (1, 1).
 * 
 * 
 * 
 * Note:
 * 
 * The pairs (i, j) and (j, i) count as the same pair.
 * The length of the array won't exceed 10,000.
 * All the integers in the given input belong to the range: [-1e7, 1e7].
 * 
 * 
 */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        int i=0,j=0;
        unordered_set<string>st;
        while(i<nums.size())
        {
            if(i==j)
            {
                i++;
                continue;
            }
            if(nums[i]-nums[j]>k)
            {
                j++;
            }
            else if(nums[i]-nums[j]<k)
            {
                i++;
            }
            else if(nums[i]-nums[j]==k)
            {
                st.insert(to_string(nums[i])+"|"+to_string(nums[j]));
                i++;
                j++;
            }
            //std::cout<<i<<" "<<j<<"\n";
        }
        return st.size();
    }
};
