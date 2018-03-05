/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (27.23%)
 * Total Accepted:    197.3K
 * Total Submissions: 724.4K
 * Testcase Example:  '""\n1'
 *
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        vector<string> str(numRows,"");
        //str=new stringstream[numRows];//this is to add number of rows
        int flag=0;
        int k=0;
        for(int i=0;i<s.length();i++)
        {
            //std::cout<<k<<"\t";
            str[k]+=s[i];
            if(flag==0)
            {
                k++;//this is for adding next
                if(k%numRows==0)
                {
                    flag=1;
                    k--;
                }
            }
            if(flag)
            {
                k--;
                if(k==0)
                {
                    flag=0;
                }
            }
        }
        for(int i=1;i<numRows;i++)
        {
            str[0]+=str[i];   
        }
        return str[0];
    }
};
