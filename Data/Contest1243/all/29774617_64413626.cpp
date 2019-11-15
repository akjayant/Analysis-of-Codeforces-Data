#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N=100;
int n;
char s[N], t[N];
bool vs[N], vt[N];

void visit(int i) {vs[i]=vt[i]=true;}

int ops (vector<ii>& op) {
    int ans=0;
    bool yapari = true;
    while (yapari) {
        yapari=false;
        for (int i=1; i<=n; ++i) 
            if (!vs[i] && !vt[i] && s[i]==t[i]) visit(i);


        for (int i=1; i<=n; ++i)
            if (!vs[i]) {
                for (int j=1; j<=n; ++j)
                    if (!vt[j] && s[i]==t[j] && s[j] == t[i]) {
                        yapari=true;
                        ans+=2;
                        op.push_back({j,j}); swap(s[j], t[j]);
                        op.push_back({j,i}); swap(s[j], t[i]);
                        visit(i); visit(j);
                        break;
                    }
            }
        for (int i=1; i<=n; ++i)
            if (!vs[i]) {
                for (int j=i+1; j<=n; ++j)
                    if (!vs[j] && i!=j && s[i]==s[j]) {
                        yapari=true;
                        ans++;
                        op.push_back({j,i});
                        swap(s[j], t[i]);
                        visit(i);
                        if (s[j]==t[j]) visit(j);
                        break;
                    }
            }
        for (int i=1; i<=n; ++i)
            if (!vt[i]) {
                for (int j=i+1; j<=n; ++j)
                    if (!vt[j] && i!=j && t[i]==t[j]) {
                        yapari=true;
                        ans++;
                        op.push_back({i,j});
                        swap(s[i], t[j]);
                        visit(i);
                        if (s[j]==t[j]) visit(j);
                        break;
                    }
            }
    }
    for (int i=1; i<=n; ++i)
        if (!vs[i]) {
            bool virtue = false;
            for (int j=1; j<=n; ++j)
                if (!vt[j] && s[i]==t[j]) {
                    ans+=2;
                    op.push_back({j,j}); swap(s[j], t[j]);
                    op.push_back({j,i}); swap(s[j], t[i]);
                    visit(i); 
                    virtue = true;
                    break;
                }
            if (!virtue) return -1;
            int tmp = ops(op);
            if (tmp==-1) return -1;
            ans+=tmp;
        }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int k; cin>>k;
    while (k--) {
        cin>>n; for (int i=1; i<=n; ++i) cin>>s[i];
        for (int i=1; i<=n; ++i) cin>>t[i];
        fill(vs+1, vs+n+1, false); fill(vt+1, vt+n+1, false);
        vector<ii> op;
        int ans = ops(op);
        if (ans==-1 || ans>=2*n) {
            cout<<"No"<<endl;
        }
        else {
            cout<<"Yes"<<endl<<ans<<endl;
            for (auto x : op) cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}