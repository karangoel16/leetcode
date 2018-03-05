/*
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (33.65%)
 * Total Accepted:    69.9K
 * Total Submissions: 207.7K
 * Testcase Example:  '-2\n-2\n2\n2\n-2\n-2\n2\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem, creating the
 * above image and all test cases.
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int abcd = (A-C)*(B-D);
    int efgh = (E-G)*(F-H);
    int common = OverlapLength(A, C, E, G) * OverlapLength(B, D, F, H);
    return abcd + efgh - common;
    }


    int OverlapLength(int A, int C, int E, int G)
    {
        if(C < E || A > G)
            return 0;
        return min(C, G) - max(A, E);
    }
};
