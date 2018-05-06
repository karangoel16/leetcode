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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(INT_MAX);
        ListNode *end=head;
        int carry=0;
        while(l1 || l2){
            int val=0;
            if(l1)
                val+=l1->val;
            if(l2)
                val+=l2->val;
            end->next=new ListNode((val+carry)%10);
            carry=(val+carry)/10;
            end=end->next;
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
        }
        if(carry)
            end->next=new ListNode(carry);
        return head->next;
    }
};
