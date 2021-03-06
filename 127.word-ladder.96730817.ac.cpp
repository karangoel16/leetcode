/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (19.94%)
 * Total Accepted:    156.2K
 * Total Submissions: 783.1K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * 
 * For example,
 * 
 * 
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * 
 * Note:
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * 
 * 
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
public:
    queue<string> st;
    unordered_set<string> mul;
    
    int helper(string word)//this is to create adjacency list
    {
        mul.erase(word);
        for(int i=0;i<word.length();i++)
        {
            char letter=word[i];
            for(int j=0;j<26;j++)
            {
                //we will create adjacency list using this phenomenon
                word[i]='a'+j;
                if(mul.find(word)!=mul.end())
                {
                    st.push(word);//we need to push the variable in case it is adjacent to the node
                    mul.erase(word);
                }
            }
            word[i]=letter;
        }
        return 0;
    };
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto i:wordList)
        {
            mul.insert(i);
        }
        //mul.insert(endWord);
        helper(beginWord);
        int dist=2;
        while(!st.empty())
        {
            int num = st.size();
            //std::cout<<num<<"\n";
            for (int i = 0; i < num; i++) {
                string word = st.front();
                st.pop();
                if (word == endWord) 
                {
                    //std::cout<<"*";
                    return dist;
                }
                helper(word);
            }
            dist++;
        }
        return 0;
    }
};
