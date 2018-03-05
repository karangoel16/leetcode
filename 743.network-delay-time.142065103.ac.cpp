/*
 * [744] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (34.39%)
 * Total Accepted:    5.1K
 * Total Submissions: 14.9K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K.  How long will it take for all
 * nodes to receive the signal?  If it is impossible, return -1.
 * 
 * 
 * Note:
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1  and 1 .
 * 
 * 
 */
#define ipair pair<int,int> 
class Graph{
    int N;
    unordered_map<int,vector<ipair>> mp;
    public:
    Graph(){
        
    }
    Graph(int n,vector<vector<int>> result):N(n){
        for(int i=1;i<=n;i++)
            mp[i]=vector<ipair>();
        for(auto i:result)
            mp[i[0]].push_back({i[1],i[2]});
    }
    int dijkstra(int src,int dest){
        vector<int> dt(N+1,INT_MAX);
        priority_queue<ipair,vector<ipair>,std::greater<ipair>> pq;
        pq.push({0,src});
        dt[src]=0;
        while(!pq.empty()){
            ipair top=pq.top();
            pq.pop();
            for(auto i:mp[top.second]){
                if(dt[i.first]>dt[top.second]+i.second){
                    dt[i.first]=dt[top.second]+i.second;
                    pq.push({dt[i.first],i.first});
                }
            }
        }
        //for(auto i:dt)
        //    std::cout<<i<<"\t";
        //std::cout<<endl;
        return *max_element(dt.begin()+1,dt.end());
    }
    
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        Graph gph(N,times);
        int min=INT_MAX;
        min=std::min(gph.dijkstra(K,K),min);
        return min==INT_MAX?-1:min;
    }
};
