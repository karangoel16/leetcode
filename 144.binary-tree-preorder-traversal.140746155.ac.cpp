/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (46.55%)
 * Total Accepted:    216.8K
 * Total Submissions: 465.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
 * return [1,2,3].
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *>st;
        if(!root)
            return {};
        TreeNode *temp=root;
        st.push(root);
        while(!st.empty()){
            temp=st.top();
            st.pop();
            if(temp->right!=NULL)
                st.push(temp->right);
            if(temp->left!=NULL)
                st.push(temp->left);
            res.push_back(temp->val);
        }
        return res;
    }
};
