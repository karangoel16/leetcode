/*
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (54.69%)
 * Total Accepted:    35.1K
 * Total Submissions: 64.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 * 
 * For example, these are arithmetic sequence:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic. 1, 1, 2, 5, 7 
 * 
 * 
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0 
 * 
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * ⁠   A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this
 * means that P + 1 < Q.
 * 
 * The function should return the number of arithmetic slices in the array
 * A. 
 * 
 * 
 * Example:
 * 
 * A = [1, 2, 3, 4]
 * 
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3,
 * 4] itself.
 * 
 */
class Solution {
    
public:
    int cal(int n)
    {
        return n<3?0:(n-2)*(n-1)/2;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3)
        {
            return 0;
        }
        A.insert(A.begin(),INT_MAX);
        int diff=INT_MAX;
        int size=1;
        int res=0;
        for(int i=1;i<A.size();i++)
        {
            //std::cout<<diff<<"\n";
            int temp=A[i]-A[i-1];
            if(temp==diff)
            {
                size++;
            }
            if(diff!=temp)
            {
                res+=cal(size+1);
                size=1;
                diff=temp;
            }
        }
        return res+cal(size+1);
    }
};
