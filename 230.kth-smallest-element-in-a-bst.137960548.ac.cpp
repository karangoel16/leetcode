/*
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (45.12%)
 * Total Accepted:    132.8K
 * Total Submissions: 294.4K
 * Testcase Example:  '[1]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
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
    stack<TreeNode *> st;
public:
    void populate(TreeNode *temp)
    {
        while(temp!=NULL)
        {
            st.push(temp);
            temp=temp->left;
        }
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        populate(root);
        TreeNode * temp;
        while(k--)
        {
            temp=st.top();
            //std::cout<<st.top()->val<<"\n";
            st.pop();
            populate(temp->right);
        }
        return temp->val;
    }
};
