/*
 * [396] Rotate Function
 *
 * https://leetcode.com/problems/rotate-function/description/
 *
 * algorithms
 * Medium (33.74%)
 * Total Accepted:    25.9K
 * Total Submissions: 76.9K
 * Testcase Example:  '[]'
 *
 * 
 * Given an array of integers A and let n to be its length.
 * 
 * 
 * 
 * Assume Bk to be an array obtained by rotating the array A k positions
 * clock-wise, we define a "rotation function" F on A as follow:
 * 
 * 
 * 
 * F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
 * 
 * Calculate the maximum value of F(0), F(1), ..., F(n-1). 
 * 
 * 
 * Note:
 * n is guaranteed to be less than 105.
 * 
 * 
 * Example:
 * 
 * A = [4, 3, 2, 6]
 * 
 * F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
 * F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
 * F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
 * F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
 * 
 * So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
 * 
 * 
 */
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        deque<int> deq;
        int a_size=A.size();
        //priority_queue<int,vector<int>,std::less<int>> pr;
        int max;
        for(int i=0;i<a_size;i++)
        {
            deq.push_back(A[i]);
        }
        int sum=0;
        int sum_se=0;
        for(int i=0;i<a_size;i++)
        {
            sum_se+=A[i];
            sum+=i*A[i];
        }
        max=sum;
        for(int i=1;i<a_size;i++)
        {
            int temp=deq[a_size-1];
            deq.pop_back();
            deq.push_front(temp);
            sum+=(-(a_size)*deq[0])+sum_se;
            //std::cout<<pr.top()<<"\n";
            if(max<sum)
            {
                max=sum;
            }
        }
        return max;
    }
};
