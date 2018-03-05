/*
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (29.51%)
 * Total Accepted:    23.2K
 * Total Submissions: 78.5K
 * Testcase Example:  '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n[[],[1],[1],[2],[],[1],[]]'
 *
 * Design a data structure that supports all following operations in average
 * O(1) time.
 * Note: Duplicate elements are allowed.
 * 
 * 
 * insert(val): Inserts an item val to the collection.
 * remove(val): Removes an item val from the collection if present.
 * getRandom: Returns a random element from current collection of elements. The
 * probability of each element being returned is linearly related to the number
 * of same value the collection contains.
 * 
 * 
 * 
 * Example:
 * 
 * // Init an empty collection.
 * RandomizedCollection collection = new RandomizedCollection();
 * 
 * // Inserts 1 to the collection. Returns true as the collection did not
 * contain 1.
 * collection.insert(1);
 * 
 * // Inserts another 1 to the collection. Returns false as the collection
 * contained 1. Collection now contains [1,1].
 * collection.insert(1);
 * 
 * // Inserts 2 to the collection, returns true. Collection now contains
 * [1,1,2].
 * collection.insert(2);
 * 
 * // getRandom should return 1 with the probability 2/3, and returns 2 with
 * the probability 1/3.
 * collection.getRandom();
 * 
 * // Removes 1 from the collection, returns true. Collection now contains
 * [1,2].
 * collection.remove(1);
 * 
 * // getRandom should return 1 and 2 both equally likely.
 * collection.getRandom();
 * 
 * 
 */
class RandomizedCollection {
    multimap<int,int> mul;
    unordered_map<int,int> val_size;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        size=0;
        mul.clear();
        val_size.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        pair<multimap<int,int>::iterator,multimap<int,int>::iterator> res=mul.equal_range(val);
        if(mul.find(val)!=mul.end())
        {
            size++;
            val_size[val]++;//this is done to add the value in the node
            mul.insert(make_pair(val,res.second->second+1));
            return false;
        }
        else
        {
            size++;
            val_size[val]=1;
            mul.insert(make_pair(val,1));
        }
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mul.find(val)!=mul.end())
        {
            pair<multimap<int,int>::iterator,multimap<int,int>::iterator> res=mul.equal_range(val);
            size--;
            mul.erase(res.first);
            val_size[val]--;//this is done to erase the value
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(size==0)
        {
            return 0;
        }
        int res=0;
        int count=0;
        auto it=mul.begin();
        std::advance(it,rand()%size);
        return it->first;
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
