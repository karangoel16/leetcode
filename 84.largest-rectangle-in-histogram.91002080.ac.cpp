/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (27.49%)
 * Total Accepted:    112.6K
 * Total Submissions: 409.6K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        stack<int> st;
        st.push(0);
        int res=0;
        int idx;
        for(int i=1;i<heights.size();i++)
        {
            while(heights[i]<heights[idx=st.top()])
            {
                st.pop();
                res=std::max(res,heights[idx]*(i-st.top()-1));
            }
            st.push(i);
        }
        return res;
    }
};
