/*
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (35.06%)
 * Total Accepted:    44.2K
 * Total Submissions: 126K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 
 * You are given an integer array nums and you have to return a new counts
 * array.
 * The counts array has the property where counts[i] is 
 * the number of smaller elements to the right of nums[i].
 * 
 * 
 * Example:
 * 
 * 
 * Given nums = [5, 2, 6, 1]
 * 
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 * 
 * 
 * Return the array [2, 1, 1, 0].
 * 
 */
struct tree{
    int left_size;
    int common_size;
    int val;
    tree *left;
    tree *right;
    tree(){
        left_size=0;
        common_size=1;
        left=NULL;
        right=NULL;
    }
};
class trie{
    struct tree *head;
    public:
    trie()
    {
        head=new tree();
        head->val=INT_MAX;
    }
    int add(int n)
    {
        tree *temp=head;
        int res=0;
        while(true)
        {
            if(temp->val==n)
            {
                res+=temp->left_size;
                temp->common_size++;
                return res;
            }
            if(temp->val>n)
            {
                temp->left_size++;
                if(temp->left==NULL)
                {
                 	temp->left=new tree();
                    temp->left->val=n;
                    return res;
                }
                temp=temp->left;
            }
            else if(temp->val<n)
            {
                res+=temp->left_size+temp->common_size;
                if(temp->right==NULL)
                {
                    temp->right=new tree();
                    temp->right->val=n;
                    return res;
                }
                temp=temp->right;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        trie t;
        vector<int>res;
        for(int i=nums.size()-1;i>=0;--i)
        {
           res.push_back(t.add(nums[i]));
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};
