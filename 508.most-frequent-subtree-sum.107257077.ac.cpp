/*
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (52.29%)
 * Total Accepted:    27.7K
 * Total Submissions: 53K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
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
    unordered_map<int,int>mp;
public:
    int helper(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=helper(root->left);
        int right=helper(root->right);
        int sum=left+right+root->val;
        if(mp.find(sum)!=mp.end())
        {
            mp[sum]++;
        }
        else
        {
            mp[sum]=1;
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        std::vector<int>res;
        int max=INT_MIN;
        for(auto i:mp)
        {
            //std::cout<<i.first<<" "<<i.second<<"\n";
            if(max<i.second)
            {
                max=i.second;
            }
        }
        for(auto i:mp)
        {
            if(i.second==max)
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
