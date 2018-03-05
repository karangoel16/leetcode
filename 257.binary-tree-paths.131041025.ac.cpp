/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (40.84%)
 * Total Accepted:    149.4K
 * Total Submissions: 365.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * 
 * For example, given the following binary tree:
 * 
 * 
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
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
    vector<string> val;
public:
    void helper(TreeNode *root,string temp)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left==NULL && root->right==NULL)
        {
            temp+=(temp.length()?"->":"")+to_string(root->val);
            val.push_back(temp);
        }
        helper(root->left,temp.length()==0?to_string(root->val):(temp+"->"+to_string(root->val)));
        helper(root->right,temp.length()==0?to_string(root->val):(temp+"->"+to_string(root->val)));
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        //vector<string> val;
        if(root==NULL)
        {
            return val;
        }
        string temp="";
        helper(root,temp);
        return val;
    }
};
