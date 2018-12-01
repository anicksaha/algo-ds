//http://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation
//en.wikipedia.org/wiki/Lyndon_word

// String Rotation

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int Booths_algo(string s)
{
    int i, j, k, n, len, p, q;
    len = n = s.length();
    i = 0, j = 1, k = 0;
    n=n*2; // overflow check
    // a n i c k
    // 0 1 2 3 4
    // k a n i c
    // 4 0 1 2 3

    while(i + k < n-2 && j + k < n-2)
    {
        p = i+k >= len ? s[i+k-len] : s[i+k];
        q = j+k >= len ? s[j+k-len] : s[j+k];

        if(p == q) k++;
        else if(p > q) { i = i+k+1; if(i <= j) i = j+1; k = 0; }
        else if(p < q) { j = j+k+1; if(j <= i) j = i+1; k = 0; }
    }
    return i < j ? i : j;
}

int main()
{
    string s;
    cin>>s;
    printf("%d\n",Booths_algo(s));
    return 0;
}

