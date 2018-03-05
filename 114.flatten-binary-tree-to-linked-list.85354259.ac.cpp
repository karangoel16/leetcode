/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (36.33%)
 * Total Accepted:    157.7K
 * Total Submissions: 434.2K
 * Testcase Example:  '[]'
 *
 * 
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * 
 * 
 * For example,
 * Given
 * 
 * ⁠        1
 * ⁠       / \
 * ⁠      2   5
 * ⁠     / \   \
 * ⁠    3   4   6
 * 
 * 
 * 
 * The flattened tree should look like:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠     \
 * ⁠      3
 * ⁠       \
 * ⁠        4
 * ⁠         \
 * ⁠          5
 * ⁠           \
 * ⁠            6
 * 
 * 
 * click to show hints.
 * 
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child
 * points to the next node of a pre-order traversal.
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
    void flatten(TreeNode* root) {
        TreeNode *temp=root;
        while(temp!=NULL)
        {
            TreeNode *right=temp->right;
            temp->right=temp->left;
            temp->left=NULL;
            TreeNode *test=temp->right;
            if(test==NULL)
            {
                temp->right=right;
            }
            else
            {
                while(test!=NULL && test->right!=NULL)test=test->right;
                test->right=right;
            }
            temp=temp->right;
        }
    }
};
