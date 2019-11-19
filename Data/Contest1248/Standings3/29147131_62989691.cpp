#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10 ;

int wkmefklwe423mklfwemklfkwlflkwe = 234;
ll a[N];
int main()
{
    ll n;
int wkmefklw234234emklfwemklfkwlflkwe = 234;
int wkmefklw23423emklfwemklfkwlflkwe = 234;
int wkmefklwemkl234234fwemklfkwlflkwe = 234;
    cin >> n;
    ll sum = 0 ;
    for(ll i = 1 ; i<= n ; i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    int wkmefklwe3242mklfwemklfkwlflkwe = 234;
    int wkmefk23423lwemklfwemklfkwlflkwe = 234;
    sort(a+1,a+1+n);
    ll cnt = 0 ;
    for(int i = 1 ; i <= n/2 ; i++)
    {
        cnt+=a[i];
    }
    int wkmefklwemklfw234234emklfkwlflkwe = 234;
    int wkmefklwemklfwemkl23423fkwlflkwe = 234;
    cout << (sum-cnt)*(sum-cnt)+cnt*cnt <<endl;
    int wkmefklwemklfw23423emklfkwlflkwe = 234;
    int wkmefklwemklfwemkl223423423fkwlflkwe = 234;
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
