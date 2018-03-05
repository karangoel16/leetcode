/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (26.91%)
 * Total Accepted:    212K
 * Total Submissions: 787.9K
 * Testcase Example:  '""'
 *
 * 
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * 
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * 
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 * ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0)
        {
            return true;
        }
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        std::string p="";
        int i=0;
        int j=s.length()-1;
        int flag=0;
        while(i<j)
        {
            if(isalnum(s[i])&&(isalnum(s[j])))
            {
                //std::cout<<s[i]<<" "<<s[j]<<"\n";
                if(s[i]!=s[j])
                {
                    return false;
                }
                if(s[i]==s[j])
                {
                    --j;
                    ++i;
                }
            }
            if(!isalnum(s[j]))
                --j;
            if(!isalnum(s[i]))    
                ++i;
        }
        std::cout<<p;
        return true;
    }
};
