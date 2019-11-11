///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

const int maxn = 0;

int32_t main(){
    int Q;
    cin >>Q;
    while(Q --){
        int n, r[3] = {0, 0, 0}, p[3] = {0, 0, 0}, s[3] = {0, 0, 0};
        cin >>n >>r[0] >>p[0] >>s[0];
        string ss = "";
        cin >>ss;
        for(int i = 0; i < n; i ++){
            if(ss[i] == 'R')
                r[1] ++;
            if(ss[i] == 'P')
                p[1] ++;
            if(ss[i] == 'S')
                s[1] ++;
        }
        int wr = min(r[0], s[1]), wp = min(p[0], r[1]), ws = min(s[0], p[1]);
        r[0] -= wr;
        s[1] -= wr;
        p[0] -= wp;
        r[1] -= wp;
        s[0] -= ws;
        p[1] -= ws;
        string ans = "";
        int cn = wr + wp + ws, er = min(r[0], r[1]), es = min(s[0], s[1]), ep = min(p[0], p[1]);
        for(int i = 0; i < n; i ++){
            if(ss[i] == 'S'){
                s[2] ++;
                if(s[2] <= wr)
                    ans += 'R';
                else if(s[2] - wr <= es)
                    ans += 'S';
                else
                    ans += 'P';
            }
            if(ss[i] == 'R'){
                r[2] ++;
                if(r[2] <= wp)
                    ans += 'P';
                else if(r[2] - wp <= er)
                    ans += 'R';
                else
                    ans += 'S';
            }
            if(ss[i] == 'P'){
                p[2] ++;
                if(p[2] <= ws)
                    ans += 'S';
                else if(p[2] - ws <= ep)
                    ans += 'P';
                else
                    ans += 'R';
            }
        }
        if(cn >= (n + 1)/ 2)
            cout <<"YES" <<' ' <<ans <<'\n';
        else
            cout <<"NO" <<'\n';

    }
    return false;
}
