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
        if(s.length() <= 10)
            return {};
        vector<string> res;
        unordered_map<string,int> mp;
        for(auto i=0;i<s.length()-9;i++)
            mp[s.substr(i,10)]++;
        for(auto i:mp)
            if(i.second>1)
                res.emplace_back(i.first);
        return res;
    }
};
