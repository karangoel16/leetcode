/*
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (33.92%)
 * Total Accepted:    123.5K
 * Total Submissions: 364K
 * Testcase Example:  '{}'
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 * What if the given tree could be any binary tree? Would your previous
 * solution still work?
 * 
 * Note:
 * You may only use constant extra space.
 * 
 * 
 * For example,
 * Given the following binary tree,
 * 
 * ⁠        1
 * ⁠      /  \
 * ⁠     2    3
 * ⁠    / \    \
 * ⁠   4   5    7
 * 
 * 
 * 
 * After calling your function, the tree should look like:
 * 
 * ⁠        1 -> NULL
 * ⁠      /  \
 * ⁠     2 -> 3 -> NULL
 * ⁠    / \    \
 * ⁠   4-> 5 -> 7 -> NULL
 * 
 * 
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return ;
        queue<TreeLinkNode *> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            while(size){
                TreeLinkNode *temp1=que.front();
                que.pop();
                if(temp1->left!=NULL)
                    que.push(temp1->left);
                if(temp1->right!=NULL)
                    que.push(temp1->right);               
                size--;
                if(size>0){
                    temp1->next=que.front();
                }
            }
        }
    }
};
