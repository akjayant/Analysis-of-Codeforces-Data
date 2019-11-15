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
    int n,a,b,c;
    string S;
    /// R P S
    cin >> n >> a >> b >> c;
    cin >> S;
    S = ' ' + S;
    char kq[105];
    int dem = 0;
    FOR(i,1,n)
    {
        kq[i] = '0';
        if(S[i] == 'R')
        {
            if(b > 0)
            {
                b--;
                kq[i] = 'P';
            }
        }
        else if(S[i] == 'P')
        {
            if(c > 0)
            {
                c--;
                kq[i] = 'S';
            }
        }
        else
        {
            if(a > 0)
            {
                a--;
                kq[i] = 'R';
            }
        }
        if(kq[i] != '0') dem++;
    }
    if(dem >= (n+1)/2)
    {
        cout << "YES\n";
        FOR(i,1,n)
        {
            if(kq[i] == '0')
            {
                if(a > 0)
                {
                    kq[i] = 'R';
                    a--;
                }
                else if(b > 0)
                {
                    kq[i] = 'P';
                    b--;
                }
                else
                {
                    kq[i] = 'S';
                    c--;
                }
            }
            cout << kq[i];
        }
        cout << '\n';
    }
    else cout << "NO\n";
}
int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);
    nhap();
    while(T--) xuli();
}
