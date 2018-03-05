/*
 * [432] All O`one Data Structure
 *
 * https://leetcode.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (27.99%)
 * Total Accepted:    9K
 * Total Submissions: 32.1K
 * Testcase Example:  '["AllOne","getMaxKey","getMinKey"]\n[[],[],[]]'
 *
 * Implement a data structure supporting the following operations:
 * 
 * 
 * 
 * Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by
 * 1. Key is guaranteed to be a non-empty string.
 * Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise
 * decrements an existing key by 1. If the key does not exist, this function
 * does nothing. Key is guaranteed to be a non-empty string.
 * GetMaxKey() - Returns one of the keys with maximal value. If no element
 * exists, return an empty string "".
 * GetMinKey() - Returns one of the keys with minimal value. If no element
 * exists, return an empty string "".
 * 
 * 
 * 
 * 
 * Challenge: Perform all these in O(1) time complexity.
 * 
 */
struct compare
{
    bool operator ()(pair<string,int> a, pair<string,int> b)
    {
        if(a.second<b.second)
        {
            return true;
        }
        return false;
    }
};
struct compare1{
    bool operator () (pair<string,int> a, pair<string,int> b)
    {
        if(a.second>b.second)
        {
            return true;
        }
        return false;
    }
};
class AllOne {
    unordered_map<string,int> mul;
    priority_queue<pair<string,int>,vector<pair<string,int>>,compare> pr1;
    priority_queue<pair<string,int>,vector<pair<string,int>>,compare1> pr2;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
         if(mul.find(key)!=mul.end())
         {
             mul[key]++;
         }
         else
         {
             mul[key]=1;
         }
         pr1.push(make_pair(key,mul[key]));
         pr2.push(make_pair(key,mul[key]));
         while(!pr1.empty() && (mul[pr1.top().first]==0 || pr1.top().second!=mul[pr1.top().first]))
         {
             //std::cout<<key<<" "<<mul[key]<<" "<<pr1.top().first<<" "<<pr1.top().second<<"\n";
             pr1.pop();
         }
         while(!pr2.empty() && (mul[pr2.top().first]==0 ||pr2.top().second!=mul[pr2.top().first]))
         {
             //std::cout<<key<<" "<<mul[key]<<" "<<pr2.top().first<<" "<<pr2.top().second<<"\n";
             pr2.pop();
         }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(mul.find(key)!=mul.end())
        {
            int flag=0;
            if(mul[key]==1)
            {
                mul.erase(key);
                flag=1;
                
            }
            else
            {
                mul[key]--;//this is done to decrease the key
            }
            pr1.push(make_pair(key,mul[key]));
            pr2.push(make_pair(key,mul[key]));
            while(!pr1.empty() && (mul[pr1.top().first]==0 || pr1.top().second!=mul[pr1.top().first]))
            {
                 //std::cout<<key<<" "<<mul[key]<<" "<<pr1.top().first<<" "<<pr1.top().second<<"\n";
                 pr1.pop();
            }
            while(!pr2.empty() && (mul[pr2.top().first]==0 || pr2.top().second!=mul[pr2.top().first]))
            {
                 //std::cout<<key<<" "<<mul[key]<<" "<<pr2.top().first<<" "<<pr2.top().second<<"\n";
                 pr2.pop();
            }
        }
        
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(pr1.empty())
        {
            return "";
        }
        return pr1.top().first;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(pr2.empty())
        {
            return "";
        }
        return pr2.top().first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
