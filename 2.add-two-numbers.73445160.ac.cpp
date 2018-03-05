/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.49%)
 * Total Accepted:    450.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/*struct ListNode {
      int val;
      ListNode *next;
     };*/
int add(ListNode *temp,int val1,int val2,int carry);
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        ListNode *temp3=(struct ListNode *)malloc(sizeof(ListNode));
        temp3->val=-1;
        temp3->next=NULL;
        int carry=0;
        int k;
        while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1!=NULL && temp2!=NULL)
            {
                k=add(temp3,temp1->val,temp2->val,carry);
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1==NULL)
            {
                 k=add(temp3,0,temp2->val,carry);
                 temp2=temp2->next;
            }
            else
            {
                k=add(temp3,temp1->val,0,carry);
                temp1=temp1->next;
            }
            carry=k;
        }
        if(carry!=0)
        {
            k=add(temp3,0,0,carry);
        }
        return temp3;
    }
};

int add(ListNode * temp,int val1,int val2,int carry)
{
    int add=val1+val2+carry;
    if(temp->val==-1)
    {
        temp->val=(add%10);
        temp->next=NULL;
        return add/10;
    }
    ListNode *temp1=temp;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=(struct ListNode *)malloc(sizeof(ListNode));
    temp1=temp1->next;
    temp1->val=(add%10);
    temp1->next=NULL;
    return add/10;
}
