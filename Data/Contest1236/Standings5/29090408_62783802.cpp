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
const int nmax = 2E5 + 5;
int t = 1;


void INPUT()
{
    cin >> t;
}


void INIT()
{

}

int a,b,c;

void SOLVE()
{
    cin >> a >> b >> c;
    int res = 0;
    while (b > 0 && c >= 2) {
        res += 3;
        b--;
        c -= 2;
    }

    while (a > 0 && b >= 2) {
        res +=3;
        a--;
        b -= 2;
    }
    cout << res << endl;

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

