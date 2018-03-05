/*
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (35.33%)
 * Total Accepted:    156.7K
 * Total Submissions: 443.6K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 
 * return
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
int helper(vector<vector<int>> &res,vector<int> val,int sum,TreeNode *root,int max)//,set<vector<int>> &mul)
{
    if(root->left==NULL && root->right==NULL)
    {
        max+=root->val;
        val.push_back(root->val);
        if(max==sum )//&& mul.find(val)==mul.end())
        {
            res.push_back(val);
            //mul.insert(val);
        }
        return 1;
    }
    max+=root->val;
    val.push_back(root->val);
    if(root->left!=NULL)
        helper(res,val,sum,root->left,max);
    if(root->right!=NULL)
        helper(res,val,sum,root->right,max);
    return 0;
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> val;
        set<vector<int>> mul;
        if(root==NULL)
        {
            return res;
        }
        helper(res,val,sum,root,0);
        return res;
    }
};
