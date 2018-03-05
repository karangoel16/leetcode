/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (41.84%)
 * Total Accepted:    156.9K
 * Total Submissions: 374.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        helper(res,0,root);
        std::reverse(res.begin(),res.end());
        return res;
    }
};
