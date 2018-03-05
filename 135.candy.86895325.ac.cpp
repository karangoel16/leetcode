/*
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (25.20%)
 * Total Accepted:    76.7K
 * Total Submissions: 304.4K
 * Testcase Example:  '[0]'
 *
 * 
 * There are N children standing in a line. Each child is assigned a rating
 * value. 
 * 
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();
       vector<int> temp(n+2,0);
       vector<int> res(n+2,1);
       res[0]=0;
       res[n+1]=0;
       for(int i=0;i<n;i++)
       {
           temp[i+1]=ratings[i];
       }
       for(int i=1;i<=n;i++)
       {
           if(temp[i]>temp[i-1])
           {
               res[i]=res[i]+res[i-1];//this is to increase teh candies by 1
           }
       }
       for(int i=n;i>=1;i--)
       {
           if(temp[i]>temp[i+1] && res[i]!=1)
           {
               res[i]=(res[i-1]>res[i+1]?res[i-1]:res[i+1])+1;
           }
           else if(temp[i]>temp[i+1] && res[i]<=res[i+1])
           {
               res[i]=res[i]+res[i+1];
           }
       }
       return std::accumulate(res.begin(),res.end(),0);
    }
};
