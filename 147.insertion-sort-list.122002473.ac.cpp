/*
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (33.73%)
 * Total Accepted:    115.9K
 * Total Submissions: 343.5K
 * Testcase Example:  '[]'
 *
 * Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        for(ListNode *i=head;i!=NULL && i->next!=NULL;i=i->next)
        {
            for(ListNode *j=i->next;j!=NULL;j=j->next)
            {
                if(i->val>j->val)
                {
                    std::swap(i->val,j->val);
                }
            }
        }
        return head;
    }
};
