// https://leetcode.com/problems/unique-morse-code-words/description/

class Solution {
public:
    
    string getMorseCode(string s) {
        string code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        string _code = "";
        for(int i=0;i<s.length();i++) {
            _code+=code[s[i]-'a'];
        }
        return _code;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> S;
        for(int i=0;i<words.size();i++) {
            S.insert(getMorseCode(words[i]));
        }
        
        return S.size();
    }
};