/*
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (26.62%)
 * Total Accepted:    108.5K
 * Total Submissions: 407.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 
 * You must do this in-place without altering the nodes' values.
 * 
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
int countList(ListNode *head){
    int temp=0;
    while(head!=NULL)
    {
        temp++;
        head=head->next;
    }
    return temp;
}
ListNode * reverseList(ListNode *head)
{
    ListNode *end=NULL;
    while(head!=NULL)
    {
        ListNode *temp=head;
        head=head->next;
        temp->next=end;
        end=temp;
    }
    return end;
}
class Solution {
public:
    void reorderList(ListNode* head) {
        int count=countList(head);
        if(!count || count==1)
        {
            return ;
        }
        int br=count%2==0?count/2:(count+1)/2;
        ListNode* pos=head;
        int val=0;
        while(val<br)
        {
            pos=pos->next;
            val++;
        }
        //std::cout<<pos->val;
        pos=reverseList(pos);
        ListNode *temp=head;
        while(pos!=NULL)
        {
            ListNode *temp2=temp->next;
            temp->next=pos;
            ListNode *temp3=pos->next;
            pos->next=temp2;
            pos=temp3;
            temp=temp2;
        }
        temp->next=NULL;
        return;
    }
};
