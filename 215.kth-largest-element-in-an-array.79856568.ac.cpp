/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (40.45%)
 * Total Accepted:    193.9K
 * Total Submissions: 479.4K
 * Testcase Example:  '[1]\n1'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int,vector<int>,std::less<int>> p;
        //std::set<int> p_check;
        //std::pair<std::set<int>::iterator,bool> ret;
        for(auto i:nums)
        {
            //ret=p_check.insert(i);
            //if(ret.second==true)
            //{
                p.push(i);
            //}
        }
        int i=1;
        while(i<k)
        {
            p.pop();
            i++;
        }
        return p.top();
    }
};
