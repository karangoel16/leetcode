/*
 * [779] Max Chunks To Make Sorted II
 *
 * https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/
 *
 * algorithms
 * Hard (41.53%)
 * Total Accepted:    2.7K
 * Total Submissions: 6.5K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * This question is the same as "Max Chunks to Make Sorted" except the integers
 * of the given array are not necessarily distinct, the input array could be up
 * to length 2000, and the elements could be up to 10**8.
 * 
 * 
 * 
 * Given an array arr of integers (not necessarily distinct), we split the
 * array into some number of "chunks" (partitions), and individually sort each
 * chunk.  After concatenating them, the result equals the sorted array.
 * 
 * What is the most number of chunks we could have made?
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [5,4,3,2,1]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2,
 * 3], which isn't sorted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,1,3,4,4]
 * Output: 4
 * Explanation:
 * We can split into two chunks, such as [2, 1], [3, 4, 4].
 * However, splitting into [2, 1], [3], [4], [4] is the highest number of
 * chunks possible.
 * 
 * 
 * Note:
 * 
 * 
 * arr will have length in range [1, 2000].
 * arr[i] will be an integer in range [0, 10**8].
 * 
 * 
 * 
 */
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> val(arr.size());
        iota(val.begin(),val.end(),0);
        std::sort(val.begin(),val.end(),[&](int &a,int &b){
            return arr[a]==arr[b]?a<b:arr[a]<arr[b];
        });
        for (auto i = 0, max_i = 0, ch = 0; i <= arr.size(); ++i) {
            if (i == arr.size()) return ch;
            max_i = max(max_i, val[i]);
            if (max_i == i) ++ch;
        }
    }
};
