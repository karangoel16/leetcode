/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.24%)
 * Total Accepted:    107.3K
 * Total Submissions: 227.2K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
	int firstUniqChar(std::string s) {
        int i=0,flag;
        if(s.length()==1)
        {
            return 0;
        }
        while(i<s.length())
        {
            int j=0;
            flag=1;
            while(j<s.length())
            {
                if(s[i]==s[j] && i!=j)
                {
                  flag=0;
                  break;
                }
                j++;
                if(flag==1 && j>=s.length())
            	{
                	return i;
            	}
            }
            i++;
        }
        return -1;
    }
};
