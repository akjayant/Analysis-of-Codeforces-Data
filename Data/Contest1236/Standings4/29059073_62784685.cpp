#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1e5+5;

int a[sz],ans[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int x,y,z;
        cin >> x >> y >> z;

        int ans=0;

        int now=min(z/2,y);
        ans+=3*now;
        y-=now;

        now=min(y/2,x);
        ans+=3*now;

        cout << ans << endl;
    }
}
