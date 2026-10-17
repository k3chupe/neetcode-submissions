class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack <int> index;
        int ans = 0;
        index.push(0);
        for (int i = 1;i < n;i++){
            while (!index.empty() && heights[index.top()] > heights[i]){
                int hig = heights[index.top()];
                index.pop();
                int temp;
                if (index.empty()){
                    temp = 0;
                }
                else{
                    temp = index.top()+1;
                }
                ans = max(hig * (i - temp), ans);
                //cerr << heights[index.top()] * (i - index.top()) << " " << heights[index.top()] << " " << i << " " << index.top()<< endl;
            }
            index.push(i);
        }
        while (!index.empty()){
             
            int hig = heights[index.top()];
            index.pop();
            int temp;
            if (index.empty()){
                temp = 0;
            }
            else{
                temp = index.top()+1;
            }
            ans = max(hig * (n - temp), ans);
            //cerr << heights[index.top()] * (i - index.top()) << " " << heights[index.top()] << " " << i << " " << index.top()<< endl;
            if (index.empty())break;
            
        }
        return ans;
    }
};
