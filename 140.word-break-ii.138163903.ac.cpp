/*
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (24.36%)
 * Total Accepted:    109.2K
 * Total Submissions: 448.5K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. You may assume the dictionary does not contain
 * duplicate words.
 * 
 * 
 * 
 * Return all such possible sentences.
 * 
 * 
 * 
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * 
 * 
 * 
 * A solution is ["cats and dog", "cat sand dog"].
 * 
 * 
 * 
 * UPDATE (2017/1/4):
 * The wordDict parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
    unordered_map<string,vector<string> >mp;
    
    vector<string> combine(string word,vector<string> rev)
    {
        for(int i=0;i<rev.size();i++)
            rev[i]+=" "+word;
        return rev;
    }
public:
    vector<string> helper(string s,unordered_set<string> st)
    {
        if(mp.find(s)!=mp.end())
            return mp[s];
        vector<string> result;
        if(st.find(s)!=st.end())
            result.push_back(s);
        for(int i=1;i<s.length();i++)
        {
            string word=s.substr(i);
            if(st.count(word))
            {
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,helper(rem,st));
                result.insert(result.end(),prev.begin(),prev.end());
            }
        }
        mp[s]=result;
        return result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st{wordDict.begin(),wordDict.end()};
        return helper(s,st);
    }
};
