/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (23.35%)
 * Total Accepted:    89.8K
 * Total Submissions: 384.4K
 * Testcase Example:  '[1]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
struct Compare
{
    bool operator()(const string &a,const string &b)
    {
        string temp1=a+b;
        string temp2=b+a;
        int j=0;
        if(atol(temp1.c_str())>atol(temp2.c_str()))
        {
            return false;
        }
        return true;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string temp;
        priority_queue<string,vector<string>,Compare> pr;
        for(int i=0;i<nums.size();i++)
        {
            pr.push(to_string(nums[i]));
        }
        while(!pr.empty())
        {
            //std::cout<<pr.top()<<"\n";
            temp=temp+pr.top();
            pr.pop();
        }
        int j=0;
        while(j<temp.length())
        {
            if(temp[j]!='0')
            {
                break;
            }
            if(temp[j]=='0')
            {
                j++;
            }
        }
        if(j==temp.length())
        {
            return "0";
        }
        return temp.substr(j,temp.length()-j);
    }
};
