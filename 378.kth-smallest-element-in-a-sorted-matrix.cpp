/*
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (45.46%)
 * Total Accepted:    55.6K
 * Total Submissions: 122.4K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */
#define ipair pair<int,int>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp=[&](ipair &a,ipair &b){
            return matrix[a.first][a.second]>matrix[b.first][b.second];
        };
        priority_queue<ipair,vector<ipair>,decltype(comp)> pq(comp);
        for(int i=0;i<matrix.size();i++)
            pq.push({0,i});
        while(k-->1){
            auto temp=pq.top();
            pq.pop();
            if(temp.first+1<matrix.size())
                pq.push({temp.first+1,temp.second});
        }
        return matrix[pq.top().first][pq.top().second];
    }
};
