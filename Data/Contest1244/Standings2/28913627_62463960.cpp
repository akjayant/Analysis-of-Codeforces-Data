#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        int x, y;
        x = a / c;
        if(a % c)
            x++;
        y = b / d;
        if(b % d)
            y++;
        if(x + y <= k) {
            cout<<x<<" "<<y<<endl;
        }
        else
            cout<<-1<<endl;
    }
}
