/*
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (55.77%)
 * Total Accepted:    37K
 * Total Submissions: 66.4K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 * 
 * 
 * 
 * Note:
 * 
 * The range of node's value is in the range of 32-bit signed integer.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int,long int> mp;
    unordered_map<int,int> times;
public:
    void helper(TreeNode *root,int level=0)
    {
        if(root==NULL)
        {
            return ;
        }
        mp[level]+=root->val;
        times[level]++;
        helper(root->left,level+1);
        helper(root->right,level+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        helper(root);
        int size=mp.size();
        for(int i=0;i<size;i++)
        {
            result.push_back((double)mp[i]/times[i]);
        }
        return result;
    }
};
