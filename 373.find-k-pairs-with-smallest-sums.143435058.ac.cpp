/*
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (31.20%)
 * Total Accepted:    38.3K
 * Total Submissions: 122.9K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * 
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k. 
 * 
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * 
 * Example 1:
 * 
 * Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 * 
 * Return: [1,2],[1,4],[1,6]
 * 
 * The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * 
 * Example 2:
 * 
 * Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 * 
 * Return: [1,1],[1,1]
 * 
 * The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 
 * 
 * Example 3:
 * 
 * Given nums1 = [1,2], nums2 = [3],  k = 3 
 * 
 * Return: [1,3],[2,3]
 * 
 * All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap and @StefanPochmann for adding this
 * problem and creating all test cases.
 */
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1=nums1.size();
        int size2=nums2.size();
        if(!size1 || !size2)
            return {};
        vector<pair<int,int>> res;
        auto comp=[&](pair<int,int> &a,pair<int,int> &b){
            return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        pq.push({0,0});
        vector<int> x_mov={0,1};
        vector<int> y_mov={1,0};
        vector<vector<bool>> visited(size1,vector<bool>(size2,false));
        visited[0][0]=true;
        while(k>0 && !pq.empty()){
            auto temp=pq.top();
            pq.pop();
            res.push_back({nums1[temp.first],nums2[temp.second]});
            k--;
            for(int i=0;i<2;i++)
            {
                int temp_x=temp.first+x_mov[i];
                int temp_y=temp.second+y_mov[i];
                if(temp_x>=0 && temp_x<size1 && temp_y>=0 && temp_y<size2 && !visited[temp_x][temp_y] ){
                    pq.push({temp_x,temp_y});
                    visited[temp_x][temp_y]=true;
                }
            }
        }
        return res;
    }
};
