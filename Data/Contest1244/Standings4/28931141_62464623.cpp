#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int M = 200010;


int main() {

    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    while (t--) {
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        int x = (a/c) + (a%c != 0);
        int y = (b/d) + (b%d != 0);

        if (x + y > k) cout<<-1<<endl;
        else cout<<x<<" "<<y<<endl;
    }




    return 0;
}
