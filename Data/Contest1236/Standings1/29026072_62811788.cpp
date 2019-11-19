#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll=long long;
const int N = 1e5+5;

int n,m,k;
vector<int> row[N], col[N];

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin>>n>>m>>k;
    for (int i=1; i<=k; ++i) {
        int x,y; cin>>x>>y;
        row[x].push_back(y);
        col[y].push_back(x);
    }
    for (int i=1; i<=n; ++i) {
        row[i].push_back(0);
        row[i].push_back(m+1);
        sort(all(row[i]));
    }
    for (int i=1; i<=m; ++i) {
        col[i].push_back(0);
        col[i].push_back(n+1);
        sort(all(col[i]));
    }

    int curd=0, curx=1, cury=1;
    int mnr=0, mxr=n+1, mnc=0, mxc=m+1;
    ll cnt=1, bound=(ll)n*(ll)m-(ll)k;
    bool rotated=false;
    while (cnt<bound) {
        if (curd==0) {
            int nxt=min(*upper_bound(all(row[curx]), cury), mxc)-1;
            if (nxt==cury) {
                if (rotated) break;
                curd=1; rotated=true;
            } else {
                cnt+=(ll)(nxt-cury);
                cury=nxt;
                mnr=max(mnr, curx);
                rotated=false;
            }
        } else if (curd==1) {
            int nxt=min(*upper_bound(all(col[cury]), curx), mxr)-1;
            if (nxt==curx) {
                if (rotated) break;
                curd=2; rotated=true;
            } else {
                cnt+=(ll)(nxt-curx);
                curx=nxt;
                mxc=min(mxc, cury);
                rotated=false;
            }
        } else if (curd==2) {
            int nxt=max(*(--lower_bound(all(row[curx]), cury)), mnc)+1;
            if (nxt==cury) {
                if (rotated) break;
                curd=3; rotated=true;
            } else {
                cnt+=(ll)(cury-nxt);
                cury=nxt;
                mxr=min(mxr, curx);
                rotated=false;
            }
        } else {
            int nxt=max(*(--lower_bound(all(col[cury]), curx)), mnr)+1;
            if (nxt==curx) {
                if (rotated) break;
                curd=0; rotated=true;
            } else {
                cnt+=(ll)(curx-nxt);
                curx=nxt;
                mnc=max(mnc, cury);
                rotated=false;
            }
        }
    }

    if (cnt==bound) cout<<"Yes";
    else cout<<"No";
    return 0;
}