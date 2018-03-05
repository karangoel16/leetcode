/*
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (55.33%)
 * Total Accepted:    35K
 * Total Submissions: 63.2K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
 * 
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        vector<int> res;
        queue<TreeNode *>que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            int max=INT_MIN;
            while(size--){
                max=std::max(max,que.front()->val);
                TreeNode *temp=que.front();
                if(temp->left!=NULL)
                  que.push(temp->left);
                if(temp->right!=NULL)
                    que.push(temp->right);
                que.pop();
            }
            res.push_back(max);
        }
        return res;
    }
};
