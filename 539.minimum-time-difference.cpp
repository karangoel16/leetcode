/*
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (46.04%)
 * Total Accepted:    15.3K
 * Total Submissions: 33.2K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list. 
 * 
 * Example 1:
 * 
 * Input: ["23:59","00:00"]
 * Output: 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * 
 * 
 */
class Solution {
public:
    
    int time(string s){
        vector<string> rs;
        stringstream ss(s);
        string line;
        while(getline(ss,line,':')){
            rs.push_back(line);
        }
        //std::cout<<rs[0]<<" "<<rs[1]<<" "<<stoi(rs[0])*60+stoi(rs[1])<<endl;
        return stoi(rs[0])*60+stoi(rs[1]);
    }
    
    int findMinDifference(vector<string>& timePoints) {
        int size=timePoints.size();
        if(!size)
            return 0;
        std::sort(timePoints.begin(),timePoints.end());
        int diff =INT_MAX;
        for(int i=1;i<size;i++){
            int time1=time(timePoints[i]);
            int time2=time(timePoints[i-1]);
            if(abs(time1-time2)<diff){
                diff=time1-time2;
            }
        }
        return min(diff,1440+time(timePoints[0])-time(timePoints[size-1]));
    }
};