#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,len,ans=0;
    string s,s1;
    bool flag;
    char c1,c2;
    cin>>s;
    cin>>k;

    while(k--)
        s+='?';

    int l=s.length();

    for(int i=0;i<l;i++)
    {
        for(int j=i;j<l;j++)
        {
            s1=s.substr(i,j+1);
            int len=s1.length();

            if(len&1)
                continue;

            int low,high,mid;

            low=0;
            high=len/2;

            flag=true;
            while(high<len)
            {
                if(s1[low]!=s1[high] && s1[low]!='?' && s1[high]!='?')
                {
                    flag=false;
                    break;
                }
                low++;
                high++;
            }

            if(flag)
                ans=max(ans,len);
        }
    }
    cout<<ans<<endl;
    return 0;
}
