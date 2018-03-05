/*
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (37.61%)
 * Total Accepted:    31K
 * Total Submissions: 82.4K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * return [2].
 * 
 * 
 * Note:
 * If a tree has more than one mode, you can return them in any order.
 * 
 * 
 * Follow up:
 * Could you do that without using any extra space? (Assume that the implicit
 * stack space incurred due to recursion does not count).
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
int helper(stack<TreeNode *> &st,TreeNode *root,int val)
{
    if(root==NULL)
    {
        return 0;
    }
    int temp=((root->val)==val)+helper(st,root->left,val)+helper(st,root->right,val);
    if(root->val!=val)
    {
        st.push(root);
    }
    return temp;
}
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_set<int> res1;
        if(root==NULL)
        {
            return res;
        }
        int mode=0;
        stack<TreeNode *>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *temp=st.top();
            st.pop();
            if(res1.find(temp->val)!=res1.end())
            {
                continue;
            }
            int temp_mode=helper(st,temp,temp->val);
            res1.insert(temp->val);
            //std::cout<<temp->val<<" "<<temp_mode<<"\n";
            if(temp_mode>mode)
            {
                //res.clear();
                vector<int> temp1{temp->val};
                res=temp1;
                mode=temp_mode;
            }
            else if(temp_mode==mode)
            {
                res.push_back(temp->val);
            }
        }
        //std::copy(res1.begin(),res1.end(),res.begin());
        return res;
    }
};
