
#include<iostream>

using namespace std;


int main()

{

    int temp,N,m,x1,x2,y1,y2;

    while ( cin>>N )

    {

          int MAT[108][108],V[108][108]={0};

          for( int i=1;i<=N;i++ )
               for ( int j=1;j<=N;j++ )
                   cin>>MAT[i][j];

          for ( int i=1;i<=N;i++)
              for (int j=1;j<=N;j++)
                  for (int k=1;k<=i;k++)
                      for( int l=1;l<=j;l++)
                           V[i][j]=V[i][j]+MAT[k][l];


          m=V[0][0];


          for (x1=1;x1<=N;x1++)
              for (y1=1;y1<=N;y1++)
                  for (x2=x1;x2<=N;x2++)
                      for (y2=y1;y2<=N;y2++)
                      {
                          temp=V[y2][x2]-V[y2][x1-1]-V[y1-1][x2]+V[y1-1][x1-1];
                          m=max(m,temp);
                      }



          cout<<m<<endl;


          }


    return 0;



}