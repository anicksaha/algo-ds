#include<bits/stdc++.h>
using namespace std;

int arr[200010],tmp[200010];
int ans;
long long int INVCNT;

void merge(int min,int mid,int max)
{
    int i,j,k,m;
    j=min;
    m=mid+1;

    for(i=min; j<=mid && m<=max ; i++)
    {
        if(arr[j]<=arr[m])
        {
            tmp[i]=arr[j];
            j++;
        }
        else
        {
            INVCNT+=(mid-j)+1;
            tmp[i]=arr[m];
            m++;
        }
    }
    if(j>mid)
    {
        for(k=m; k<=max; k++)
        {
            tmp[i]=arr[k];
            i++;
        }
    }
    else
    {
        for(k=j; k<=mid; k++)
        {
            tmp[i]=arr[k];
            i++;
        }
    }

    for(k=min; k<=max; k++)
        arr[k]=tmp[k];
}





void part(int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(min,mid);
   part(mid+1,max);
   merge(min,mid,max);
 }
}



int main()
{
    int t;
    scanf("%d",&t);
    int i, j;
    while(t--)
    {
        int n,k,ans;
        scanf("%d",&n);

        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);

        INVCNT=0;

        part(1, n); // Merge Sort

        cout<<INVCNT<<endl;

    } // TC

    return 0;
}







