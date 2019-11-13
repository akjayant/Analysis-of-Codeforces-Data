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

ll F[N], MOD = 1e9 + 7;
string S;
void nhap()
{
    cin >> S;
    F[0] = 1;
    F[1] = 1;
    FOR(i,2,S.size()+1)
    {
        F[i] = (F[i-1] + F[i-2]) % MOD;
    }
}
void xuli()
{
    int d1 = 0, d2 = 0;
    ll res = 1;
    FOR_(i,0,S.size())
    {
        if(S[i] == 'm' || S[i] == 'w')
        {
            cout << "0\n";
            return;
        }
        if(S[i] == 'u') d1++;
        else d1 = 0;
        if(S[i] == 'n') d2++;
        else d2 = 0;

        if(S[i] == 'u' && (i == S.size()-1 || S[i] != S[i+1]))
        {
            res = (res * F[d1]) % MOD;
        }
        if(S[i] == 'n' && (i == S.size()-1 || S[i] != S[i+1]))
        {
            res = (res * F[d2]) % MOD;
        }
    }
    cout << res << '\n';
}
int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);
    nhap();
    xuli();
}
