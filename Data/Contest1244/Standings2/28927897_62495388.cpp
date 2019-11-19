#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+100;
long long int a[N], mns, mxs, mx, mn, l, r;

int main () {
    ios::sync_with_stdio(0);
    long long int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0 ; i < n ; i++ ) {
        if(a[i]==a[0]) {
            mns++;
            l=i;
        }
        if(a[i]==a[n-1]) {
            mxs++;
            if(r==0)
                r=i;
        }
    }
    if(mns==n) {
        cout << 0;
        return 0;
    }
    mn=a[0];
    mx=a[n-1];
    /*for(int i = 0 ; i < n;  i++)
        cout << a[i] << ' ';
    cout << '\n';*/
    while(true) {
            //cout << k << ' ' << l << ' ' << r << ' ' << mns << ' ' << mxs << ' ' << mn << ' ' << mx << '\n';
        if(l==r) {
            cout << 0;
            return 0;
        }
        if(k==0||mn==mx) {
            cout << mx-mn;
            return 0;
        }
        if(mns<mxs) {
            long long int nex=a[l+1];
            long long int di=nex-a[l];
            if(mns*di>k) {
                cout << mx-mn-(k/mns);
                return 0;
            }
            else {
                k-=mns*di;
                long long int h = l;
                while(a[h+1]==a[l+1]&&l<r)
                    l++, mns++;
                mn=a[l];
            }
        }
        else {
            long long int pre=a[r-1];
            long long int di=a[r]-pre;
            if(mxs*di>k) {
                cout << mx-mn-(k/mxs);
                return 0;
            }
            else {
                k-=mxs*di;
                long long int h = r;
                while(a[h-1]==a[r-1]&&r>l)
                    r--, mxs++;
                mx=a[r];
            }
        }
    }
}
