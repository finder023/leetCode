#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size())
            return 0;
        int max = 0, min = INT32_MAX;
        int tmp;
        
        for (int i=1; i<prices.size(); ++i) {
            if (min > prices[i-1])
                min = prices[i-1];
            if ((tmp = prices[i] - min) > max)
                max = tmp;
        }
        return max;
    }
};

int main() {
    int buff[] = {7,1,5,3,6,4};
    Solution su;
    vector<int> data(buff, buff+6);
    int res = su.maxProfit(data);
    return 0;
}