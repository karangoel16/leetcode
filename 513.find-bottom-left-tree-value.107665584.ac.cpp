/*
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (56.01%)
 * Total Accepted:    39.4K
 * Total Submissions: 70.3K
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree. 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Output:
 * 1
 * 
 * 
 * 
 * ⁠ Example 2: 
 * 
 * Input:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * Output:
 * 7
 * 
 * 
 * 
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
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
    int level;
    int val;
public:
    Solution()
    {
        level=INT_MIN;
    }
    void helper(TreeNode *root,int phase=0)
    {
        if(root==NULL)
        {
            return ;
        }
        helper(root->left,phase+1);
        if(phase>level)
        {
            level=phase;
            val=root->val;
        }
        helper(root->right,phase+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        helper(root);
        return val;
    }
};
