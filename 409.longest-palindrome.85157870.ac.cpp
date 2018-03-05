/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (45.82%)
 * Total Accepted:    59.8K
 * Total Submissions: 130.5K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++)
        {
            std::unordered_map<char,int>::iterator it=map.find(s[i]);
            if(it!=map.end())
            {
                map[s[i]]++;
            }
            else
            {
                map[s[i]]=1;//this is to insert new element in the hash map
            }
        }
        bool res=false;
        int pall=0;
        for(auto it=map.begin();it!=map.end();it++)
        {
            //std::cout<<it->second<<"\n";
            if(it->second%2==1)
            {
                res=true;
            }
            pall+=((it->second)/2)*2;
        }
        return res?pall+1:pall;
    }
};
