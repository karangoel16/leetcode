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
        {
            return vector<int>();
        }
        vector<int> left(26,-1);
        vector<int> right(26,-1);
        vector<int> res;
        for(int i=0;i<S.length();i++)
        {
            if(left[S[i]-'a']==-1)
                left[S[i]-'a']=i;
            if(right[S[i]-'a']<i)
                right[S[i]-'a']=i;
        }
        int max=right[S[0]-'a'];
        int min=0;
        for(int i=0;i<S.length();i++)
        {
            min=std::min(min,left[S[i]-'a']);
            max=std::max(max,right[S[i]-'a']);
            if(i==max)
            {
                res.push_back(max-min+1);
                min=i+1;
            }
            //std::cout<<min<<" "<<max<<"\n";
        }
        return res;
    }
};
