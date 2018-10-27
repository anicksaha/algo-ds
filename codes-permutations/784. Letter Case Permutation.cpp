class Solution {
public:   
    vector<string> ANS;
    
    void getAns(string& S,int L,int R) {
        if(L>R) {
            ANS.push_back(S);
            return;
        }
        
        if(isupper(S[L]) || islower(S[L])) {
            getAns(S,L+1,R); // original
            S[L] = islower(S[L]) ? toupper(S[L]) : tolower(S[L]); 
            getAns(S,L+1,R); // changed
        } else {
            getAns(S,L+1,R); // original
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        getAns(S,0,S.length()-1);
        return ANS;
    }
};
