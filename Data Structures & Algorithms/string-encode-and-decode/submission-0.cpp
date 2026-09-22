class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (string a : strs){
            s += a + (char)2;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector <string> odp;
        string temp = "";
        for (int i = 0;i < s.size();i++){
            if (s[i] == 2){
                odp.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        return odp;
    }
};
