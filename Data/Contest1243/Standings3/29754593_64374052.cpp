#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    while(q--) {
        int n, m=0; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        for(int i=0;i<n;i++)
            m=max(m,min(a[i],i+1));
        cout << m << endl;
    }
    return 0;
}
