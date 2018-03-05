/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (33.51%)
 * Total Accepted:    204.7K
 * Total Submissions: 610.9K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
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
    int min(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int temp_left=min(root->left)+1;
        int temp_right=min(root->right)+1;
        if(temp_left>=temp_right && root->right!=NULL)
        {
            return temp_right;
        }
        if(temp_left<=temp_right && root->left!=NULL)
        {
            return temp_left;
        }
        if(temp_left<=temp_right && root->left==NULL)
        {
            return temp_right;
        }
        if(temp_left>=temp_right && root->right==NULL)
        {
            return temp_left;
        }
        return 1;
    }
    int minDepth(TreeNode* root) {
        return min(root);
    }
};
