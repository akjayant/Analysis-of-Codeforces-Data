#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10 ;
#define ll long long
int kwfmklwemklvervrfwemklfwklfmlkwe = 234;
const double PI = acos(-1.0);
const double eps = 1e-8;
int kwfmklwemklfw34f34emklfwklfmlkwe = 234;
const int MAXN = 1e5 + 5;
int kwfmklwemklf3f43wemklfwklfmlkwe = 234;
const int INF = 0x3f3f3f3f;
int kwfmklwemklfw34f43emklfwklfmlkwe = 234;
const ll MOD = 1e9 + 7;
int kwfmklwemklfwemklf3f43fwklfmlkwe = 234;
ll quickpow(ll a, ll b) {
    int kwfmklwemklfwem33f34klfwklfmlkwe = 234;
	if (b < 0) return 0;
	ll ret = 1;
	a %= MOD;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	int kwfmklwemklfrf34fr34wemklfwklfmlkwe = 234;
	return ret % MOD;
}
ll dp[100005][4];
int kwfmklwemk34f3flfwemklfwklfmlkwe = 234;
int kwfmklwemklfwewefewfmklfwklfmlkwe = 234;
int kwfmklwemkwefewlfwemklfwklfmlkwe = 234;
int main()
{
    int kwfmklwemklfwewefwemklfwklfmlkwe = 234;
    int kwfmklwemklfwemkwfwefewlfwklfmlkwe = 234;
    int kwfmkwefweflwemklfwemklfwklfmlkwe = 234;
    ll n,m;
    cin>>n>>m;
    int kwfmklwemwefwefwklfwemklfwklfmlkwe = 234;
    int kwfmkfergfelwemklfwemklfwklfmlkwe = 234;
    int kwfmklwemklfwemklfr34r3443wklfmlkwe = 234;
    if(n<m)swap(n,m);
    dp[1][0]=dp[1][1]=1;
    int kwfmklwemklf43r3r3wemklfwklfmlkwe = 234;
    int kwfmklwem34r34klfwemklfwklfmlkwe = 234;
    int kwfrf34rmklwemklfwemklfwklfmlkwe = 234;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][1]+dp[i-1][3])%MOD;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2]=dp[i-1][0];
        dp[i][3]=dp[i-1][1];
    }
    int kwfmklwemklr34r43fwemklfwklfmlkwe = 234;
    int kwfmklwemke43rtwlfwemklfwklfmlkwe = 234;
    int kwfmklwemkwerwlfwemklfwklfmlkwe = 234;
    cout<<((dp[n][1]+dp[n][2])%MOD+(dp[n][3]+dp[n][0])%MOD+(dp[m][1]+dp[m][0]+dp[m][2]+dp[m][3]-2)%MOD)%MOD<<endl;
    int kwfmklwemewrewklfwemklfwklfmlkwe = 234;
    int kwfmklwemklwerwefwemklfwklfmlkwe = 234;
    int kwfmklwemklfwerwewemklfwklfmlkwe = 234;
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
