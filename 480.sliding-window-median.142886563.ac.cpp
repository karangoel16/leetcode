/*
 * [480] Sliding Window Median
 *
 * https://leetcode.com/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (30.70%)
 * Total Accepted:    12.4K
 * Total Submissions: 40.3K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5 
 * 
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Your job is to output the median array for each window in the
 * original array.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * 
 * Window position                Median
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 * ⁠1 [3  -1  -3] 5  3  6  7       -1
 * ⁠1  3 [-1  -3  5] 3  6  7       -1
 * ⁠1  3  -1 [-3  5  3] 6  7       3
 * ⁠1  3  -1  -3 [5  3  6] 7       5
 * ⁠1  3  -1  -3  5 [3  6  7]      6
 * 
 * 
 * Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 * 
 * Note: 
 * You may assume k is always valid, ie: k is always smaller than input array's
 * size for non-empty array.
 */

class Solution {
    multiset<int> data;
public:
    double GetMedian(int k)
    {
        if (data.empty())
            return 0;
        //const size_t n = data.size();
        double median = 0;
        auto iter = data.cbegin();
        std::advance(iter, k / 2);
        if (k % 2 == 0)
        {
            const auto iter2 = iter--;
            median = (double(*iter) + double(*iter2)) / 2;
        }
        else
            median = *iter;
        return median;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        if(!nums.size())
            return {};
        for(;i<k;i++)
            data.insert(nums[i]);
        vector<double> res;
        for(;i<nums.size();i++)
        {
            res.push_back(GetMedian(k));
            data.erase(data.lower_bound(nums[i-k]));
            data.insert(nums[i]);
            //for(auto i:data)
            //    std::cout<<i<<"\t";
            //std::cout<<endl;
        }
        res.push_back(GetMedian(k));
        return res;
        
    }
};
