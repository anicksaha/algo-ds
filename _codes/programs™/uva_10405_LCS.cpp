#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int table[1001][1001];

int LCS(string a, string b)
{

    memset(table, 0, sizeof(table));


    for(int i=1; i<=a.length(); i++)
        {
            for(int j=1; j<=b.length(); j++)
              {
                  if (a[i-1] == b[j-1])
                        table[i][j] = table[i-1][j-1] + 1;

                  else if(table[i][j-1]>=table[i-1][j])
                        table[i][j] = table[i][j-1];

                  else
                        table[i][j] = table[i-1][j];
              }
        }

    return table[a.length()][b.length()];
}



int main()
{

    string str1, str2;

    int t;
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        //getline(cin, str2);
        cout << LCS(str1, str2) << endl;
    }

    return 0;
}
