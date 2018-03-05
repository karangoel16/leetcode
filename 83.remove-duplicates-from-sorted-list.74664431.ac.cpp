/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (40.19%)
 * Total Accepted:    224.9K
 * Total Submissions: 559.7K
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        ListNode *temp=head;
        while(temp!=NULL)
        {
            while(temp->next!=NULL && temp!=NULL && temp->val==temp->next->val)
            {
                struct ListNode *t=temp->next;
                temp->next=t->next;
                free(t);
            }
            temp=temp->next;
        }
        return head;
        
    }
};
