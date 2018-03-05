/*
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (34.11%)
 * Total Accepted:    84.5K
 * Total Submissions: 247.7K
 * Testcase Example:  '[]\n0'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 * 
 * Note: 
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for
 * non-empty array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();// remove the maxiumum element
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();//to remove the lowest elements which are not needed
            }
            dq.push_back(i);//this is to push the elements in stack
            if(i>=k-1)
            {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
