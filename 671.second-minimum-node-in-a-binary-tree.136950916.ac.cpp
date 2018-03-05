/*
 * [671] Second Minimum Node In a Binary Tree
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (41.82%)
 * Total Accepted:    20K
 * Total Submissions: 47.7K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or zero
 * sub-node. If the node has two sub-nodes, then this node's value is the
 * smaller value among its two sub-nodes. 
 * 
 * 
 * 
 * Given such a binary tree, you need to output the second minimum value in the
 * set made of all the nodes' value in the whole tree. 
 * 
 * 
 * 
 * If no such second minimum value exists, output -1 instead.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest
 * value.
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
    int first_min;
    int sec_min;
public:
    void helper(TreeNode *root)
    {
        if(!root || ((root->left) && (root->right==NULL)))
            return ;
        if(root->val<first_min)
        {
            std::swap(first_min,sec_min);
            first_min=root->val;
        }
        else if(root->val>first_min && root->val<sec_min)
            sec_min=root->val;
        helper(root->right);
        helper(root->left);
    }
    int findSecondMinimumValue(TreeNode* root) {
        sec_min=INT_MAX;
        first_min=INT_MAX;
        helper(root);
        return sec_min==INT_MAX?-1:sec_min;
    }
};
