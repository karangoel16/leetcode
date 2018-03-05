/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (31.27%)
 * Total Accepted:    133.3K
 * Total Submissions: 426.2K
 * Testcase Example:  '[5]\n1\n1'
 *
 * 
 * Reverse a linked list from position m to n. Do it in-place and in
 * one-pass.
 * 
 * 
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
void reverse(ListNode *start,ListNode *end);
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL)
        {
            return head;
        }
        if(head->next==NULL)
        {
            return head;
        }
        ListNode *start;
        ListNode *end;
        ListNode *temp=head;
        int i=1;
        while(i<=n && temp!=NULL)
        {
           if(i==m)
           {
               start=temp;
           }
           if(i==n)
           {
               end=temp;
           }
           temp=temp->next; 
           ++i;
        }
        reverse(start,end);
        return head;
        
    }
};
void reverse(ListNode *start,ListNode *end)
{
    if(start==NULL)
    {}
    struct ListNode *temp=start;
    struct ListNode *rev=NULL;
    while(temp!=end->next)
    {
        if(rev==NULL)
        {
            rev=(struct ListNode *)malloc(sizeof(ListNode));
            rev->next=NULL;
            rev->val=temp->val;
            //std::cout<<rev->val<<"\n";
        }
        else
        {
            struct ListNode *temp_add=(struct ListNode *)malloc(sizeof(ListNode));
            temp_add->val=temp->val;
            temp_add->next=rev;
            rev=temp_add;
            //std::cout<<rev->val<<"\n";
        }
        temp=temp->next;
    }
    temp=start;
    while(temp!=end->next)
    {
        temp->val=rev->val;
        temp=temp->next;
        rev=rev->next;
    }
}

