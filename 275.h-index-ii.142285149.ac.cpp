/*
 * [275] H-Index II
 *
 * https://leetcode.com/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (34.85%)
 * Total Accepted:    60K
 * Total Submissions: 172.2K
 * Testcase Example:  '[]'
 *
 * 
 * Follow up for H-Index: What if the citations array is sorted in ascending
 * order? Could you optimize your algorithm?
 * 
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0,high=citations.size()-1,size=citations.size();
        if(!size)
            return 0;
        while(low<=high){
            int mid=(low+high)/2;
            //std::cout<<mid<<endl;
            if(citations[mid]==(size-mid))
                return citations[mid];
            else if(citations[mid]<(size-mid))
                low=mid+1;
            else
                high=mid-1;
        }
         return size - (high+1);
    }
};
