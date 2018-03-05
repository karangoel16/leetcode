/*
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.70%)
 * Total Accepted:    35.6K
 * Total Submissions: 96.9K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int countSegments(string s) 
    {
        if(s.length()==0)
        {
            return 0;
        }
        int i=0;
        while(i<s.length() && s[i]==' ')
        {
            i++;
        }
        if(i<s.length())
        {
            string temp=s.substr(i)+" ";
            size_t pos=0;
            int t=0;
            while((pos=temp.find(" "))!=std::string::npos)
            {
                t++;
                while(temp[pos]==' ')
                {
                    temp[pos]='*';
                    pos++;
                }
                //temp.erase(0,pos+1);
            }
            return t;
        }
        return 0;
    }
};
