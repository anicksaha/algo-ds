// https://www.hackerrank.com/contests/hourrank-20/challenges/p-string

#include <bits/stdc++.h>
using namespace std;

typedef int ll;
const ll MOD = 1000000007;
const int N = 500010;

ll fact[N], invfact[N];

inline void add(ll &a, ll b, ll c) {
    a+=b;
    if (a>=c) {
        a-=c;
    }
}

/* this function calculates (a*b)%c taking into account that a*b might overflow */
inline ll mulmod_(ll a,ll b,ll c) {
    ll x=0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y+y)%c;
        b /= 2;
    }
    return x%c;
}

inline ll mulmod(ll a,ll b,ll c) {
    return (long long)a*b%c;
}

/* This function calculates (a^b)%c */
inline ll power(ll a,ll b,ll c) {
    ll x=1,y=a;
    while(b>0) {
        if(b%2 == 1) {
            x=mulmod(x,y,c);
        }
        y=mulmod(y,y,c);
        b /= 2;
	}
 	return x%c;
}

inline int inv(ll x, ll mod) {
    return power(x, mod - 2, mod);
}

inline void init() {
    fact[0] = 1;
    invfact[0] = 1;
    for(ll i = 1; i < N; i++) {
        fact[i] = mulmod(fact[i - 1], i, MOD);
        invfact[i] = mulmod(inv(i, MOD), invfact[i-1], MOD);
        //invfact[i] = inv(fact[i], MOD);
    }
}

inline ll nCr(ll n, ll r) {
    return mulmod(fact[n], mulmod(invfact[r], invfact[n -r], MOD), MOD);
}

ll getAns(ll a, ll b) {
  ll res = 0;
  for (int i = 0; i <= a && i <= b; i++) {
        add(res, mulmod(nCr(a, i), nCr(b, i), MOD), MOD);
  }
  return res;
}

int main() {
    init();
    string s;
    int t;
    scanf("%d", &t);
    while (t--) {
        cin>>s;
        vector <int> cnt(4, 0);
        for (int i = 0; i<s.length(); i++) {
            cnt[s[i] - 'a']++;
        }
        cout<< (mulmod(getAns(cnt[0], cnt[1]), getAns(cnt[2], cnt[3]), MOD) + MOD - 1) % MOD <<endl;
    }
    return 0;
}
