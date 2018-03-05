/*
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (42.27%)
 * Total Accepted:    103.1K
 * Total Submissions: 244K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * 
 * For example:
 * Given the following binary tree,
 * 
 * ⁠  1            
 * 
 * 
 * You should return [1, 3, 4].
 * 
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
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
    vector <int>temp;
public:
    vector<int> rightSideView(TreeNode* root,int i=0)
        {
            if(root==NULL)
            {
                return temp;
            }
            if(i==temp.size())
            {
                temp.push_back(root->val);
            }
            rightSideView(root->right,i+1);
            rightSideView(root->left,i+1);
            return temp;
        }
};
