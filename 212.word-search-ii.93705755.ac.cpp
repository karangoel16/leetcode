/*
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (24.60%)
 * Total Accepted:    61.3K
 * Total Submissions: 249.2K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * 
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * For example,
 * Given words = ["oath","pea","eat","rain"] and board = 
 * 
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * 
 * Return ["eat","oath"].
 * 
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 * 
 * click to show hint.
 * 
 * You would need to optimize your backtracking to pass the larger test. Could
 * you stop backtracking earlier?
 * 
 * If the current candidate does not exist in all words' prefix, you could stop
 * backtracking immediately. What kind of data structure could answer such
 * query efficiently? Does a hash table work? Why or why not? How about a Trie?
 * If you would like to learn how to implement a basic trie, please work on
 * this problem: Implement Trie (Prefix Tree) first.
 * 
 */
struct trie{
    unordered_map<char,trie *> mul;
    bool end;
    trie()
    {
        end=false;
    }
} *head;

bool add(string s)
{
    struct trie *t=head;
    for(auto i:s)
    {
        if(t->mul.find(i)!=t->mul.end())
        {
            t=t->mul[i];
        }
        else
        {
            t->mul[i]=new trie();
            t=t->mul[i];
        }
    }
    t->end=true;
    return true;
}
int display(trie *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->end)
    {
        std::cout<<"\n";
    }
    for(auto it=root->mul.begin();it!=root->mul.end();it++)
    {
        std::cout<<it->first;
        display(it->second);
    }
    return 1;
}
void find(vector<vector<char>>&board,int row,int col,int x,int y,struct trie *temp,unordered_set<string> &words,string temp1)
{
    if(x<0 || y<0 || x>=row || y>=col || board[x][y]=='*' || temp->mul.find(board[x][y])==temp->mul.end())
    {
        //std::cout<<"****************"<<"\n";
        return ;
    }
    //std::cout<<x<<" "<<y<<" "<<board[x][y]<<"\n";
    //std::cout<<temp1<<"\n";
    temp1=temp1+board[x][y];
    char ch=board[x][y];
    board[x][y]='*';//this is
    temp=temp->mul[ch];
    if(temp->end==true)
    {
        words.insert(temp1);//this is to push the element into the temprary array
    }
    //std::cout<<ch<<"\n";
    find(board,row,col,x+1,y,temp,words,temp1);
    find(board,row,col,x,y+1,temp,words,temp1);
    //std::cout<<it->first<<"2*\n
    find(board,row,col,x-1,y,temp,words,temp1);
    //std::cout<<it->first<<"2*\n";
    find(board,row,col,x,y-1,temp,words,temp1);
    //std::cout<<it->first<<"2*\n";
    board[x][y]=ch;//this is to bring 
    return ;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        head=new trie();
        for(auto i:words)
        {
            add(i);
        }
        //display(head);
        int row=board.size();
        int col=board[0].size();
        if(row==0 || col==0)
        {
            return vector<string>{};
        }
        string temp1="";
        unordered_set<string> res;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                find(board,row,col,i,j,head,res,temp1);//here we send board[i][j] to find if the element does exist int the first place of not
            }
        }
        return std::vector<string>{res.begin(),res.end()};
    }
};
