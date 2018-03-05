/*
 * [801] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (39.05%)
 * Total Accepted:    2.6K
 * Total Submissions: 6.7K
 * Testcase Example:  '[[1,3],[0,2],[1,3],[0,2]]'
 *
 * Given a graph, return true if and only if it is bipartite.
 * 
 * Recall that a graph is bipartite if we can split it's set of nodes into two
 * independent subsets A and B such that every edge in the graph has one node
 * in A and another node in B.
 * 
 * The graph is given in the following form: graph[i] is a list of indexes j
 * for which the edge between nodes i and j exists.  Each node is an integer
 * between 0 and graph.length - 1.  There are no self edges or parallel edges:
 * graph[i] does not contain i, and it doesn't contain any element twice.
 * 
 * 
 * Example 1:
 * Input: [[1,3], [0,2], [1,3], [0,2]]
 * Output: true
 * Explanation: 
 * The graph looks like this:
 * 0----1
 * |    |
 * |    |
 * 3----2
 * We can divide the vertices into two groups: {0, 2} and {1, 3}.
 * 
 * 
 * 
 * Example 2:
 * Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
 * Output: false
 * Explanation: 
 * The graph looks like this:
 * 0----1
 * | \  |
 * |  \ |
 * 3----2
 * We cannot find a way to divide the set of nodes into two independent
 * subsets.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * graph will have length in range [1, 100].
 * graph[i] will contain integers in range [0, graph.length - 1].
 * graph[i] will not contain i or duplicate values.
 * 
 */
class Solution {
public:
    //0 means never visted
    //1 means visited with colour grey
    //2 means visited with colour white
    bool bfs(vector<int> &visited,int root,int colour,vector<vector<int>> & graph){
        queue<int> que;
        que.push(root);
        visited[root]=colour;
        colour = colour ==1?2:1;
        while(!que.empty()){
            int size=que.size();
            while(size-->0)
            {
                int temp=que.front();
                que.pop();
                if(visited[temp]==colour)
                    return false;//they are of same colour
                for(auto i:graph[temp]){
                    if(visited[i]==0)
                    {
                        que.push(i);
                        visited[i]=visited[temp]==1?2:1;
                    }
                    else if(visited[i]==visited[temp])
                        return false;
                }
            }
            colour = colour ==1?2:1;//change colour for next level
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        if(!size)
            return false;
        vector<int> visited(size,0);//nobody has visited yet
        for (int i = 0; i < size; i++)
            if (visited[i] == 0)
                if (!bfs(visited, i,1, graph))
                    return false;
        return true;
    }
};
