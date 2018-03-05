/*
 * [565] Array Nesting
 *
 * https://leetcode.com/problems/array-nesting/description/
 *
 * algorithms
 * Medium (49.41%)
 * Total Accepted:    15.9K
 * Total Submissions: 32.2K
 * Testcase Example:  '[5,4,0,3,1,6,2]'
 *
 * A zero-indexed array A of length N contains all integers from 0 to N-1. Find
 * and return the longest length of set S, where S[i] = {A[i], A[A[i]],
 * A[A[A[i]]], ... } subjected to the rule below.
 * 
 * Suppose the first element in S starts with the selection of element A[i] of
 * index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By
 * that analogy, we stop adding right before a duplicate element occurs in S.
 * 
 * Example 1:
 * 
 * Input: A = [5,4,0,3,1,6,2]
 * Output: 6
 * Explanation: 
 * A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
 * 
 * One of the longest S[K]:
 * S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 * 
 * 
 * 
 * Note:
 * 
 * N is an integer within the range [1, 20,000].
 * The elements of A are all distinct.
 * Each element of A is an integer within the range [0, N-1].
 * 
 * 
 * 
 */
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int size = nums.size();
        if(!size)
        {
            return 0;
        }
        vector<int> visited(size,-1);
        stack<int>st;
        for(int i=0;i<size;i++)
        {
            //we will see that following link has been ever visted or not
            if(visited[i]==-1)//this means that the following link has not been visited ever
            {
                visited[i]=i;//we will allocate its address to the value
                int temp=nums[i];
                while(visited[temp]==-1){
                    st.push(temp);
                    visited[temp]=INT_MAX;
                    temp=nums[temp];//we will change the value of the stack
                    //to show that this is in grey area
                }
                while(!st.empty())
                {
                    visited[st.top()]=i;
                    st.pop();
                }
            }
        }
        unordered_map<int,int> mp;
        int min=INT_MIN;
        for(auto i:visited)
        {
            mp[i]++;
            if(mp[i]>min)
            {
                min=mp[i];
            }
        }
        return min;
    }
};
