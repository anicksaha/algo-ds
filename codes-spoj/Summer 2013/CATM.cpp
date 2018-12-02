#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int r,c,k;
    int mouse_row, mouse_col, cat1_row, cat1_col, cat2_row, cat2_col;
    int mt,mr,ml,mb,ct,cr,cl,cb;

    cin>>r>>c>>k;

    while(k--)
    {
        scanf("%d%d%d%d%d%d",&mouse_row,&mouse_col,&cat1_row,&cat1_col,&cat2_row,&cat2_col);

        if(  (mouse_row>cat1_row && mouse_row>cat2_row)  || (mouse_row<cat1_row && mouse_row<cat2_row)
           ||(mouse_col>cat1_col && mouse_col>cat2_col)  || (mouse_col<cat1_col && mouse_col<cat2_col) )

        {
            printf("YES\n");
            continue;
        }

        mt=mouse_row-1;
        ct=min(abs(1-cat1_row)+abs(mouse_col-cat1_col),abs(1-cat2_row)+abs(mouse_col-cat2_col));

        ml=c-mouse_col;
        cl=min(abs(mouse_row-cat1_row)+abs(c-cat1_col),abs(mouse_row-cat2_row)+abs(c-cat2_col));

        mb=r-mouse_row;
        cb=min(abs(r-cat1_row)+abs(mouse_col-cat1_col),abs(r-cat2_row)+abs(mouse_col-cat2_col));

        mr=mouse_col-1;
        cr=min(abs(mouse_row-cat1_row)+abs(1-cat1_col),abs(mouse_row-cat2_row)+abs(1-cat2_col));

        if(mt<ct || mb<cb || ml<cl || mr<cr)
            printf("YES\n");
        else
            printf("NO\n");



    } // cases
}
