/*
 * [327] Count of Range Sum
 *
 * https://leetcode.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (30.56%)
 * Total Accepted:    22.8K
 * Total Submissions: 74.6K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * 
 * ⁠   Given an integer array nums, return the number of range sums that lie in
 * [lower, upper] inclusive.
 * 
 * ⁠   Range sum S(i, j) is defined as the sum of the elements in nums between
 * indices i and 
 * ⁠   j (i ≤ j), inclusive.
 * 
 * 
 * 
 * ⁠   Note:
 * ⁠   A naive algorithm of O(n2) is trivial. You MUST do better than that.
 * 
 * 
 * ⁠   Example:
 * ⁠   Given nums = [-2, 5, -1], lower = -2, upper = 2,
 * ⁠   Return 3.
 * ⁠   The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums
 * are: -2, -1, 2.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long int> mst;
        mst.insert(0);
        long long int sum =0;
        int res=0;
        for(auto i:nums)
        {
            sum+=i;
            res+=std::distance(mst.lower_bound(sum-upper),mst.upper_bound(sum-lower));
            mst.insert(sum);
        }
        return res;
    }
};
