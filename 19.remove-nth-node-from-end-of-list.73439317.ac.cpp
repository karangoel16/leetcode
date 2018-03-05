/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.08%)
 * Total Accepted:    231.4K
 * Total Submissions: 679K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 * 
 * For example,
 * 
 * 
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        if(n==1 &&temp->next==NULL)
        {
            free(head);
            return NULL;   
        }
        while(temp!=NULL)
        {
            ListNode *temp1=temp;
            int x=n+1;
            while(x--!=0)
            {
                temp1=temp1->next;
                if(temp1==NULL && x!=0)
                {
                    temp1=head->next;
                    free(head);
                    return temp1;
                }
            }
            if(temp1==NULL)
            {
                temp1=temp->next;
                temp->next=temp1->next;
                free(temp1);
                return head;
            }
            temp=temp->next;
        }
        return head;
    }
};
