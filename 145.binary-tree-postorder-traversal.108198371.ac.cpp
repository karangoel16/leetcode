/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (41.72%)
 * Total Accepted:    170K
 * Total Submissions: 407.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree [1,null,2,3],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * 
 * return [3,2,1].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> val;
        stack<TreeNode *>st;
        TreeNode *p=root;
        while(!st.empty() || p!=NULL)
        {
            //std::cout<<"*";
            if(p!=NULL)
            {
                st.push(p);
                val.push_back(p->val);
                p=p->right;
            }
            else
            {
                p=st.top()->left;
                st.pop();
            }
        }
        std::reverse(val.begin(),val.end());
        return val;
    }
};
