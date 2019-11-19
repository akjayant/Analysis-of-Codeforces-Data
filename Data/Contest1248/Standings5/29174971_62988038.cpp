#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int aa;
        scanf("%d",&aa);
        a.push_back(aa);
    }
    sort(a.begin(),a.end());
    ll ant1=0;
    for(int i=0;i<n/2;i++)
    {
        ant1+=a[i];
    }
    ll ant2=0;
    for(int i=n/2;i<a.size();i++)
    {
        ant2+=a[i];
    }
    ll ant3=0;
    ant3=ant1*ant1+ant2*ant2;
    printf("%lld\n",ant3);
}
