/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (48.08%)
 * Total Accepted:    122.7K
 * Total Submissions: 255.3K
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * 
 * Note:
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> st{nums1.begin(),nums1.end()};
        for(auto i:nums2)
        {
            if(st.find(i)!=st.end())
            {
                res.push_back(i);
                st.erase(i);
            }
        }
        return res;
    }
};
