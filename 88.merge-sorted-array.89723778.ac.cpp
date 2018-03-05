/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (32.16%)
 * Total Accepted:    220.4K
 * Total Submissions: 685.2K
 * Testcase Example:  '[1]\n1\n[]\n0'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * 
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m+n-1;
        //nums1.resize(i);
        int j=n-1;
        int k=m-1;
        while(j>=0 && k>=0)
        {
            if(nums1[k]>=nums2[j])
            {
                nums1[i]=nums1[k];
                k--;
            }
            else
            {
                nums1[i]=nums2[j];
                j--;
            }
            //std::cout<<i<<" "<<j<<" "<<k<<"\n";
            i--;
        }
        while(j>=0)
        {
            nums1[i--]=nums2[j--];
        }
    }
};
