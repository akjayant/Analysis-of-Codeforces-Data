#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define pb push_back

typedef long long ll;
typedef pair<int,int> pi;
const int MAXN = (int)1e3+7;

char str[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cin >> str+1;
        int ans = N;
        rep(i,1,N) {
            if (str[i] == '1') {
                int n1 = (N-i+1);
                ans = max(ans,max(i*2,n1*2));
            }
        }
        cout << ans << endl;
    }
}
