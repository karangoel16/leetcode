/*
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (51.87%)
 * Total Accepted:    23K
 * Total Submissions: 44.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array, find the minimum number of moves required
 * to make all array elements equal, where a move is incrementing a selected
 * element by 1 or decrementing a selected element by 1.
 * 
 * You may assume the array's length is at most 10,000.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * 
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 */
template <typename It>
auto Median(It begin, It end)
{
    const auto size = std::distance(begin, end);
    std::nth_element(begin, begin + size / 2, end);
    return *std::next(begin, size / 2);
}
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int temp=Median(nums.begin(),nums.end());
        int res=0;
        for(auto i:nums)
            res+=abs(i-temp);
        return res;
    }
};
