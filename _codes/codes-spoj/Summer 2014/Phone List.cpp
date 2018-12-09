//prefix tree, trie

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct trie
{
    trie *next[10];
    bool end;
    trie()
    {
        for(int i=0; i<10; i++)
            next[i] = NULL;
        end=false;
    }
};

int main()
{
    int t, n, i, p;
    char str[15];
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        trie *head, *tail;
        head = new trie;
        flag = 1;
        while(n--)
        {
            scanf("%s", str);
            if(flag)
            {
                tail = head;
                for(i=0; str[i]; i++)
                {
                    if(tail->end)  // if any other string is a sub of the present
                    {
                        flag = 0;
                        break;
                    }

                    p = str[i]-'0';

                    if(tail->next[p]==NULL)
                        tail->next[p] = new trie;

                    tail = tail->next[p];
                } //for

                tail->end =1; // in context of present string

                for(i=0; i<10; i++) // checks if the present string is a sub of any other string
                {
                    if(tail->next[i])
                    {
                        flag = 0;
                        break;
                    }
                }

            } // if(flag)

        }  //

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    } // TC

    return 0;
}

