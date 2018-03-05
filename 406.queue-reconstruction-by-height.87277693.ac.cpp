/*
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (56.69%)
 * Total Accepted:    40.4K
 * Total Submissions: 71.2K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 * 
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * 
 * 
 * 
 * Example
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */
struct compare{
    bool operator ()(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first>b.first)
        {
            return true;
        }
        if(a.first==b.first && a.second<b.second)
        {
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        std::sort(people.begin(),people.end(),compare());
        vector<pair<int,int>> res;
        for(auto i:people)
        {
            res.insert(res.begin()+i.second,i);
        }
        return res;
    }
};
