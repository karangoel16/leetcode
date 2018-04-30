vector<string> split(string & s)
{
    stringstream ss(s);
    vector<string> res;
    for(string s;ss>>s;)
        res.emplace_back(std::move(s));
    return res;
}
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> res;
        for(auto i:split(path)){
            if(i==".."){
                if(!res.empty())
                    res.pop();
            }
            else if(i==".")
                continue;
            else
                res.push(i);
                
        }
        vector<string> s;
        while(!res.empty()){
            s.emplace_back(std::move(res.top()));
            s.emplace_back("/");
            res.pop();
        }
        std::reverse(s.begin(),s.end());
        stringstream result;
        for(auto i:s)
            result<<i;
        string rs=result.str();
        return rs.length()?rs:"/";
    }
};
