/*
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (44.61%)
 * Total Accepted:    88.3K
 * Total Submissions: 197.9K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * 
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 * 
 * 
 * Note:
 * The relative order inside both the even and odd groups should remain as it
 * was in the input. 
 * The first node is considered odd, the second node even and so on ...
 * 
 * 
 * Credits:Special thanks to @DjangoUnchained for adding this problem and
 * creating all test cases.
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *temp=head;
        ListNode *start=new ListNode(1);
        ListNode *end=start;
        ListNode *start_even=new ListNode(2);
        ListNode *end_even=start_even;
        int i=1;
        while(temp!=NULL)
        {
            if(i%2==1)
            {
                end->next=temp;
                temp=temp->next;
                end=end->next;
                end->next=NULL;
            }
            else if(i%2==0)
            {
                end_even->next=temp;
                temp=temp->next;
                end_even=end_even->next;
                end_even->next=NULL;
            }
            i++;
        }
        end->next=start_even->next;
        return start->next;
    }
};
