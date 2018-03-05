/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (28.04%)
 * Total Accepted:    206.4K
 * Total Submissions: 736.1K
 * Testcase Example:  '[]'
 *
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
#define ipair pair<int,ListNode *>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp=[](ListNode * a, ListNode * b){
            return a->val > b-> val;
        };
        priority_queue<ListNode *,vector<ListNode *>,decltype(comp)> pq(comp);
        ListNode *head=new ListNode(100);
        ListNode *end=head;
        for(int i=0;i<lists.size();i++)
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        while(!pq.empty()){
            auto temp=pq.top();
            end->next=new ListNode(temp->val);
            end=end->next;
            pq.pop();
            if(temp->next!=NULL){
                pq.push(temp->next);
            }
        }
        return head->next;
    }
};
