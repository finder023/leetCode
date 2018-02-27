/*
整数反转，也很简单，要注意的地方是string 和int 之间的转换： to_string()函数，sprintf()将int转为string，sscanf()，stringstream可以将string转为int.
*/


class Solution {
public:
    int reverse(int x) {
        string sx = to_string(x);
        int start = 0, end = sx.length() - 1;
        
        string temp;
        
        if(sx[0] == '-'){
            start = 1;
            temp.push_back('-');
        }
        while(sx[end] == 0){
            --end;
        }
        
        for(int i = end; i >= start; --i){
            temp.push_back(sx[i]);
        }
        
        long long result;
        stringstream ss;
        ss << temp;
        ss >> result;
        if(result > INT_MAX || result < INT_MIN)
            return 0;
        return result;
        
    }
};
