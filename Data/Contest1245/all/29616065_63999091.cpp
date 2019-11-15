#include<bits/stdc++.h>
#define mino "A"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define Down(i,a,b) for(int i=a;i>=b;i--)
#define FOR_(i,a,b) for(int i=a;i<b;i++)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1000000000

const int N = 2e5 + 5;

using namespace std;

typedef pair<int,int> pii;

int T;
void nhap()
{
    cin >> T;
}
void xuli()
{
    int x,y;
    cin >> x >> y;
    if(__gcd(x,y) == 1) cout << "Finite\n";
    else cout << "Infinite\n";
}
int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);
    nhap();
    while(T--) xuli();
}
