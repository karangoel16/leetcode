/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (42.21%)
 * Total Accepted:    26.6K
 * Total Submissions: 63.1K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 * 
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * 
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */
#define ipair pair<string,double>
class uf
{
    private:
    unordered_map<string,ipair> mp;
    public:
    uf(auto que)
    {
        for(auto i:que)
            mp[i]=make_pair(i,1);
    }
    ipair find(string i)
    {
        ipair root=mp[i];
        while(mp[root.first]!=root)
            root=mp[root.first];
        return mp[root.first];
    }
    void unionfind(string p,string q,double value)
    {
        ipair rootp=find(p);
        ipair rootq=find(q);
        if(rootp==rootq)
                return ;
        mp[rootp.first]=rootq;
        mp[rootp.first].second=value*val(q)/val(p);
        return;
    }
    double val(string p)
    {
        double val=1;
        while(mp[p].first!=p)
        {
            val*=mp[p].second;
            p=mp[p].first;
        }
        return val;
    }
    double connect(string p,string q)
    {
        return mp.find(p)!=mp.end() && mp.find(q)!=mp.end() && find(p)==find(q) ? val(p)/val(q) :-1;
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> eq, vector<double>& val, vector<pair<string, string>> queries) {
        unordered_set<string> st;
        vector<double> res;
        for(auto i:eq)
        {
            st.insert(i.first);
            st.insert(i.second);   
        }
        uf union_find(st);
        for(int i=0;i<eq.size();i++)
            union_find.unionfind(eq[i].first,eq[i].second,val[i]);
        for(auto i:queries)
            res.push_back(union_find.connect(i.first,i.second));
        return res;
    }
};
