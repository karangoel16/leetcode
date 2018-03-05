/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (36.18%)
 * Total Accepted:    218.7K
 * Total Submissions: 604.5K
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 * 
 * 
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
private:
    vector <string> test;
    vector <string > result;
public:
    Solution()
    {
        test={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    }
    void support(string res,int digit,string temp)
    {
        if(res.length()==temp.length())
        {
            result.push_back(res);//this is to push back in the vector
            return;
        }
        for(int i=0;i<test[(temp[digit])-'0'].length();i++)
        {
            //std::cout<<test[temp[digit]-'0'][i]<<"\n";
            support(res+test[temp[digit]-'0'][i],digit+1,temp);
        }
    }
    vector<string> letterCombinations(string digits) {
        result.clear();
        if(digits.length()<1)
        {
            return result;
        }
        support("",0,digits);
        return result;
    }
};
