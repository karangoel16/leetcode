/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (33.27%)
 * Total Accepted:    145.6K
 * Total Submissions: 437.7K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
        {
            return NULL;
        }
        while(head!=NULL && head->val==val)
        {
            ListNode *temp=head;
            head=head->next;
            delete temp;//this is done to remove the temp
        }
        if(head==NULL)
        {
            return head;
        }
        ListNode *temp=head;
        while(temp!=NULL && temp->next!=NULL)
        {
            while( temp->next!=NULL && temp->next->val==val)
            {
                ListNode *temp1=temp->next;
                temp->next=temp1->next;
                delete temp1;
            }
            temp=temp->next;
        }
        return head;
    }
};
