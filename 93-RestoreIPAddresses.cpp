//每个ip地址都可以是4段，所以可以采用每段都尝试的回溯法。最多递归4次，
//要完全正确得调一些时间
class Solution {
public:
    
    void build_ip_addr(string& s, vector<string>& result, string& cur, int pos, int part){
        if(part > 4){
            if(pos >= s.length())
                result.push_back(cur);
            return;
        }
        int prelen;
        for(int i=1; i<=3; ++i){
            string tmp = s.substr(pos, i);
            if(tmp[0] == '0' && tmp.length() > 1)   continue;
            int t = atoi(tmp.c_str());
            prelen = cur.length();
            if(t <= 255 && pos + i <= s.length()){
                cur += (part == 1 ? tmp : ('.' + tmp));
                build_ip_addr(s, result, cur, pos+i, part+1);
                for(int k=0;cur.length()-prelen; ++k)
                    cur.pop_back();
            }
        }
        
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        string temp;
        build_ip_addr(s, r, temp, 0, 1);
        return r;
    }
};
