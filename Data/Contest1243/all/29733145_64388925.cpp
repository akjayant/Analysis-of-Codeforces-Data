                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;

void nhap()
{
    int n;
    cin>>n;
    int kq=n;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            {
                kq=min(kq,__gcd(kq,i));
                kq=min(kq,__gcd(kq,n/i));
            }
    }
    cout<<kq;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Zo".inp","r",stdin);
//    freopen(Zo".out","w",stdout);
    nhap();
}
