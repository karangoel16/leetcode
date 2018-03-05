/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (28.87%)
 * Total Accepted:    252.5K
 * Total Submissions: 874.7K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 
 * Implement strStr().
 * 
 * 
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * 
 * Example 1:
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 */
class Solution {
public:
    vector<int> pattern(string s)
    {
        int n=s.length();
        vector<int> pat;
        pat.push_back(0);
        int i=1,len=0;
        while(i<n){
            if(s[i]==s[len])
            {
                pat.push_back(++len);
                i++;
            }
            else if(len)
            {
                len=pat[len-1];
            }
            else
            {
                pat.push_back(0);
                i++;
            }
        }
        return pat;
    }
    int strStr(string haystack, string needle) {
        int m=haystack.length();
        int n=needle.length();
        if(!n){
            return 0;
        }
        vector<int> result = pattern(needle);
        for(int i=0,j=0;i<m;)
        {
            if(needle[j]==haystack[i])
            {
                //std::cout<<"**";
                i++;
                j++;
            }
            //std::cout<<i<<" "<<j<<"\n";
            if(j==n)
            {
                return i-j;
            }
            if(i<m && needle[j]!=haystack[i])
            {
                if(j)
                {
                    j=result[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};
