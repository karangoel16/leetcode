/*
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (51.91%)
 * Total Accepted:    9.9K
 * Total Submissions: 19.1K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * 
 * Implement a MapSum class with insert, and sum methods.
 * 
 * 
 * 
 * For the method insert, you'll be given a pair of (string, integer). The
 * string represents the key and the integer represents the value. If the key
 * already existed, then the original key-value pair will be overridden to the
 * new one.
 * 
 * 
 * 
 * For the method sum, you'll be given a string representing the prefix, and
 * you need to return the sum of all the pairs' value whose key starts with the
 * prefix.
 * 
 * 
 * Example 1:
 * 
 * Input: insert("apple", 3), Output: Null
 * Input: sum("ap"), Output: 3
 * Input: insert("app", 2), Output: Null
 * Input: sum("ap"), Output: 5
 * 
 * 
 * 
 */
struct node{
    unordered_map<char,node *> mp;
    int val;
    node(){
        val=0;
    }
};

class MapSum {
    node *head;
public:
    /** Initialize your data structure here. */
    MapSum() {
        head =new node();
    }
    
    void insert(string key, int val) {
        node *temp=head;
        for(auto i:key)
        {
            if(temp->mp.find(i)==temp->mp.end())
            {
                temp->mp[i]=new node();
            }
            temp=temp->mp[i];
        }
        temp->val=val;
    }
    int helper(node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int sum=root->val;
        for(auto i:root->mp)
        {
            sum+=helper(i.second);
        }
        return sum;
    }
    int sum(string prefix) {
        node *temp=head;
        for(auto i:prefix)
        {
            if(temp->mp.find(i)==temp->mp.end())
            {
                return 0;
            }
            temp=temp->mp[i];
        }
        return helper(temp);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
