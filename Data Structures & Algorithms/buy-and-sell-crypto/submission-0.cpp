class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 1000000;
        int odp = 0;
        for (int i = 0;i < prices.size();i++){
            if (prices[i] < mini) mini = prices[i];
            odp = max(odp, prices[i] - mini);
        }
        return odp;
    }
};
