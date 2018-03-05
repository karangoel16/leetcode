/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (36.46%)
 * Total Accepted:    129.9K
 * Total Submissions: 356.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
int helper(vector<vector<int>> &res,int rank,TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(res.size()==rank)
    {
        res.push_back(std::vector<int>{root->val});
    }
    else
    {
        res[rank].push_back(root->val);
    }
    helper(res,rank+1,root->left);
    helper(res,rank+1,root->right);
    return 1;
}
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        helper(res,0,root);
        for(int i=1;i<res.size();i+=2)
        {
            std::reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};
