// https://leetcode.com/problems/number-of-segments-in-a-string/description/

class Solution {
public:
    bool isChar(char ch) {
        bool isUpper = (ch>=65 && ch<=90);
        bool isLower = (ch>=97 && ch<=122);
        return (isUpper || isLower);
    }
    
    bool isSpace(char ch) {
        return ch==' ';
    }
    
    int countSegments(string s) {
        int segments = 0;
        int idx = 0;
        
        while(idx<s.length()) {
            while(isSpace(s[idx]) && idx<s.length()) {idx++;}
            if(idx<s.length()) {segments++;}
            while(!isSpace(s[idx]) && idx<s.length()) {idx++;}
        }
        
        return segments;
    }
};