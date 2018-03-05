/*
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (47.43%)
 * Total Accepted:    80.6K
 * Total Submissions: 170K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
 int helper(TreeNode *root,int &sum)
 {
     if(root==NULL)
     {
         return 1;
     }
     if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
     {
         sum=sum+root->left->val;
         if(root->right!=NULL)
         {
             helper(root->right,sum);
         }
         return 0;
     }
     helper(root->left,sum);
     helper(root->right,sum);
     return 1;
 }
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return sum;
    }
};
