#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int arr[100001];
long long int a1[100001];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i]);

        int ctr=0;
        long long int maxsum,currsum;
        long long int nik=0;

        a1[1]=maxsum=currsum=arr[1];
       if(currsum==0)
       nik++;
        long long int c=1;

        for(int i=2;i<=n;i++)
        {

            if(currsum<0)
            {
                currsum=arr[i];
                nik=0;
            }

            else
            {
                currsum+=arr[i];
            }





            if(currsum>maxsum)
            {
                maxsum=currsum;
                c=nik+1;
            }

            else if( currsum==maxsum)
            {
                c+=nik+1;
            }

            if(currsum==0)
            {
               nik++;
            }

            //a1[i]=maxsum;
        }



        cout<<maxsum<<" "<<c<<endl;


    } // TC
}
