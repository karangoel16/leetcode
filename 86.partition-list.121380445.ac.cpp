/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (33.37%)
 * Total Accepted:    118.8K
 * Total Submissions: 356K
 * Testcase Example:  '[]\n0'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode *head, *end;
public:
    Solution()
    {
        head=new ListNode(100);
        end=head;
    }
    ListNode* partition(ListNode* h, int x) {
        while(h!=NULL && h->val>=x)
        {
            ListNode *temp=h;
            h=h->next;
            end->next=temp;
        end=end->next;
        temp->next=NULL;
        }
        ListNode *temp1=h;
        while(temp1!=NULL && temp1->next!=NULL)
        {
            if(temp1->next->val>=x)
            {
                ListNode *temp=temp1->next;
                temp1->next=temp1->next->next;
            end->next=temp;
        end=end->next;
        temp->next=NULL;
            }
            else{
                temp1=temp1->next;
            }
        }
        if(h==NULL)
        {
            return head->next;
        }
        temp1->next=head->next;
        return h;
    }
};
