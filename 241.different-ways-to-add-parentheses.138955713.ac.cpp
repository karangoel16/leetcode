/*
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (45.82%)
 * Total Accepted:    53.5K
 * Total Submissions: 116.7K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1
 * Input: "2-1-1". 
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 * 
 * Example 2
 * Input: "2*3-4*5" 
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10] 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
    unordered_map<string,vector<int>> mp;
    vector<int> helper(string input)
    {
        vector<int> res;
        if(mp.find(input) !=mp.end())
        {
            return mp[input];
        }
        if(input.empty())
        {
            return res;
        }
        for(int i=0;i<input.length();i++)
        {
            if(input[i]=='+'|| input[i]=='-'||input[i]=='*'){
                vector<int> result1=helper(input.substr(0,i));
                vector<int> result2=helper(input.substr(i+1));
                for(auto n1:result1){
                    for(auto n2:result2){
                        if (input[i] == '+')
							res.push_back(n1 + n2);
						else if (input[i] == '-')
							res.push_back(n1 - n2);
						else
							res.push_back(n1 * n2);
                    }
                }
            }
        }
        if(res.empty())
        {
            res.push_back(stoi(input));
        }
        mp[input]=res;
        return mp[input];
    }
public:
    vector<int> diffWaysToCompute(string input) {
        return helper(input);
    }
};
