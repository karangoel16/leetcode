/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.20%)
 * Total Accepted:    90.3K
 * Total Submissions: 594.4K
 * Testcase Example:  '[]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    int GCD(int a, int b) {    
        if(b==0) return a;
        else return GCD(b, a%b);
    }
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()<2)
            return points.size();
        int res=0;
        for(int i=0;i<points.size();i++){
            int overlap=0,vertical=0,localmax=0;
            map<pair<int,int>,int> lines;
            for(int j=i+1;j<points.size();j++){
                if(points[j].x==points[i].x && points[j].y==points[i].y)
                {
                    overlap++;
                    //continue;
                }  
                else if(points[j].x==points[i].x)
                    vertical++;
                else   {
                    int a=points[j].x-points[i].x,b=(points[j].y-points[i].y);
                    int gcd=GCD(a,b);
                    a/=gcd;
                    b/=gcd;
                    localmax=std::max(++lines[{a,b}],localmax);
                }
                localmax=std::max(localmax,vertical);    
            }
            res=std::max(localmax+overlap+1,res);
        }
        return res;
    }
};
