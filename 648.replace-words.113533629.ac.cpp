/*
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (47.64%)
 * Total Accepted:    14.2K
 * Total Submissions: 29.7K
 * Testcase Example:  '["cat", "bat", "rat"]\n"the cattle was rattled by the battery"'
 *
 * 
 * In English, we have a concept called root, which can be followed by some
 * other words to form another longer word - let's call this word successor.
 * For example, the root an, followed by other, which can form another word
 * another.
 * 
 * 
 * 
 * 
 * Now, given a dictionary consisting of many roots and a sentence. You need to
 * replace all the successor in the sentence with the root forming it. If a
 * successor has many roots can form it, replace it with the root with the
 * shortest length.
 * 
 * 
 * 
 * You need to output the sentence after the replacement.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: dict = ["cat", "bat", "rat"]
 * sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The input will only have lower-case letters.
 * ⁠1 
 * ⁠1 
 * ⁠1 
 * ⁠1 
 * 
 * 
 */
struct suffix_tree{
    unordered_map<char,suffix_tree *> mp;
    bool end;
    public:
        suffix_tree(){
            end=false;
        }
};

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}


void add(string val,int i,suffix_tree *root)
{
    if(i>=val.length())
    {
        root->end=true;
        //this is the end of the 
        return;
    }
    if(root->mp.find(val[i])==root->mp.end())
    {
        root->mp[val[i]]=new suffix_tree();
    }
    add(val,i+1,root->mp[val[i]]);
}

int disp(string val,int i,suffix_tree *head)
{
    if(head->mp.find(val[0])==head->mp.end())
    {
        return -1;
    }
    while(!head->end && head->mp.find(val[i])!=head->mp.end())
    {
        head=head->mp[val[i]];
        i++;
    }
    return head->end?i:-1;
}

class Solution {
    suffix_tree *head;
public:
    Solution(){
        head=new suffix_tree();
    }
    string replaceWords(vector<string>& dict, string sentence) {
        for(auto i:dict)
        {
            add(i,0,head);
        }
        vector<string> val=split(sentence,' ');
        stringstream ss;
        for(auto i:val)
        {
            int temp=disp(i,0,head);
            if(temp!=-1)
            {
                ss<<i.substr(0,temp)<<" ";   
            }
            else
            {
                ss<<i<<" ";
            }
        }
        string temp=ss.str();
        return temp.substr(0,temp.length()-1);        
    }
};
