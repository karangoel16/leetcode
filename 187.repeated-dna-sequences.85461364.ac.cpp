/*
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (32.85%)
 * Total Accepted:    91.3K
 * Total Submissions: 278K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * 
 * For example,
 * 
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * 
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 * 
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> map_;
        vector<string> res;
        if(s.length()<10)
        {
            return res;
        }
        for(int i=0;i<=s.length()-10;i++)
        {
            string temp=s.substr(i,10);
            //std::cout<<temp<<"\n";
            if(map_.find(temp)!=map_.end())
            {
                map_[temp]++;
            }
            else
            {
                map_[temp]=1;
            }
        }
        for(auto it=map_.begin();it!=map_.end();it++)
        {
            if(it->second>1)
            {
                res.push_back(it->first);
            }
        }
        return res;
    }
};
