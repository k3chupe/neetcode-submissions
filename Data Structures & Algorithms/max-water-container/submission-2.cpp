class Solution {
public:
    int maxArea(vector<int>& height) {
        int odp = 0;
        int l = 0;
        int p = height.size()-1;
        while (l < p){
            odp = max(min(height[l],height[p])*(p-l),odp);
            if (height[l] >= height[p]){
                p--;
            }
            else{
                l++;
            }
        }
        return odp;
    }
};