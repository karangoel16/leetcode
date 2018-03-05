/*
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (18.81%)
 * Total Accepted:    65K
 * Total Submissions: 345.5K
 * Testcase Example:  '[]\n0\n0'
 *
 * 
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 * 
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> mul;
        for(int i=0;i<nums.size();i++)
        {
            if(i>k)
            {
                mul.erase(nums[i-k-1]);
            }
            auto g=mul.lower_bound(nums[i]-t);
            //std::cout<<i<<" "<<abs(*g-nums[i])<<" "<<t<<"\n";
            if(g!=mul.end() && abs(*g-nums[i])<=t)
            {
                return true;
            }
            mul.insert(nums[i]);
        }
        return false;
    }
};
