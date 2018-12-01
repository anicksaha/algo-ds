#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

char s[100005];
int main()
{
    //string s;
    vector<int> count(4);
    vector<int> mask(4);
    int n,l;
    scanf("%d",&n);
    scanf("%s",s);
    string nik="";
    l=strlen(s);

    for(int i=0;i<l;i++)
        count[s[i]-'A']++;
    for(int i=0;i<4;i++)
        mask[i]=n-count[i];

    for(int i=0;i<l;i++)
    {
        if(s[i]=='A')
        {

            bool foo=false;
            int q= min(mask[1],min(mask[2],mask[3]));
            A:

            if(mask[1]!=0 && q==mask[1])
            {
                nik+="B";
                mask[1]--;
                foo=true;
            }
            else if(mask[2]!=0 && q==mask[2])
            {
                nik+="C";
                mask[2]--;
                foo=true;
            }
            else if(mask[3]!=0 && q==mask[3])
            {
                nik+="D";
                mask[3]--;
                foo=true;
            }

            if(!foo)
            {
               q++;
               goto A;
            }

        }

        else if(s[i]=='B')
        {

            bool foo=false;
            int q= min(mask[0],min(mask[2],mask[3]));

            B:


            if(mask[3]!=0 && q==mask[3])
            {
                nik+="D";
                mask[3]--;
                foo=true;
            }
            else if(mask[2]!=0 && q==mask[2])
            {
                nik+="C";
                mask[2]--;
                foo=true;
            }
            else if(mask[0]!=0 && q==mask[0])
            {
                nik+="A";
                mask[0]--;
                foo=true;
            }

            if(!foo)
            {
               q++;
               goto B;
            }
        }
        else if(s[i]=='C')
        {

            bool foo=false;
            int q= min(mask[1],min(mask[0],mask[3]));

            C:

            if(mask[1]!=0 && q==mask[1])
            {
                nik+="B";
                mask[1]--;
                foo=true;
            }
            else if(mask[3]!=0 && q==mask[3])
            {
                nik+="D";
                mask[3]--;
                foo=true;
            }
            else if(mask[0]!=0 && q==mask[0])
            {
                nik+="A";
                mask[0]--;
                foo=true;
            }

            if(!foo)
            {
               q++;
               goto C;
            }
        }
        else if(s[i]=='D')
        {

            bool foo=false;
            int q= min(mask[1],min(mask[2],mask[0]));

            D:

            if(mask[1]!=0 && q==mask[1])
            {
                nik+="B";
                mask[1]--;
                foo=true;
            }
            else if(mask[2]!=0 && q==mask[2])
            {
                nik+="C";
                mask[2]--;
                foo=true;
            }
            else if(mask[0]!=0 && q==mask[0])
            {
                nik+="A";
                mask[0]--;
                foo=true;
            }

            if(!foo)
            {
               q++;
               goto D;
            }
        }
    } //

    cout<<nik<<endl;
}
