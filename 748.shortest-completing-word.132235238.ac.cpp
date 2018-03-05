/*
 * [749] Shortest Completing Word
 *
 * https://leetcode.com/problems/shortest-completing-word/description/
 *
 * algorithms
 * Medium (53.00%)
 * Total Accepted:    5.3K
 * Total Submissions: 10.1K
 * Testcase Example:  '"1s3 PSt"\n["step","steps","stripe","stepple"]'
 *
 * 
 * Find the minimum length word from a given dictionary words, which has all
 * the letters from the string licensePlate.  Such a word is said to complete
 * the given string licensePlate
 * 
 * Here, for letters we ignore case.  For example, "P" on the licensePlate
 * still matches "p" on the word.
 * 
 * It is guaranteed an answer exists.  If there are multiple answers, return
 * the one that occurs first in the array.
 * 
 * The license plate might have the same letter occurring multiple times.  For
 * example, given a licensePlate of "PP", the word "pair" does not complete the
 * licensePlate, but the word "supper" does.
 * 
 * 
 * Example 1:
 * 
 * Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe",
 * "stepple"]
 * Output: "steps"
 * Explanation: The smallest length word that contains the letters "S", "P",
 * "S", and "T".
 * Note that the answer is not "step", because the letter "s" must occur in the
 * word twice.
 * Also note that we ignored case for the purposes of comparing whether a
 * letter exists in the word.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
 * Output: "pest"
 * Explanation: There are 3 smallest length words that contains the letters
 * "s".
 * We return the one that occurred first.
 * 
 * 
 * 
 * Note:
 * 
 * licensePlate will be a string with length in range [1, 7].
 * licensePlate will contain digits, spaces, or letters (uppercase or
 * lowercase).
 * words will have a length in the range [10, 1000].
 * Every words[i] will consist of lowercase letters, and have length in range
 * [1, 15].
 * 
 * 
 */
class Solution {
public:
    /*long result(string str)
    {
        vector<int>val={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        long ret=1;
        for(auto i:str)
        {
            ret*=(i>='a' && i<='z')?val[i-'a']:1;
            ret*=(i>='A' && i<='Z')?val[i-'A']:1;
            //std::cout<<ret<<"\n";
        }
        return ret;
    }*/
    vector<int> result1(string str)
    {
        vector<int> res(27,0);
        for(auto i:str)
        {
            res[(i>='a' && i<='z')?i-'a':26]++;
            res[(i>='A' && i<='Z')?i-'A':26]++;
            //std::cout<<ret<<"\n";
        }
        return res;
    }
    bool test(vector<int> res1,vector<int> res2)
    {
        for(int i=0;i<26;i++)
        {
            if(res1[i] && res1[i]>res2[i])
            {
                //std::cout<<res1[i]<<res2[i]<<"\n"<<i;
                return false;
            }
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
       
        //long temp=result(licensePlate);
        vector<int> res=result1(licensePlate);
        /*for(auto i:res)
        {
            std::cout<<i<<"\n";
        }*/
        //std::sort(words.begin(),words.end(),[](const std::string &s1, const std::string &s2) {return s1.size() < s2.size(); });
        string rep="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        for(auto i:words)
        {
            if(test(res,result1(i)) && rep.length()>i.length()) rep=i;
        }
        return rep;
    }
};
