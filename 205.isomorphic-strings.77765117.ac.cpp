/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (34.60%)
 * Total Accepted:    130.1K
 * Total Submissions: 376.2K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * For example,
 * Given "egg", "add", return true.
 * 
 * Given "foo", "bar", return false.
 * 
 * Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.length()!=t.length())
        {
            return false;
        }
        map<char,char>map_1;
        map<char,char>map_2;
        map<char,char>::iterator it1;
        map<char,char>::iterator it2;
        const char *p=s.c_str();
        const char *q=t.c_str();
        int i=0;
        while(i<s.length())
        {
            it1=map_1.find(p[i]);
            it2=map_2.find(q[i]);
            if(it1!=map_1.end() || it2!=map_2.end())
            {
                if(it1->second!=q[i] && it2->second!=p[i])
                {
                    return false;
                }
            }
            if(it1==map_1.end())
            {
                map_1.insert(std::pair<char,char>(p[i],q[i]));
            }
            if(it2==map_2.end())
            {
                map_2.insert(std::pair<char,char>(q[i],p[i]));
            }
            ++i;   
        }
        return true;
    }
};
