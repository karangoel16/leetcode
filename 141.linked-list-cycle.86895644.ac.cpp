/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (35.12%)
 * Total Accepted:    236.3K
 * Total Submissions: 672.6K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
       if(head==NULL)
       {
           return false;
       }
       if(head->next==NULL)
       {
           return false;
       }
       ListNode *temp=head;
       ListNode *temp1=head->next;
       while(temp1!=NULL && temp!=NULL && temp1->next!=NULL)
       {
           if(temp1==temp)
           {
               return true;
           }
           temp=temp->next;
           temp1=temp1->next->next;
       }
       return false;
    }
};
