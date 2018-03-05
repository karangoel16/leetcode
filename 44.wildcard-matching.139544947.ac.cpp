/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (20.91%)
 * Total Accepted:    118K
 * Total Submissions: 564.2K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        int count=0;
        for(int i=0;i<n;i++) count+=(p[i]=='*')?1:0;
        if(m<n-count ||(count==0 && m!=n)) return false;
        vector<bool> pre(n+1,false);
        pre[0]=true;
        for(int j=1; j<=n; j++)
            pre[j] = pre[j-1] && p[j-1]=='*';
        for(int i=1;i<=m;i++){
            vector<bool> cur(n+1,false);
            for(int j=1;j<=n;j++)
            {
                
                if(p[j-1]=='*'){
                    cur[j]=cur[j-1] || pre[j];
                }
                else{
                    cur[j]=pre[j-1] && ((s[i-1]==p[j-1]) || (p[j-1]=='?'));
                }
            }
            pre=cur;
        }
        return pre[n];
    }
};
