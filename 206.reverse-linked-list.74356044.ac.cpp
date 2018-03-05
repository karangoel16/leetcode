/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (46.63%)
 * Total Accepted:    322.2K
 * Total Submissions: 691.1K
 * Testcase Example:  '[]'
 *
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        if(head->next==NULL)
        {
            return head;
        }
        ListNode *temp=head;
        ListNode *rev=NULL;
        while(temp!=NULL)
        {
            //std::cout<<"*";
            if(rev==NULL)
            {
                rev=(struct ListNode *)malloc(sizeof(ListNode));
                rev->next=NULL;
                rev->val=temp->val;
                //std::cout<<rev->val;
                //return rev;
            }
            else
            {
                struct ListNode *temp_add=(struct ListNode *)malloc(sizeof(ListNode));
                temp_add->next=rev;
                temp_add->val=temp->val;
                rev=temp_add;
            }
            temp=temp->next;
        }
        return rev;
        
    }
};
