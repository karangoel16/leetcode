/*
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (53.03%)
 * Total Accepted:    9.7K
 * Total Submissions: 18.3K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures, produce a list that, for each day in the
 * input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73],
 * your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        if(!temperatures.size())
            return temperatures;
        stack<int> st;
        for(int i=0;i<temperatures.size();i++){
                while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                    int idx=st.top();
                    res[idx]=i-st.top();
                    st.pop();
                }
                st.push(i);
        }
        return res;
    }
};
