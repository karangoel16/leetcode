/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (40.63%)
 * Total Accepted:    318.5K
 * Total Submissions: 783.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(100);
        ListNode *end=head;
        while(l1 && l2){
            int temp;
            if(l1->val>l2->val){
                temp=l2->val;
                l2=l2->next;
            }
            else{
                temp=l1->val;
                l1=l1->next;
            }
            end->next=new ListNode(temp);
            end=end->next;
        }
        while(!(!l1 && !l2)){
            int temp;
            if(l2!=NULL){
                temp=l2->val;
                l2=l2->next;
            }
            if(l1!=NULL){
                temp=l1->val;
                l1=l1->next;
            }
            end->next=new ListNode(temp);
            end=end->next;
        }
        return head->next;
    }
};
