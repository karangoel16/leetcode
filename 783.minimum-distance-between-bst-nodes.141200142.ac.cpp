/*
 * [799] Minimum Distance Between BST Nodes
 *
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (46.86%)
 * Total Accepted:    4.9K
 * Total Submissions: 10.5K
 * Testcase Example:  '[4,2,6,1,3,null,null]'
 *
 * Given a Binary Search Tree (BST) with the root node root, return the minimum
 * difference between the values of any two different nodes in the tree.
 * 
 * Example :
 * 
 * 
 * Input: root = [4,2,6,1,3,null,null]
 * Output: 1
 * Explanation:
 * Note that root is a TreeNode object, not an array.
 * 
 * The given tree [4,2,6,1,3,null,null] is represented by the following
 * diagram:
 * 
 * ⁠         4
 * ⁠       /   \
 * ⁠     2      6
 * ⁠    / \    
 * ⁠   1   3  
 * 
 * while the minimum difference in this tree is 1, it occurs between node 1 and
 * node 2, also between node 3 and node 2.
 * 
 * 
 * Note:
 * 
 * 
 * The size of the BST will be between 2 and 100.
 * The BST is always valid, each node's value is an integer, and each node's
 * value is different.
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
    int min;
    TreeNode *previous;
    stack<TreeNode *> st;
public:
    Solution(){
        min=INT_MAX;
        previous=NULL;
    }
    void left(TreeNode *root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        return ;
    }
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
            return 0;
        left(root);
        while(!st.empty()){
            if(previous!=NULL)
                min=std::min(min,st.top()->val-previous->val);
            previous=st.top();
            st.pop();
            left(previous->right);
        }
        return min;
    }
};
