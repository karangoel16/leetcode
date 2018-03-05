/*
 * [676] Implement Magic Dictionary
 *
 * https://leetcode.com/problems/implement-magic-dictionary/description/
 *
 * algorithms
 * Medium (49.47%)
 * Total Accepted:    10K
 * Total Submissions: 20.2K
 * Testcase Example:  '["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]'
 *
 * 
 * Implement a magic directory with buildDict, and search methods.
 * 
 * 
 * 
 * For the method buildDict, you'll be given a list of non-repetitive words to
 * build a dictionary.
 * 
 * 
 * 
 * For the method search, you'll be given a word, and judge whether if you
 * modify exactly one character into another character in this word, the
 * modified word is in the dictionary you just built.
 * 
 * 
 * Example 1:
 * 
 * Input: buildDict(["hello", "leetcode"]), Output: Null
 * Input: search("hello"), Output: False
 * Input: search("hhllo"), Output: True
 * Input: search("hell"), Output: False
 * Input: search("leetcoded"), Output: False
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that all the inputs are consist of lowercase letters a-z.
 * For contest purpose, the test data is rather small by now. You could think
 * about highly efficient algorithm after the contest.
 * Please remember to RESET your class variables declared in class
 * MagicDictionary, as static/class variables are persisted across multiple
 * test cases. Please see here for more details.
 * 
 * 
 */
struct node 
{
    unordered_map<char,node *> mp;
    bool end;
    node()
    {
        end=false;
    }
};

void add(node *head,string val,int i)
{
    if(i==val.length())
    {
        head->end=true;
        return ;
    }
    if(head->mp.find(val[i])==head->mp.end())
    {
        head->mp[val[i]]=new node();
    }
    add(head->mp[val[i]],val,i+1);
}

bool helper(node * head,int i,string val)
{
    if(i==val.length())
    {
        if(head->end==true)
        {
            return true;
        }
        return false;
    }
    return (head->mp.find(val[i])!=head->mp.end() && helper(head->mp[val[i]],i+1,val));
}

class MagicDictionary {
    struct node *head;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        head=new node();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto i:dict)
        {
            add(head,i,0);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        //std::cout<<word<<"****\n";
        for(int i=0;i<word.length();i++)
        {
            for(char c='a';c<='z';c++)
            {
                if(word[i]==c)
                {
                    continue;
                }
                char temp=word[i];
                word[i]=c;
                if(helper(head,0,word))
                {
                    //std::cout<<word<<"\n";
                    return true;
                }
                word[i]=temp;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
