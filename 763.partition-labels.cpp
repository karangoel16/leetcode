/*
 * [768] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (64.88%)
 * Total Accepted:    7.4K
 * Total Submissions: 11.4K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 
 * A string S of lowercase letters is given.  We want to partition this string
 * into as many parts as possible so that each letter appears in at most one
 * part, and return a list of integers representing the size of these parts.
 * 
 * 
 * Example 1:
 * 
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits S into less parts.
 * 
 * 
 * 
 * Note:
 * S will have length in range [1, 500].
 * S will consist of lowercase letters ('a' to 'z') only.
 * 
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(!S.length())
            return {};
        vector<int> res,last(26,0);
        res.reserve(S.length());
        for(int i=0;i<S.length();i++)
            last[S[i]-'a']=i;
        int left=0,right=0;
        for(int i=0;i<S.size();i++){
            if(i>right){
                res.emplace_back(right-left+1);
                left=right+1;
            }
            right=max(right,last[S[i]-'a']);
        }
        res.push_back(right-left+1);
        return res;
    }

};
