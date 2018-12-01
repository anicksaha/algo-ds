#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long int a[20010];
long long int ans, diff[2000000];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,ans;
        cin>>n>>k;
        int foo=n+1;
        foo-=k;
        //vector<int> diff;
        int i;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sort(&a[1],&a[n+1]);

        i=1;


        for(int j=1;j<=foo;j++)
        {

            //cout<<a[i]<<" - "<<a[i+k-1]<<endl;
            //cout<<a[i+k-1]-a[i]<<endl;
            diff[j]=a[i+k-1]-a[i];
            //cout<<diff[j]<<endl;
            i++;
        }

        /*for(int j=1;j<=foo;j++)
        {
            cout<<diff[j]<<" ";
        }*/

        //cout<<"\n";

        ans=*min_element(&diff[1],&diff[foo+1]);
        cout<<ans<<endl;


    } // TC

    return 0;
}
