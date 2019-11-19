#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
set<long long> R[maxn], C[maxn];


struct Point{
    int r, c;
};
map<int, Point> M;
int n, m, k;
int main()
{
    cin>>n>>m>>k;
    for(int i = 1; i <= k; i++){
        int r, c;
        cin>>r>>c;
        R[r].insert(c);
        C[c].insert(r);
    }
    long long r1 = 0, r2 = n+1, c1 = 0, c2 = m+1;
    Point u;
    u.r = 1; u.c = 1;
    int s = 0;
    long long num = 0;
    M[3].r = 1e9;
    while(1){
        //cout<<s<<" "<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;

        if(s == 0){
            R[u.r].insert(c2);
            long long c = *R[u.r].upper_bound(u.c);
            if(c < c2){
                num += (r2 - r1 - 1) * (c2 - c);
            }
            c2 = min(c2, c);
            r1++;
            u.c = c2-1;
        } else if(s == 1){
            C[u.c].insert(r2);
            long long r = *C[u.c].upper_bound(u.r);
            if(r < r2){
                num += (c2 - c1 - 1) * (r2 - r);
            }
            r2 = min(r2, r);
            c2--;
            u.r = r2-1;
        } else if(s == 2){
            R[u.r].insert(c1);
            long long c = *(--R[u.r].lower_bound(u.c));
            if(c > c1){
                num += (r2 - r1 - 1) * (c - c1);
            }
            c1 = max(c1, c);
            r2--;
            u.c = c1+1;
        } else {
            C[u.c].insert(r1);
            long long r = *(--C[u.c].lower_bound(u.r));
            if(r > r1){
                num += (c2 - c1 - 1) * (r - r1);
            }
            r1 = max(r1, r);
            c1++;
            u.r = r1+1;
        }
        if(M[(s-1+4)%4].r == u.r && M[(s-1+4)%4].c == u.c) break;
        M[s].r = u.r;
        M[s].c = u.c;
        if(r2 - r1 == 1 && c2 - c1 == 1) break;
        s = (s+1)%4;
    }
    if(num != k) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}