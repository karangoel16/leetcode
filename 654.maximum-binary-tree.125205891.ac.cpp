/*
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (69.69%)
 * Total Accepted:    26.4K
 * Total Submissions: 37.9K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 * 
 * The root is the maximum number in the array. 
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number. 
 * 
 * 
 * 
 * 
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 * 
 * 
 * Example 1:
 * 
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * Note:
 * 
 * The size of the given array will be in the range [1,1000].
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode *> st;
        TreeNode *head;
        int i=0;
        while(i<nums.size())
        {
            TreeNode *temp=new TreeNode(nums[i]);
            TreeNode *temp2=NULL;
            while(!st.empty() && st.top()->val<temp->val)
            {
                temp2=st.top();
                //std::cout<<temp2->val<<"\n";
                st.pop();
            }
            if(st.empty())
            {
                head=temp;
                head->left=temp2;
                st=stack<TreeNode *>();
                st.push(head);
                //std::cout<<head->val<<"\n";
            }
            else
            {
                st.top()->right=temp;
                temp->left=temp2;
                st.push(temp);
            }
            i++;
        }
        return head;
    }
};
