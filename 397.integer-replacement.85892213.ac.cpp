/*
 * [397] Integer Replacement
 *
 * https://leetcode.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (30.48%)
 * Total Accepted:    27.7K
 * Total Submissions: 90.7K
 * Testcase Example:  '8'
 *
 * 
 * Given a positive integer n and you can do operations as follow:
 * 
 * 
 * 
 * 
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * 
 * 
 * 
 * 
 * What is the minimum number of replacements needed for n to become 1?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 8
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 7
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 * 
 * 
 */
void support(long n,int &max,int val)
{
    //std::cout<<n<<"\n";
    if(n<1)
    {
        return ;
    }
    else if(n==1)
    {
        if(max>val)
        {
            max=val;
        }
        return ;
    }
    if(n%2==0)
    {
        support(n/2,max,val+1);
    }
    else if(n%2==1)
    {
        support(n-1,max,val+1);
        support(n+1,max,val+1);
    }
    return ;
}
class Solution {
public:
    int integerReplacement(int n) {
        int max=INT_MAX;
        support(n,max,0);
        return max;
    }
};
