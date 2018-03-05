/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.40%)
 * Total Accepted:    147.9K
 * Total Submissions: 442.8K
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
        {
            return true;
        }
        if(head->next==NULL)
        {
            return true;
        }
        ListNode *slow_temp=head;
        ListNode *fast_temp=slow_temp->next->next;
        while(fast_temp!=NULL && fast_temp->next!=NULL && slow_temp!=NULL)
        {
            fast_temp=fast_temp->next->next;
            slow_temp=slow_temp->next;
        }
        ListNode *temp;
        if(fast_temp!=NULL)
         temp=slow_temp->next->next;
        else
         temp=slow_temp->next;
         slow_temp->next=NULL;
         struct ListNode *temp1;;
        while(temp!=NULL)
        {
            if(temp1==NULL)
            {
                temp1=(struct ListNode *)malloc(sizeof(ListNode));
                temp1->next=NULL;
                temp1->val=temp->val;
            }
            else
            {
                ListNode *temp_add=(struct ListNode *)malloc(sizeof(ListNode));
                temp_add->next=temp1;
                temp_add->val=temp->val;
                temp1=temp_add;
            }
            temp=temp->next;
           
        }
        slow_temp=head;
        while(slow_temp!=NULL && temp1!=NULL)
        {
            if(slow_temp->val != temp1->val)
            {
                return false;
            }
            temp1=temp1->next;
            slow_temp=slow_temp->next;
        }
        //std::cout<<temp1->val;
        
        return true;
    }
};
