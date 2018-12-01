class Solution {
public:
    
    string _rev(string s) {
        reverse(s.begin(),s.end());
        return s;
    }
    
    bool isSpace(char ch) {
        return ch==' ';
    }
    
    string reverseString(string s) {
        stack<string> S;
        int idx = 0;
        
        while(idx<s.length()) {
            string tmp = "";
            while(!isSpace(s[idx]) && idx<s.length()) {tmp+=s[idx++];}
            S.push(_rev(tmp));
            tmp="";
            while(isSpace(s[idx]) && idx<s.length()) {tmp+=s[idx++];}
            S.push(_rev(tmp));
        }
        
        string ans = "";
        while(!S.empty()) {
            ans+=S.top();
            S.pop();
        }
        
        return ans;
    }
};