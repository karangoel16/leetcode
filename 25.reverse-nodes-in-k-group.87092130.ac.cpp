/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (31.39%)
 * Total Accepted:    119.7K
 * Total Submissions: 381.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be
 * changed.
 * 
 * Only constant memory is allowed.
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
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
int count(ListNode *head)
{
    int co=0;
    ListNode *temp=head;//this is temparary variable
    while(temp!=NULL)
    {
        co++;
        temp=temp->next;
    }
    return co;
}
ListNode *helper(ListNode *head,int co,int k)
{
    if(co<k)
    {
        return head;
    }
    int flag=1;
    ListNode *temp1=head;
    ListNode *end_start=NULL;
    while(co>=k)
    {
        ListNode *start=NULL;
        ListNode *end=NULL;
        int i=0;
        while(i<k)
        {
            if(start==NULL)
            {
                start=temp1;
                end=temp1;
                temp1=temp1->next;
                start->next=NULL;
            }
            else
            {
                ListNode *temp=start;
                start=temp1;
                temp1=temp1->next;
                start->next=temp;
            }
            i++;//this is to increase the element
            //std::cout<<"*";
        }
        if(flag==1)
        {
            head=start;//this is done to add head
            end_start=end;
            flag=0;
        }
        else
        {
            end_start->next=start;
            end_start=end;
        }
        //std::cout<<temp1->val<<"\n";
        co=co-k;
    }
    //std::cout<<"*";
    end_start->next=temp1;
    return head;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int co=count(head);
        if(co<k)
        {
            return head;
        }
        return helper(head,co,k);
    }
};
