//代码写的好乱，但是我又不想改

//将原始路径一步一步剥离，对新的路径进行回退或者添加
class Solution {
public:
    void simplifyStep(string& r, string& path, int i){
        if(i >= path.length())  return;
        string temp;
        temp += path[i];
        int j=i+1;
        while(j < path.length() && path[j] != '/'){
            temp += path[j++];
        }
        if(temp == "/.."){
            int k = r.length()-1;
            while(k > 0 && r[k] != '/'){
                r.pop_back();
                --k;
            }
            if(r.length() > 0)
                r.pop_back();
            simplifyStep(r, path, j);
        }
        else if(temp == "/." || temp.length() < 2)
            simplifyStep(r, path, j);
        else{
            r += temp;
            simplifyStep(r, path, j);
        }
    }
    
    string simplifyPath(string path) {
        string r;
        
        simplifyStep(r, path, 0);
        if(r.length() == 0 && path.length() != 0)
            r+='/';
        return r;
    }
};




//还是挣扎着改了一下，但是由于频繁的字符串构造，运行时间增加了
class Solution {
public:
    void simplifyStep(string& r, string path){
        if(path.length() == 0){
            if(r.length() == 0)
                r+='/';
            return;
        } 
        if(path.length() == 1 && r.length() == 0){
            r+=path[0];
            return;
        }
        string temp;
        temp += path[0];
        
        int j=1;
        while(j < path.length() && path[j] != '/'){
            temp += path[j++];
        }
        if(temp == "/.."){
            int k = r.length()-1;
            while(k > 0 && r[k] != '/'){
                r.pop_back();
                --k;
            }
            if(r.length() > 0)
                r.pop_back();
            simplifyStep(r, string(path, j, path.length()-j));
        }
        else if(temp == "/." || temp.length() < 2){
            simplifyStep(r, string(path, j, path.length()-j));
        }
        else{
            r += temp;
            simplifyStep(r, string(path, j, path.length()-j));
        }
    }
    
    string simplifyPath(string path) {
        string r;
        
        simplifyStep(r, path);
        return r;
    }
};
