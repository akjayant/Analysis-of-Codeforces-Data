#define task "test"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define fs first
#define sc second
#define FOR(x,a,b) for (int x = a; x<=b; x++)
#define FOD(x,a,b) for (int x = b; x>=a; x--)
#define pb push_back

const int INF = 1E9;
const ll INFll = 1E16;
const int nmax = 300 + 5;
int t = 1;

int n;

void INPUT()
{
    cin >> n;
}


int a[nmax],cnt;
bool F[nmax];

vector <int> ans[nmax];

void INIT()
{

}


void SOLVE()
{
    cnt = 0;
    int tt = 0;
    for (int i=1; i<=n*n; i++) {

        if (tt == 0) {
            cnt++;
            if (cnt > n) {
                tt = 1;
                cnt--;
            }
            ans[cnt].pb(i);
        }
        else {
            cnt--;
            if (cnt == 0) {
                tt = 0;
                cnt++;
            }
            ans[cnt].pb(i);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<n; j++) cout << ans[i][j] <<" ";
        cout << endl;
    }

}

int main()
{
    if (fopen(task ".inp","r")){
        freopen(task ".inp","r",stdin);
        freopen(task ".out","w",stdout);
    }
    INPUT();
    INIT();
    while (t--) SOLVE();
}

