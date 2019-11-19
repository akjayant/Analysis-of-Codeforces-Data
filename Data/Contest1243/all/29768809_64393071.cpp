#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
#define maxn 1000000
int pri[maxn+5];
void getPrime()
{
    int i,j;
    for (i=2;i<=maxn;i++)
    {
        if (pri[i]==0) pri[++pri[0]]=i;
        for (j=1;j<=pri[0] && pri[j]<=maxn/i;j++)
        {
            pri[pri[j]*i]=1;
            if (i%pri[j]==0) break;
        }
    }
}

int main()
{
    cin>>n;
    getPrime();
    vector<ll> v;
    for (int i=1;i<=pri[0];i++)
    {
        if (n%pri[i]==0)
        {
            v.push_back(pri[i]);
            while (n%pri[i]==0) n/=pri[i];
        }
    }
    if (n!=1) v.push_back(n);
    if (v.size()>=2) printf("1\n");
    else if (v.size()==1) printf("%I64d\n",v[0]);
    else printf("1\n");
    return 0;
}
