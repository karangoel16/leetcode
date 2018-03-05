/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (42.05%)
 * Total Accepted:    49K
 * Total Submissions: 116.4K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 
 * Given an encoded string, return it's decoded string.
 * 
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 */
class Solution {
public:
    string helper(string &s,int &i){
        stringstream res;
        //std::cout<<"*"<<endl;
        while(i<s.length() && s[i]!=']'){
            if(!isdigit(s[i]))
                res<<s[i++];
            else{
                int val=0;
                while(i<s.length() && isdigit(s[i]))
                    val=10*val+(s[i++]-'0');
                i++;
                string t=helper(s,i);
                i++;
                while(val--)
                    res<<t;
            }
        }
        return res.str();
    }
    string decodeString(string s) {
        int i=0;
        stringstream res;
        while(i<s.length()){
            res<<helper(s,i);
        }
        return res.str();
    }
};
