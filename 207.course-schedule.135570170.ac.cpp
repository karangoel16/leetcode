/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (33.50%)
 * Total Accepted:    115.3K
 * Total Submissions: 344.3K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So it is possible.
 * 
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0, and to take course 0 you should also have finished course
 * 1. So it is impossible.
 * 
 * Note:
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be
 * impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 * 
 */
class Solution {
    vector<unordered_set<int>> graph;
public:
    bool canFinish(int numCourses, vector<pair<int,int>> prerequisites)
    {
        vector<unordered_set<int>> matrix(numCourses); // save this directed graph
        for(int i = 0; i < prerequisites.size(); ++ i)
            matrix[prerequisites[i].second].insert(prerequisites[i].first);

        unordered_set<int> visited;
        vector<bool> flag(numCourses, false);
        for(int i = 0; i < numCourses; ++ i)
            if(!flag[i])
                if(DFS(matrix, visited, i, flag))
                    return false;
        return true;
    }
    bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag)
    {
        flag[b] = true;
        visited.insert(b);
        for(auto it = matrix[b].begin(); it != matrix[b].end(); ++ it)
            if(visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag))
                return true;
        visited.erase(b);
        return false;
    }
};
