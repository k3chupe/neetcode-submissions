class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>sta;
        int a, b;
        for (string s: tokens){
            cerr << s << endl; 
            if (s == "+" || s == "-" || s == "*" || s == "/"){
                b = sta.top();
                sta.pop();
                a = sta.top();
                sta.pop();
                if (s == "+"){
                    sta.push(a + b);
                }
                if (s == "-"){
                    sta.push(a - b);
                }
                if (s == "*"){
                    sta.push(a * b);
                }
                if (s == "/"){
                    cerr << a / b << endl; 
                    sta.push(a / b);
                }
            }
            else{
                sta.push(stoi(s));
            }
        }
        return sta.top();
    }
};