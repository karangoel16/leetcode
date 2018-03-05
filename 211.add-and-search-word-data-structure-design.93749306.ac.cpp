/*
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (25.04%)
 * Total Accepted:    72K
 * Total Submissions: 287.8K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * 
 * For example:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 * 
 * click to show hint.
 * 
 * You should be familiar with how a Trie works. If not, please work on this
 * problem: Implement Trie (Prefix Tree) first.
 * 
 */
struct prefix{
    unordered_map<char,prefix*> mul;
    char end;
    prefix()
    {
        end=false;
    }
}*head;
bool helper(string word,prefix *root,int len)
{
    if(root->end && len>=word.length())
    {
        return true;
    }
    if(word[len]=='.')//this is to check and loop in the words
    {
        for(auto it=root->mul.begin();it!=root->mul.end();it++)
        {
            if(helper(word,it->second,len+1))
            {
                return true;
            }
        }
    }
    if(root->mul.find(word[len])!=root->mul.end())
    {
        return helper(word,root->mul[word[len]],len+1);
    }
    return false;
}
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head =new prefix();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        struct prefix *temp=head;
        for(auto i:word)
        {
            if(temp->mul.find(i)==temp->mul.end())
            {
                temp->mul[i]=new prefix();
                temp=temp->mul[i];
            }
            else
            {
                temp=temp->mul[i];
            }
        }
        temp->end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(word,head,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
