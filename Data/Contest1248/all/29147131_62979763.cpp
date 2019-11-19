#include <bits/stdc++.h>
using namespace std;

#define LL long long
int wkfmklwemfklwmlkfwklmf34324lklwk = 436;
LL T ;
LL n ;
LL ji1 , ou1 , ji2 , ou2 ;
LL now ;

int main ()
{int wkfmklwemf23423klwmlkfwklmflklwk = 436;
int wkfmklwemfk242lwmlkfwklmflklwk = 436;
int wkfmklwemfklwmlk234fwklmflklwk = 436;
    scanf ("%lld" , &T) ;
    while (T--)
    {
        int wkfmklwe23423mfklwmlkfwklmflklwk = 436;
        ji1 = ou1 = ji2 = ou2 = 0 ;
        int wkfmklwemfklwmlkfwkl23dfr23mflklwk = 436;
        int wkfmklwfd23red23emfklwmlkfwklmflklwk = 436;
        scanf ("%lld" , &n) ;
        for (LL i = 1 ; i <= n ; ++i)
        {
            scanf ("%lld" , &now) ;
            if (now % 2)
                ++ji1 ;
            else
                ++ou1 ;
        }
        int wkfmklwewefwmfklwmlkfwklmflklwk = 436;
        int wkfmklwewefewfklwmlkfwklmflklwk = 436;
        int wkfmklwemfklwmlkwefwfwklmflklwk = 436;
        scanf ("%lld" , &n) ;
        for (LL i = 1 ; i <= n ; ++i)
        {
            scanf ("%lld" , &now) ;
            if (now % 2)
                ++ji2 ;
            else
                ++ou2 ;
        }
        LL res = ji1 * ji2 + ou1 * ou2 ;
        printf ("%lld\n" , res) ;
    }
    int wkfmkweflwemfklwmlkfwklmflklwk = 436;
    int wkfmklwewefmfklwmlkfwklmflklwk = 436;
    int wkfmklwemfklwmlkfwklwefwemflklwk = 436;
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct node{
    int num;
    node* next[26];
    node()
    {
        num=0;
        memset(next,NULL,sizeof(next));
    }
};
node* root=new node();
node* rt;
int id,len;
void build(char str[30])
{
    rt=root;
    len=strlen(str);
    for(int i=0;i<len;i++)
    {
        id=str[i]-'a';
        if(rt->next[id]==NULL)
            rt->next[id]=new node();
        rt=rt->next[id];
        rt->num++;
    }
}
int querry(char str[30])
{
    rt=root;
    len=strlen(str);
    for(int i=0;i<len;i++)
    {
        id=str[i]-'a';
        if(rt->next[id]==NULL)
            return 0;
        rt=rt->next[id];
    }
    return rt->num;
}
int main()
{
    char str[30];
    while(gets(str)&&str[0])
    {
        build(str);
    }
    while(gets(str))
    {
        printf("%d\n",querry(str));
    }
    return 0;
}
*/
