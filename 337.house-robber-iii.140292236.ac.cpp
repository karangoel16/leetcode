/*
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (44.53%)
 * Total Accepted:    60.5K
 * Total Submissions: 135.8K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * 
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * 
 * Example 1:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * 
 * Example 2:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
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
    pair<int,int> helper(TreeNode *root){
        if(!root) return make_pair(0,0);
        pair<int,int> left=helper(root->left);
        pair<int,int> right=helper(root->right);
        pair<int,int> res=make_pair(0,0);
        res.first = left.second + right.second +root->val;
        res.second = std::max(left.first,left.second)+std::max(right.first,right.second);
        return res;
    }
    int rob(TreeNode* root) {
        pair<int,int> res = helper(root);
        return std::max(res.first,res.second);
    }
};
