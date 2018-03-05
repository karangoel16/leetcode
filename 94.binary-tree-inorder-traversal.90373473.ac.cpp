/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (49.13%)
 * Total Accepted:    261.2K
 * Total Submissions: 531.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree [1,null,2,3],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [1,3,2].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root==NULL)
        {
            return res;
        }
        stack<TreeNode *>st;
        TreeNode *left=root;
        while(left!=NULL)
        {
            st.push(left);
            left=left->left;
        }
        while(!st.empty())
        {
            res.push_back(st.top()->val);
            TreeNode *left=st.top()->right;
            st.pop();
            while(left!=NULL)
            {
                st.push(left);
                left=left->left;
            }
        }
        return res;
        
    }
};
