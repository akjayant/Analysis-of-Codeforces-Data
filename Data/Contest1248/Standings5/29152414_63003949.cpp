#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<utility>
#include<set>
using namespace std;
long long int ch[100001];
long long int nxt[100001];
int main()
{
long long int n,m;
long long int cnt=0;
cin>>n>>m;
ch[1]=1;
ch[2]=2;
for(int i=3;i<=100000;i++)
{
    ch[i]=(ch[i-1]%1000000007+ch[i-2]%1000000007)%1000000007;
}

nxt[1]=ch[n];
nxt[2]=ch[n]+1;
for(int i=3;i<=m;i++)
{
    nxt[i]=(nxt[i-1]%1000000007+ch[i-2]%1000000007)%1000000007;
}
cout<<(nxt[m]*2)%1000000007;
return 0;
}
