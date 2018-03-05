/*
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (35.41%)
 * Total Accepted:    127.3K
 * Total Submissions: 359.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
int count(ListNode *head)
{
    ListNode *temp=head;
    int co=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        co++;
    }
    return co;
}
ListNode * helper1(ListNode *head,int n)
{
    int i=0;
    ListNode *temp=head;
    while(temp!=NULL && i<n)
    {
        temp=temp->next;
        i++;
    }
    return temp;
}

TreeNode * helper(ListNode *head,int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    int mid=(high+low)/2;
    TreeNode *root;
    ListNode *temp=helper1(head,mid-low);
    if(temp!=NULL)
    {
        //std::cout<<temp->val<<"\n";
        root=new TreeNode(temp->val);
        root->left=helper(head,low,mid-1);
        root->right=helper(temp->next,mid+1,high);
    }
    return root;
}
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n=count(head);
        if(n==0)
        {
            return NULL;
        }
        return helper(head,0,n-1);
    }
};
