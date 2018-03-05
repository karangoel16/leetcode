/*
 * [746] Prefix and Suffix Search
 *
 * https://leetcode.com/problems/prefix-and-suffix-search/description/
 *
 * algorithms
 * Hard (24.67%)
 * Total Accepted:    3K
 * Total Submissions: 12K
 * Testcase Example:  '["WordFilter","f"]\n[[["apple"]], ["a","e"]]'
 *
 * 
 * Given many words, words[i] has weight i.
 * 
 * Design a class WordFilter that supports one function, WordFilter.f(String
 * prefix, String suffix).
 * It will return the word with given prefix and suffix with maximum weight.
 * If no word exists, return -1.
 * 
 * 
 * Examples:
 * 
 * Input:
 * WordFilter(["apple"])
 * WordFilter.f("a", "e") // returns 0
 * WordFilter.f("b", "") // returns -1
 * 
 * 
 * Note:
 * 
 * words has length in range [1, 15000].
 * For each test case, up to words.length queries WordFilter.f may be made.
 * words[i] has length in range [1, 10].
 * prefix, suffix have lengths in range [0, 10].
 * words[i] and prefix, suffix queries consist of lowercase letters only.
 * 
 * 
 */
struct trie{
    vector <trie *> child;    
    vector<int> index;
    trie()
    {
        child=vector<trie *>(26,NULL);
    }
    vector<int> findIndex(string word,int pos)
    {
        if(pos>word.length())
            return vector<int>();
        if(pos==word.length())
        {
            return index;
        }
        int temp=word[pos]-'a';
        if(child[temp]==NULL)
            return vector<int>();
        return child[temp]->findIndex(word,pos+1);
    }
    
    void add(string word,int i,int pos)
    {
        index.push_back(i);
        if(word.length()<=pos)
        {
            return ;
        }
        int temp=word[pos]-'a';
        //std::cout<<temp<<" "<<word[pos]<<" "<<index.size()<<"\n";
        if(child[temp]==NULL)
            child[temp]=new trie();
        child[temp]->add(word,i,pos+1);
        return ;
    }  
};

class WordFilter {
    trie *front;
    trie *back;
public:
    WordFilter(vector<string> words) {
        front = new trie();
        //this is for the front row
        back = new trie();
        //this is for the back row
        for(int i=0;i<words.size();i++)
        {
            front->add(words[i],i,0);
            std::reverse(words[i].begin(),words[i].end());
            back->add(words[i],i,0);
        }
    }
    
    int f(string prefix, string suffix) {
        vector<int> frontval=front->findIndex(prefix,0);
        reverse(suffix.begin(), suffix.end());
        vector<int> backval=back->findIndex(suffix,0);
        int i=frontval.size()-1;
        int j=backval.size()-1;
        /*
        for(auto i:frontval)
        {
            std::cout<<i<<"\t";
        }
        std::cout<<endl;
        for(auto i:backval)
        {
            std::cout<<i<<"\t";
        }
        std::cout<<endl;
        */
        while(i>=0 && j>=0)
        {
            if(frontval[i]>backval[j])
            {
                i--;
            }
            else if(frontval[i]<backval[j])
            {
                j--;
            }
            else
            {
                return frontval[i];
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
