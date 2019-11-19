#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define pb push_back

typedef long long ll;
typedef pair<int,int> pi;
const int MAXN = (int)1e6+7;


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T --) {
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >>k;
        int n1 = (a+c-1)/c;
        int n2 = (b+d-1)/d;
        if (n1 + n2 > k) {
            cout << -1 << endl;
        }else {
            cout << n1 << " " << n2 << endl;
        }
    }

}
