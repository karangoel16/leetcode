/*
 * [655] Print Binary Tree
 *
 * https://leetcode.com/problems/print-binary-tree/description/
 *
 * algorithms
 * Medium (49.52%)
 * Total Accepted:    8K
 * Total Submissions: 16.2K
 * Testcase Example:  '[1,2]'
 *
 * Print a binary tree in an m*n 2D string array following these rules: 
 * 
 * 
 * The row number m should be equal to the height of the given binary tree.
 * The column number n should always be an odd number.
 * The root node's value (in string format) should be put in the exactly middle
 * of the first row it can be put. The column and the row where the root node
 * belongs will separate the rest space into two parts (left-bottom part and
 * right-bottom part). You should print the left subtree in the left-bottom
 * part and print the right subtree in the right-bottom part. The left-bottom
 * part and the right-bottom part should have the same size. Even if one
 * subtree is none while the other is not, you don't need to print anything for
 * the none subtree but still need to leave the space as large as that for the
 * other subtree. However, if two subtrees are none, then you don't need to
 * leave space for both of them. 
 * Each unused space should contain an empty string "".
 * Print the subtrees following the same rules.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * ⁠    1
 * ⁠   /
 * ⁠  2
 * Output:
 * [["", "1", ""],
 * ⁠["2", "", ""]]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * ⁠    1
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \
 * ⁠    4
 * Output:
 * [["", "", "", "1", "", "", ""],
 * ⁠["", "2", "", "", "", "3", ""],
 * ⁠["", "", "4", "", "", "", ""]]
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * ⁠     1
 * ⁠    / \
 * ⁠   2   5
 * ⁠  / 
 * ⁠ 3 
 * ⁠/ 
 * 4 
 * Output:
 * 
 * [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 * ⁠["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 * ⁠["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 * ⁠["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 * 
 * 
 * 
 * Note:
 * The height of binary tree is in the range of [1, 10].
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
    int hei(TreeNode *root){
        if(!root)
            return 0;
        int left=hei(root->left);
        int right=hei(root->right);
        return std::max(left,right)+1;
    }
    int wid(TreeNode *root){
        if(!root)
            return 0;
        return std::max(wid(root->left),wid(root->right))*2+1;  
    }
    void helper(vector<vector<string>> &res,int low,int high,TreeNode *root,int height){
        if(low>high || root==NULL)
            return ;
        int mid=(low+high)/2;
        res[height][mid]=to_string(root->val);
        helper(res,low,mid-1,root->left,height+1);
        helper(res,mid+1,high,root->right,height+1);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height=hei(root);
        int width=wid(root);
        vector<vector<string>> res(height,vector<string>(width,""));
        helper(res,0,width,root,0);
        return res;
    }
};
