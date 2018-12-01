/*
    anick saha
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>
#include<fstream>

using namespace std;

#define ll long long int

int maxVal,n;

int tree[350][350]; 

int read(int idx, int idy)
{
    int x,y,z;
    int sum=0;
    //x=idx;
    while(idx>0)
    {
        y=idy;
        while(y>0)
        {
            sum+=tree[idx][y];
            y-=y&-y;
        }
        idx-=idx&-idx; //
    } 
    
    return sum;
}

void update(int idx,int idy,int val)
{
    int x,y,z;
    //x=idx;
    while(idx<=n)
    {
        y=idy;
        while(y<=n)
        {
            tree[idx][y]++;
            y+=y&-y;
        }
        idx+=idx&-idx; //
    } 
}


int a[350][350];


int main()
{
    
    freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);

    int n,foo;
    scanf("%d",&n);
    int mask[11];
    memset(mask,0, sizeof(mask));
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&foo);
            mask[foo]++;
            int cnt=0;
            for(int k=1;k<=10;k++)
                if(mask[k]>0)
                    cnt++;
                    
            update(i,j,cnt);
        }
    
    int q;
    scanf("%d",&q);
    int a,b,c,d,ans;
    int x1,x2,y1,y2;
    
    while(q--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        
        a=read(x2,y2);
        b=read(x1-1,y1-1);
        c=read(x2,y1-1);
        d=read(x1-1,y2); 
        
        ans=a-(c+d) + b;
         
        printf("%d\n",ans);
    } // TC

    return 0;
}
