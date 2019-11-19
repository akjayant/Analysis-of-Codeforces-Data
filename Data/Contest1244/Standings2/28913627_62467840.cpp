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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int mi = -1, ma = -1;
        for(int i=0;i<n;i++) {
            if(s[i] == '1') {
                if(mi == -1) {
                    mi = i;
                }
                ma = i;
            }
        }
        if(mi == -1) {
            cout<<n<<endl;
            continue;
        }
        cout<<max((ma + 1) * 2, ((n - mi) * 2))<<endl;
    }
}
