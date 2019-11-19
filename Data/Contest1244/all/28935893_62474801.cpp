#include <iostream>

using namespace std;

int t,n, e,u;
char ch;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        e = 10000; u = 0;
        for (int i=1; i<=n; i++) {
            cin>>ch;
            if (ch == '1') {
                e = min(e, i);
                u = max(u, i);
            }
        }
        if (u == 0) cout<<n<<'\n';
        else cout<< 2*max(u, n-e+1) <<'\n';
    }

    return 0;
}
