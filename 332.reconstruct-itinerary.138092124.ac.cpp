/*
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (29.81%)
 * Total Accepted:    45.7K
 * Total Submissions: 153.4K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 * 
 * 
 * Note:
 * 
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * 
 * 
 * 
 * 
 * ⁠   Example 1:
 * ⁠   tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR",
 * "SFO"]]
 * ⁠   Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 * 
 * 
 * ⁠   Example 2:
 * ⁠   tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * ⁠   Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 * ⁠   Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        if(!tickets.size())
            return res;
        unordered_map<string,list<string>> mp;
        for(auto ticket:tickets)
            mp[ticket.first].push_back(ticket.second);
        for(auto it=mp.begin();it!=mp.end();it++)
            it->second.sort();
        stack<string> st;
        st.push("JFK");
        while(!st.empty())
        {
            string top=st.top();
            if(!mp[top].size())
            {
                res.push_back(top);
                st.pop();
            }
            else
            {
                st.push(mp[top].front());
                mp[top].pop_front();
            }
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};
