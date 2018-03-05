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
        if(!heights.size())
            return 0;
        stack<int> st;
        int maxArea=0,i=0;
        for(;i<heights.size();i++){
            int area=0,top;
            while(!st.empty() && heights[st.top()]>heights[i]){
                top=st.top();
                st.pop();
                if(st.empty())
                {
                    area=heights[top]*i;
                }
                else{
                    area=heights[top]*(i-st.top()-1);
                }
                //std::cout<<area<<endl;
                maxArea=std::max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int top=st.top(),area=0;
            st.pop();
            if(st.empty())
            {
                area=heights[top]*i;
            }
            else{
                area=heights[top]*(i-st.top()-1);
            }
            maxArea=std::max(maxArea,area);
        }
        return maxArea;
    }
};
