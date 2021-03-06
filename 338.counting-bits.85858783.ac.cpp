/*
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (62.10%)
 * Total Accepted:    104.9K
 * Total Submissions: 168.9K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * 
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 * 
 * 
 * Follow up:
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount  in c++ or in any other language.
 * 
 * 
 * 
 * Credits:Special thanks to @ syedee  for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    vector<int> countBits(int num) {
        int loop=ceil(log(num));
        //std::cout<<loop<<"\n";
        vector <int> res{0};
        int j=0;
        int res_size=res.size();
        for(int i=1;i<=num;i++)
        {
            res.push_back(res[j++]+1);
            if(j==res_size)
            {
                j=0;
                res_size=2*res_size;
            }
        }
        return res;
    }
};
