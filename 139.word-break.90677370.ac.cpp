/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (31.31%)
 * Total Accepted:    199.4K
 * Total Submissions: 636.8K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words. You may assume the dictionary does
 * not contain duplicate words.
 * 
 * 
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * 
 * 
 * 
 * Return true because "leetcode" can be segmented as "leet code".
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
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word;
        for(auto i:wordDict)
        {
            word.insert(i);
        }
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string temp=s.substr(j,i-j);
                   // std::cout<<temp<<"\n";
                    if(word.find(temp)!=word.end())
                    {
                        //std::cout<<"*\n";
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};
