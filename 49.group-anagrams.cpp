/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (37.93%)
 * Total Accepted:    186K
 * Total Submissions: 490.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
 */
class Solution {
public:
    int find(string s)
    {
        vector<int> mp=vector<int>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        int p=1;
        for(auto i:s)
        { 
            p*=mp[i-'a'];
        }
        return p;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
            mp[find(strs[i])].emplace_back(std::move(strs[i]));
        vector<vector<string>> res;
        res.reserve(strs.size());
        for(auto i:mp){
            std::sort(i.second.begin(),i.second.end());
            res.emplace_back(std::move(i.second));
        }
        return res;
    }
};
