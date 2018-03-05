/*
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (37.22%)
 * Total Accepted:    5.8K
 * Total Submissions: 15.6K
 * Testcase Example:  '[5,10,-5]'
 *
 * 
 * We are given an array asteroids of integers representing asteroids in a
 * row.
 * 
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 * 
 * Find out the state of the asteroids after all collisions.  If two asteroids
 * meet, the smaller one will explode.  If both are the same size, both will
 * explode.  Two asteroids moving in the same direction will never meet.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * asteroids = [5, 10, -5]
 * Output: [5, 10]
 * Explanation: 
 * The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * asteroids = [8, -8]
 * Output: []
 * Explanation: 
 * The 8 and -8 collide exploding each other.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: 
 * asteroids = [10, 2, -5]
 * Output: [10]
 * Explanation: 
 * The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in
 * 10.
 * 
 * 
 * 
 * Example 4:
 * 
 * Input: 
 * asteroids = [-2, -1, 1, 2]
 * Output: [-2, -1, 1, 2]
 * Explanation: 
 * The -2 and -1 are moving left, while the 1 and 2 are moving right.
 * Asteroids moving the same direction never meet, so no asteroids will meet
 * each other.
 * 
 * 
 * 
 * Note:
 * The length of asteroids will be at most 10000.
 * Each asteroid will be a non-zero integer in the range [-1000, 1000]..
 * 
 */
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> res;
        if(!asteroids.size())
            return res;
        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty())
                st.push(asteroids[i]);
            else{
                bool flag=true;
                while(!st.empty() && (asteroids[i]<=0 && st.top()>0) && abs(st.top()) <= abs(asteroids[i]) && flag){
                    if(st.top()>0 && asteroids[i]<0 && abs(st.top())>=abs(asteroids[i]))
                        flag=false;
                    st.pop();
                    
                }
                    
                if((st.empty() || st.top()*asteroids[i]>=0 || (st.top()<0 && asteroids[i]>0))&& flag)
                    st.push(asteroids[i]);
            }
        }
        while(!st.empty())
            res.push_back(st.top()),st.pop();
        std::reverse(res.begin(),res.end());
        return res;
    }
};
