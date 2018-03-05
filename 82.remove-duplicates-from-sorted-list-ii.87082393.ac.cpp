/*
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (29.90%)
 * Total Accepted:    129.3K
 * Total Submissions: 432.4K
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> mul;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            if(mul.find(temp->val)!=mul.end())
            {
                mul[temp->val]++;
            }
            else
            {
                mul[temp->val]=1;
            }
            temp=temp->next;
        }
        while(head!=NULL && mul[head->val]!=1)
        {
            ListNode *del=head;
            head=head->next;
            delete del;
        }
        temp=head;
        while(temp!=NULL && temp->next!=NULL && temp->next->next!=NULL)
        {
            if(mul[temp->next->val]!=1)
            {
                ListNode *del=temp->next;
                temp->next=del->next;
                delete del;//this is to delete the element
            }
            else
            {
                temp=temp->next;
            }
        }
        if(temp!=NULL && temp->next!=NULL && mul[temp->next->val]!=1)
        {
            ListNode *del=temp->next;
            temp->next=NULL;
            delete del;
        }
        return head;
    }
};
