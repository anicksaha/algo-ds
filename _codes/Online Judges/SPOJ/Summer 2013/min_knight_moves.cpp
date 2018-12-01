#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct node
{
  int x,y,c;
};

bool visited[8][8];

int bfs( node s, node t )
{
    queue< node > q;
    q.push( s );
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        if(s.x < 0 || s.x > 7 || s.y < 0 || s.y > 7 )
            continue;

        if(s.x == t.x && s.y == t.y )
            return s.c;


        q.push( ( node ) { s.x + 2, s.y + 1, s.c + 1 } );
        q.push( ( node ) { s.x + 2, s.y - 1, s.c + 1 } );
        q.push( ( node ) { s.x + 1, s.y + 2, s.c + 1 } );
        q.push( ( node ) { s.x - 1, s.y + 2, s.c + 1 } );
        q.push( ( node ) { s.x + 1, s.y - 2, s.c + 1 } );
        q.push( ( node ) { s.x - 1, s.y - 2, s.c + 1 } );
        q.push( ( node ) { s.x - 2, s.y - 1, s.c + 1 } );
        q.push( ( node ) { s.x - 2, s.y + 1, s.c + 1 } );
    }
}

int main()
{
    char s[3],t[ 3 ];
    int tc;
    node foo,bar;
    cin>>tc;
    while(tc--)
    {
        memset(visited, false, sizeof(visited));
        scanf( "%s %s", s, t );
        foo.x=s[ 0 ] - 'a';
        foo.y=s[ 1 ] - '1' ;
        foo.c=0;
        bar.x=t[ 0 ] - 'a';
        bar.y=t[ 1 ] - '1' ;
        bar.c=0;
        //cout<<foo.x<<" "<<foo.y<<endl;
        printf( "%d\n", bfs(foo,bar));
    }

    return 0;
}
