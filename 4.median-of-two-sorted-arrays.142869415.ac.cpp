/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (22.83%)
 * Total Accepted:    237.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizeX=nums1.size(),sizeY=nums2.size();
        if(sizeX>sizeY)
        {
            auto temp=nums1;
            nums1=nums2;
            nums2=temp;
        }
        sizeX=nums1.size(),sizeY=nums2.size();
        if(!sizeX)
            return (sizeY)%2==0?(nums2[sizeY/2-1]+nums2[sizeY/2])/2.0:nums2[sizeY/2];
        int low=0, high=sizeX;
        while(low<=high){
            int partX=(low+high)/2;
            int partY=(sizeX+sizeY+1)/2-partX;
            int maxLeftX = (partX<=0)?INT_MIN:nums1[partX-1];
            int minRightX = partX>=(sizeX)?INT_MAX:nums1[partX];
            int maxLeftY = (partY<=0)?INT_MIN:nums2[partY-1];
            int minRightY = partY>=(sizeY)?INT_MAX:nums2[partY];
            if(maxLeftX<=minRightY && maxLeftY<=minRightX)
            {
                if((sizeX+sizeY)%2==1)
                    return max(maxLeftX,maxLeftY);
                else
                    return (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
            }
            if(maxLeftX>minRightY){
                high=partX-1;
            }
            else{
                low=partX+1;
            }
        }
        return 0;
    }
};
