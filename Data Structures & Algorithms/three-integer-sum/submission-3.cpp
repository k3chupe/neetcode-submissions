class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> odp;
        int n = nums.size();
        unordered_map<int,int> mapa;
        set<pair<int,pair<int,int>>> bann;
        for (int i = 0;i < n;i++){
            if (mapa.find(nums[i]) != mapa.end()) mapa[nums[i]] = i;
            mapa.insert({nums[i],i});
        }
        for (int i = 0;i < n;i++){
            for (int j = i+1;j < n;j++){
                if (mapa.find(-(nums[i] + nums[j])) != mapa.end()){
                    if (mapa[-(nums[i] + nums[j])] <= j) continue;
                    if (bann.find({nums[i],{nums[j],nums[mapa[-(nums[i] + nums[j])]]}}) != bann.end()) continue;
                    odp.push_back({nums[i],nums[j],nums[mapa[-(nums[i] + nums[j])]]});
                    bann.insert({nums[i],{nums[j],nums[mapa[-(nums[i] + nums[j])]]}});
                }
            }
        }
        return odp;
    }
};
