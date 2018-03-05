/*
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (34.73%)
 * Total Accepted:    205K
 * Total Submissions: 590.1K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool path1(TreeNode *root,int path,int sum)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(path+root->val==sum)
            {
                    return true;
            }
        }
        bool res1=false;
        bool res2=false;
        if(root->left!=NULL)
        {
            res1=path1(root->left,path+root->val,sum);
        }
        if(root->right!=NULL)
        {
            res2=path1(root->right,path+root->val,sum);
        }
        return res1||res2;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
        {
            return false;
        }
        return path1(root,0,sum);
    }
};
