/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.90%)
 * Total Accepted:    147.6K
 * Total Submissions: 569.7K
 * Testcase Example:  '{}'
 *
 * 
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * 
 * 
 * Return a deep copy of the list.
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *temp=head;
        unordered_map<int,RandomListNode *>map_;
        RandomListNode *start=new RandomListNode(100);
        RandomListNode *end=start;
        while(temp!=NULL)
        {
            end->next=new RandomListNode(temp->label);
            end=end->next;
            map_[temp->label]=end;
            temp=temp->next;
        }
        temp=head;
        RandomListNode *temp1=start->next;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
                temp1->random=map_[temp->random->label];
            temp=temp->next;
            temp1=temp1->next;
        }
        return start->next;
    }
};
