/*
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (37.59%)
 * Total Accepted:    130.9K
 * Total Submissions: 348.4K
 * Testcase Example:  '[]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * For example,
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 
 * 
 * 
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * 
 * 
 * Return the sum = 12 + 13 = 25.
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
    int result;
    //unordered_set<TreeNode *> st;
public:
    Solution()
    {
        result=0;
    }
    void helper(TreeNode *root,string val)
    {
        //std::cout<<val<<"**";
        if(root==NULL)
        {
            return;
        }
        char suffix=root->val+48;
        //std::cout<<"\n&"<<suffix;
        if(root->left==NULL && root->right==NULL)
        {
            string p=val+suffix;
            result+=atoi(p.c_str());
            //std::cout<<result;
            return ;
        }
        helper(root->left,val+suffix);
        helper(root->right,val+suffix);
    }
    int sumNumbers(TreeNode* root) {
        helper(root,"");
        return result;
    }
};
