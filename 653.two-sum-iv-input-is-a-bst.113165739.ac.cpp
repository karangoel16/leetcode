/*
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (50.14%)
 * Total Accepted:    33K
 * Total Submissions: 65.9K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
 * 
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
class Solution {
    unordered_map<int,int> mp;
public:
    void helper(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        mp[root->val]++;
        helper(root->left);
        helper(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        {
            return false;
        }
        helper(root);
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(((mp[it->first]==2)&&((k/(it->first)*(it->first)==k)))||(mp.find(k-it->first)!=mp.end()&&(k-it->first!=it->first)))
            {
                return true;
            }
        }
        return false;
    }
};
