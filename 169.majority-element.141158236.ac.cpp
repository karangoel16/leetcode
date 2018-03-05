/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (47.81%)
 * Total Accepted:    246.9K
 * Total Submissions: 516.5K
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand=0,count=0;
        for(auto i:nums){
            if(count==0)
                cand=i;
            if(cand==i)
                count++;
            else
                count--;
        }
        return cand;
    }
};
