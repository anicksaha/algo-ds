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

int tree[50][50][50]; 
char a[50][50][50];
char b[50][50][50];
int dp[50][50][50];

int read(int idx, int idy, int idz)
{
    int x,y,z;
    int sum=0;
    //x=idx;
    while(idx>0)
    {
        y=idy;
        while(y>0)
        {
            z=idz;
            while(z>0)
            { 
                sum+=tree[idx][y][z];
                z-=z&-z;
            }
            y-=y&-y;
        }
        idx-=idx&-idx; //
    } 
    
    return sum;
}

void update(int idx,int idy,int idz,int val)
{
    int x,y,z;
    //x=idx;
    while(idx<=n)
    {
        y=idy;
        while(y<=n)
        {
            z=idz;
            while(z<=n)
            { 
                tree[idx][y][z]++;
                z+=z&-z;
            }
            y+=y&-y;
        }
        idx+=idx&-idx; //
    } 
}





int main()
{
    
    freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);


    
    int t;
    float p;
    
    
    scanf("%d",&t);
    
    while(t--)
    {
        
        scanf("%d%f",&n,&p);
        //cout<<n<<" "<<p<<endl;
        //maxVal=n;
        
        //memset(tree,0,sizeof(tree));
        
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    tree[i][j][k]=0;
              
        
        cin.ignore();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    scanf("%c",&a[i][j][k]);
                    
        cin.ignore();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                {
                    scanf("%c",&b[i][j][k]);
                    if(a[i][j][k]==b[i][j][k])
                            update(i+1,j+1,k+1,1);
                }
        
        //cin.ignore();  
        
        
        /*
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    cout<<a[i][j][k];
        cout<<endl;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    cout<<b[i][j][k];
        cout<<endl;
        */
        
        
        
        /*
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(a[i][j][k]==b[i][j][k])
                            update(i+1,j+1,k+1,1);
        */
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    dp[i][j][k]=read(i,j,k);
        
        
        //cout<<"foo"<<endl;
        
        int ans,match,size;
        
        for(int ii=n;ii>=1;ii--)//size of sub cubes
        {
            ans=0;
            
            for(int i=0;i+ii-1<n && i<n;i++)
                for(int j=0; j+ii-1<n && j<n;j++)
                    for(int k=0;k+ii-1<n && k<n; k++)// origin of each small cube
                    {
                        //match=0;
                        //ans=0;
                        //
                        //{
                            
                            int xx=i+ii-1;
                            int yy=j+ii-1;
                            int zz=k+ii-1;
                            
                            match=dp[xx+1][yy+1][zz+1]
                                    -dp[i][yy+1][zz+1]-dp[xx+1][j][zz+1]-dp[xx+1][yy+1][k]
                                    +dp[xx+1][j][k]+dp[i][yy+1][k]+dp[i][j][zz+1]
                                    -dp[i][j][k]; 


                        
                            
                            //float tt=ii+1;
                            double gg=(double)((double)match/(double)(ii*ii*ii));
                            gg=(gg*100);
                            
                            if(gg>=p)ans++;
                            
                            //cout<<gg<<" "<<p<<endl;
                            //cout<<i<<" "<<j<<" "<<k<<" match-> "<<match<<" % -> "<<gg<<" blocks till now-> "<<ans<<endl;
                            
                        //} // IF
                    
                    } // for K
                
                //cout<<"size-> "<<ii<<" count-> "<<ans<<endl;
                // size space
            
                if(ans!=0){ size=ii; break;}
                        
        } // # size of sub cubes
        
        if(ans==0)
            printf("-1\n");
        else
            printf("%d %d\n",size,ans);
        
    } // TC

    return 0;
}
