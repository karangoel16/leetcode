/*
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (27.04%)
 * Total Accepted:    121.3K
 * Total Submissions: 448.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a binary tree, find the maximum path sum.
 * 
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * 
 * For example:
 * Given the below binary tree,
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 
 * 
 * Return 6.
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
    int result;
public:
    int helper(TreeNode *root)
    {
        int left=(root->left==NULL)?0:helper(root->left);
        int right=(root->right==NULL)?0:helper(root->right);
        left=left<0?0:left;
        right=right<0?0:right;
        result=std::max(result,left+right+root->val);
        return std::max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        result=INT_MIN;
        helper(root);
        return result;
    }
};
