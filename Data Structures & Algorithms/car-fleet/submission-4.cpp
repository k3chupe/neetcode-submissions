class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> position_to_speed(n);
        for (int i = 0;i < n;i++){
            position_to_speed[i] = {position[i],speed[i]};
        }
        sort(position_to_speed.rbegin(),position_to_speed.rend());
        int rest = 1;
        double cur = (target - position_to_speed[0].first) / (double) position_to_speed[0].second;
        for (int i = 1;i < n;i++){
            double temp = (target - position_to_speed[i].first) / (double) position_to_speed[i].second;

            if (cur < temp){
                rest ++;
                cur = temp;
            }
        }
        return rest;
    }
};
