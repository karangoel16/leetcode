/*
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (46.15%)
 * Total Accepted:    44.5K
 * Total Submissions: 96.3K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    int count(ListNode *node){
        int count=0;
        while(node){
            count++;
            node=node->next;
        }
        return count;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st;
        int n1=count(l1),n2=count(l2),tmp=std::max(n1,n2);
        for(ListNode *temp1=l1,*temp2=l2;tmp;tmp--){
            int a=0,b=0;
            if(n1>n2){
                a=temp1->val;
                temp1=temp1->next;
                n1--;
            }
            else if(n2>n1){
                b=temp2->val;
                temp2=temp2->next;
                n2--;
            }
            else{
                a=temp1->val;
                temp1=temp1->next;
                b=temp2->val;
                temp2=temp2->next;
                n1--;
                n2--;
            }
            st.push(a+b);
            //std::cout<<a+b<<"\n";
        }
        ListNode *head=NULL;
        int c=0;
        while(!st.empty()){
            ListNode *temp=new ListNode((st.top()+c)%10);
            temp->next=head;
            c=(st.top()+c)/10;
            head=temp;
            st.pop();  
        }
        if(c){
            ListNode *temp=new ListNode(c);
            temp->next=head;
            head=temp;
        }
        return head;
    }
};
