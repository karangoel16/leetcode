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
public:

    vector<string> letterCombinations(string digits) {
        if(digits.length()<1)
        return {};
        vector<string> test={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        queue<string> que;
        vector<string> res;
        for(auto i:test[digits.front()-'0'])
            que.push(string(1,i));
        int i=1;
        while(i<digits.size()){
            int size=que.size();
            while(size--){
                auto temp=que.front();
                que.pop();
                for(auto j:test[digits[i]-'0'])
                    que.push(temp+j);
            }
            i++;
        }
        res.reserve(que.size());
        while(!que.empty()){
            res.emplace_back(std::move(que.front()));
            que.pop();
        }
        return res;
    }
};
