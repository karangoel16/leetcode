/*
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (37.66%)
 * Total Accepted:    11.6K
 * Total Submissions: 30.8K
 * Testcase Example:  '[2,1,1]'
 *
 * 
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them. 
 * 
 * 
 * Two trees are duplicate if they have the same structure with same node
 * values.
 * 
 * 
 * Example 1: 
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * The following are two duplicate subtrees:
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * and
 * 
 * ⁠   4
 * 
 * Therefore, you need to return above trees' root in the form of a list.
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
public:
    string helper(TreeNode *root,unordered_map<string,int> & mp,vector<TreeNode *> &res)
    {
        if(root==NULL)
        {
            return "#";
        }
        string val=to_string(root->val)+helper(root->right,mp,res)+helper(root->left,mp,res);
        if(mp.find(val)!=mp.end() && mp[val]==1)
        {
            res.push_back(root);
        }
        mp[val]+=1;
        return val;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> res;
        unordered_map<string,int> mp;
        helper(root,mp,res);
        return res;
    }
};
