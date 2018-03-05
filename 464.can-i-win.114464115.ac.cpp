/*
 * [464] Can I Win
 *
 * https://leetcode.com/problems/can-i-win/description/
 *
 * algorithms
 * Medium (25.28%)
 * Total Accepted:    19K
 * Total Submissions: 75.2K
 * Testcase Example:  '10\n11'
 *
 * In the "100 game," two players take turns adding, to a running total, any
 * integer from 1..10. The player who first causes the running total to reach
 * or exceed 100 wins. 
 * 
 * What if we change the game so that players cannot re-use integers? 
 * 
 * For example, two players might take turns drawing from a common pool of
 * numbers of 1..15 without replacement until they reach a total >= 100.
 * 
 * Given an integer maxChoosableInteger and another integer desiredTotal,
 * determine if the first player to move can force a win, assuming both players
 * play optimally. 
 * 
 * You can always assume that maxChoosableInteger will not be larger than 20
 * and desiredTotal will not be larger than 300.
 * 
 * 
 * Example
 * 
 * Input:
 * maxChoosableInteger = 10
 * desiredTotal = 11
 * 
 * Output:
 * false
 * 
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers
 * from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >=
 * desiredTotal.
 * Same with other integers chosen by the first player, the second player will
 * always win.
 * 
 * 
 */
class Solution {
    vector<bool> used;
    unordered_map<int,bool> mp;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=0){
            return true;
        }
        int sum=maxChoosableInteger*(maxChoosableInteger+1)/2;//this is the total sum of the series
        if(sum<desiredTotal)
        {
            return false;
        }
        used=vector<bool>(maxChoosableInteger+1,false);//nothing is choosen so far
        return helper(desiredTotal);
    }
    bool helper(int desiredTotal)
    {
        //std::cout<<desiredTotal<<"\n";
        if(desiredTotal<=0)
        {
            //if we can reach the desired total
            return false;
        }
        int key=format(used);
        if(mp.find(key)==mp.end())
        {
            for(int i=1;i<used.size();i++)
            {
                if(!used[i])
                {
                    used[i]=true;//this is put in memoization that this particular value is being used
                    if(!helper(desiredTotal-i))
                    {
                        mp[key]=true;
                        used[i]=false;
                        return true;
                    }
                    used[i]=false;
                }
            }
            mp[key]=false;
        }
        return mp[key];//this is when we have key value
    }
    int format(vector<bool> val)
    {
        int num=0;
        for(auto b:val)
        {
            num<<=1;
            if(b)
                num|=1;
        }
        return num;
    }
};
