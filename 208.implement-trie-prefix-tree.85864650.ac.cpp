/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (30.55%)
 * Total Accepted:    104.3K
 * Total Submissions: 341.4K
 * Testcase Example:  '["Trie","search"]\n[[],["a"]]'
 *
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 */
class TrieNode {
    public:
    // Initialize your data structure here
    TrieNode():isWord(false) {
    }
    unordered_map<char,TrieNode*> mul;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(const string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->mul.find(word[i])!=temp->mul.end())
            {
                temp=(TrieNode *)temp->mul[word[i]];
            }
            else
            {
                //TrieNode *temp1=new TrieNode();
                temp->mul[word[i]]=new TrieNode();
                temp=temp->mul[word[i]];
            }
        }
        temp->isWord=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->mul.find(word[i])!=temp->mul.end())
            {
                temp=temp->mul[word[i]];
            }
            else
            {
                return false;
            }
        }
        if(temp->isWord)
        {
            return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *temp=root;
        for(int i=0;i<prefix.length() && temp!=NULL;i++)
        {
            if(temp->mul.find(prefix[i])!=temp->mul.end())
            {
                temp=(TrieNode *)temp->mul[prefix[i]];
            }
            else
            {
                return false;
            }
        }
        if(temp!=NULL)
        {
            return true;
        }
        return false;
    }

private:
    TrieNode* root;
};
