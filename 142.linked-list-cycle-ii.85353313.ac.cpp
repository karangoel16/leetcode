/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.68%)
 * Total Accepted:    140.3K
 * Total Submissions: 457.4K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
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
    ListNode *detectCycle(ListNode *head) {
       set<ListNode *>set_;
       if(head==NULL)
       {
           return NULL;
       }
       if(head->next==NULL)
       {
           return NULL;
       }
       ListNode *temp=head;
       while(temp!=NULL)
       {
           auto res=set_.insert(temp);
           if(res.second==false)
           {
               return temp;
           }
           temp=temp->next;
       }
       return NULL;
    }
};
