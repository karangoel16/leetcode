/*
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (29.71%)
 * Total Accepted:    127.4K
 * Total Submissions: 428.7K
 * Testcase Example:  '[]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *merge(ListNode *headA,ListNode *headB){
        ListNode *d=new ListNode(100);
        ListNode *e=d;
        while(headA || headB){
            if(headA && (!headB || headA->val<=headB->val)){
                e=e->next=headA;
                headA=headA->next;
            }
            if(headB && (!headA || headA->val> headB->val)){
                e=e->next=headB;
                headB=headB->next;
            }
        }
        e->next=NULL;
        ListNode *temp=d->next;
        delete d;
        return temp;
    }
    ListNode* sortList(ListNode* head) {
         if(!head || !head->next) return head;
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *headB=slow->next;
        slow->next=NULL;
        return merge(sortList(head),sortList(headB));
    }
};
