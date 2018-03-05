/*
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (27.69%)
 * Total Accepted:    75K
 * Total Submissions: 270.7K
 * Testcase Example:  '[]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int left=0;
        int right=0;
        TreeNode *temp=root;
        while(temp){left++;temp=temp->left;}
        temp=root;
        while(temp){right++;temp=temp->right;}
        if(left==right){
            return pow(2,left)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
