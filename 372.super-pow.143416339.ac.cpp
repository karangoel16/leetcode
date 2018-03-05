/*
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (34.64%)
 * Total Accepted:    20K
 * Total Submissions: 57.7K
 * Testcase Example:  '2\n[3]'
 *
 * 
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is
 * an extremely large positive integer given in the form of an array.
 * 
 * 
 * Example1:
 * 
 * a = 2
 * b = [3]
 * 
 * Result: 8
 * 
 * 
 * 
 * Example2:
 * 
 * a = 2
 * b = [1,0]
 * 
 * Result: 1024
 * 
 * 
 * 
 * Credits:Special thanks to @Stomach_ache for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int mod=1337;
    int quickPow(int a,int b){
        int res=1;
        a=a%mod;
        while(b){
            if(b&1)
                res=(res*a)%mod;
            a=(a*a)%1337;
            b>>=1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(!b.size())
            return 1;
        int res=1;
        for(int i=b.size()-1;i>=0;i--){
            res=(res*quickPow(a,b[i]))%mod;
            a=quickPow(a,10);
        }
        return res;
    }
};
