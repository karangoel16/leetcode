/*
 * [593] Valid Square
 *
 * https://leetcode.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (39.87%)
 * Total Accepted:    10.2K
 * Total Submissions: 25.7K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * Given the coordinates of four points in 2D space, return whether the four
 * points could construct a square.
 * 
 * The coordinate (x,y) of a point is represented by an integer array with two
 * integers.
 * 
 * Example:
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: True
 * 
 * 
 * 
 * ⁠Note: 
 * 
 * All the input integers are in the range [-10000, 10000].
 * A valid square has four equal sides with positive length and four equal
 * angles (90-degree angles).
 * Input points have no order.
 * 
 * 
 */
class Solution {
public:
    int dist(vector<int> p1,vector<int> p2)
    {
        return (pow((p1[0]-p2[0]),2)+pow((p1[1]-p2[1]),2));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //std::cout<<dist(p1,p2);
        unordered_set<int> st={dist(p1,p2),dist(p2,p3),dist(p3,p4),dist(p4,p1),dist(p1,p3),dist(p2,p4)};
        return !st.count(0) && st.size()==2;
    }
};
