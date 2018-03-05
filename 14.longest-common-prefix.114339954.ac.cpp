/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.63%)
 * Total Accepted:    251.3K
 * Total Submissions: 794.4K
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
struct trie{
    unordered_map<char,trie *> mp;
    int val;
};
void add(string val,struct trie * head)
{
    struct trie *temp=head;
    if(head==NULL)
    {
        return;
    }
    for(auto i:val)
    {
        if(temp->mp.find(i)!=temp->mp.end())
        {
            temp->mp[i]->val++;
            temp=temp->mp[i];
        }
        else
        {
            temp->mp[i]=new trie();
            temp=temp->mp[i];
            temp->val=1;
        }
    }
}
string display(struct trie *head,int n)
{
    string answer="";
    string res="";
    if(head->val!=n)
    {
        return "";
    }
    for(auto it=head->mp.begin();it!=head->mp.end();it++)
    {
        if(it->second->val==n)
        {
            return it->first+display(it->second,n);
        }
    }
    return "";
}
class Solution {
    struct trie *head;
public:
    Solution(){
        head = new trie();
    }
    string longestCommonPrefix(vector<string>& strs) {
        for(auto i:strs)
        {
            head->val++;
            add(i,head);
        }
        string answer="";
        return display(head,strs.size());
    }
};
