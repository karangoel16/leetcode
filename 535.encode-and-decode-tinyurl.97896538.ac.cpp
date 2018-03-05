/*
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (73.88%)
 * Total Accepted:    32.5K
 * Total Submissions: 44.1K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 * 
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 * 
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 */
class Solution {
public:
    string dict="0123456789abcdefghijklmnopqrstuvwqyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string,string> mp;
    unordered_map<long,string> rev;
    int id=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(mp.find(longUrl)!=mp.end())
        {
            return mp[longUrl];
        }
        string res="";
        id++;
        int count=id;
        while(count)
        {
            res=dict[(count%62)]+res;
            count=count/62;
        }
        while(res.length()<6)
        {
            res="0"+res;
        }
        mp[longUrl]=res;
        rev[id]=longUrl;
        //std::cout<<res<<"\n";
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int count=0;
        for(int i=0;i<shortUrl.length();i++)
        {
            count=(count*62)+(int)dict.find(shortUrl[i]);
        }
        //std::cout<<count;
        if(rev.find(count)!=rev.end())
        {
            return rev[count];
        }
        return rev[count];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
