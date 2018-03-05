/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (33.40%)
 * Total Accepted:    99K
 * Total Submissions: 296.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Examples:
 * 
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * 
 * 
 * 
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * 
 * 
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.length()==0 && str.length()!=0)
        {
            return false;
        }
        if(pattern.length()==0 && str.length()==0)
        {
            return true;
        }
        std::map<char,string> list;
        const char *p=str.c_str();
        int i=0;
        int flag=0;
        int j=0;
        char pat;
        while(i<=str.length())
        {
            pat=pattern[j];
            if(p[i]==' ' || i==str.length())
            {
                string temp=str.substr(flag,i-flag);
                for(std::map<char,string>::iterator it=list.begin();it!=list.end();++it)
                {
                    if(it->second==temp && pat!=it->first || it->first==pat && it->second!=temp)
                    {
                        return false;
                    }
                }
                list.insert(std::pair<char,string>(pat,temp));
                flag=i+1;
                ++j;
            }
            ++i;
        }
        //std::cout<<j<<" "<<pattern.length();
        if(j<pattern.length())
        {
          return false;
        }
        //for(std::map<char,string>::iterator it=list.begin();it!=list.end();++it)
        //    cout<<it->first<<" "<<it->second<<"\n";
        //std::sort(pattern.begin(),pattern.end());
        //std::cout<<j<<"\n";
        //print list;
        return true;
    }
};
