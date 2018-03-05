/*
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (49.14%)
 * Total Accepted:    32.3K
 * Total Submissions: 65.7K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */
class union_find
{
    unordered_map<int,int> mp;
    public:
    union_find(int m)
    {
        for(int i=0;i<m;i++)
        {
            mp[i]=i;//connect to your self
        }
    }
    int find()
    {
        unordered_set<int> st;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            st.insert(find_root(it->second));
        }
        return st.size();//this is to tell how many seperate sets are formed
    }
    int find_root(int p)
    {
        int root=p;
        while(mp[root]!=root)
        {
            root=mp[root];//we are going above towards the main root
        }
        int temp=p;
        while(mp[temp]!=root)
        {
            int val=mp[temp];
            mp[temp]=root;
            temp=val;
        }
        return root;
    }
    void connect(int p,int q)
    {
        int rootp=find_root(p);
        int rootq=find_root(q);
        if(rootp==rootq)
        {
            return ;//this is when we are at same page already connected
        }
        mp[rootp]=rootq;
        return ;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int row=M.size();
        union_find graph(row);
        for(int i=0;i<row;i++)
        {
            for(int j=i+1;j<row;j++)
            {
                //this is to make use of the upper part of the array
                if(M[i][j]==1)
                {
                    graph.connect(i,j);//we connected these two graph
                }
            }
           // std::cout<<graph.find()<<"\n";
        }
        return graph.find();
    }
};
