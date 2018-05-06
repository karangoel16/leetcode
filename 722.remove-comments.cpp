class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        stringstream ss;
        const char * delim = "\n";
        copy(source.begin(),source.end(),ostream_iterator<string>(ss,delim));
        string s=ss.str();
        regex e("//.*|/\\*(.|\n)*?\\*/");
        string ns=regex_replace(s,e,"");
        vector<string> res;
        ss.str(ns);
        string line;
        while(getline(ss,line,'\n')){
            if(line.size())
                res.emplace_back(line);
        } 
        return res;
    }
};
