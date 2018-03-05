/*
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (35.27%)
 * Total Accepted:    14.6K
 * Total Submissions: 41.3K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * ⁠Length of the given array is positive and will not exceed 104
 * ⁠Absolute value of elements in the array and x will not exceed 104
 * 
 * 
 * 
 * 
 * 
 * 
 * UPDATE (2017/9/19):
 * The arr parameter had been changed to an array of integers (instead of a
 * list of integers). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        if(arr.size()<k)
        {
            return vector<int>{};
        }
        int high=arr.size()-k;
        int diff= abs(arr[0]-x);
        int index=0;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(x-arr[mid]>arr[mid+k]-x)
            {
               low=mid+1;
            }
            else
            {
                high=mid;
            }
            //std::cout<<low<<" "<<high<<"\n";
        }
        //std::cout<<index<<"\n";
        return vector<int>{arr.begin()+low,arr.begin()+low+k};
    }
};
