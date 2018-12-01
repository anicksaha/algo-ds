
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>


using namespace std;

//int arr[1000001];

int main()
{
    int t,n,m;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);

        vector<int> arr(n);
        //cout<<n<<m<<endl;

        for(int k=0;k<n;k++)
            scanf("%d",&arr[k]);

        //cin>>arr[k];
        sort(arr.begin(),arr.end());

        /*
        for(int k=0;k<n;k++)
            cout<<arr[k]<<" "<<endl;
        */

        int ans=0;
        int i=0;
        int j=(n-1);

        while(i<j)
        {
            //cout<<"$"<<endl;
            if(arr[i]+arr[j]==m)
            {
                ans++;
                //i++;
                j--;
            }

            else if(arr[i]+arr[j]<m)
                i++;

            else if(arr[i]+arr[j]>m)
                j--;
        }

        printf("%d\n",ans);

    } // TC

    return 0;

} // Main
