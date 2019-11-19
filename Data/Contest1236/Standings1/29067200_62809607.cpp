#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m, k;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
vector<int> posx[100005], posy[100005];
void init(){
    n = read(), m = read(), k = read();
    for (int i = 1; i <= k; ++i){
        int xx = read(), yy = read();
        posx[xx].push_back(yy);
        posy[yy].push_back(xx);
    }
    for (int i = 1; i <= n; ++i)
        if (!posx[i].empty())
            sort(posx[i].begin(), posx[i].end());
    for (int i = 1; i <= m; ++i)
        if (!posy[i].empty())
            sort(posy[i].begin(), posy[i].end());
}
int queryx(int xid, int l, int r, int o){
    if (posx[xid].empty()) return -1;
    if (o == 1){
        // ->
        int dd = lower_bound(posx[xid].begin(), posx[xid].end(), l) - posx[xid].begin();
        if (dd >= 0 && dd < posx[xid].size() && posx[xid][dd] <= r)
            return posx[xid][dd];
        else return -1;
    }else {
        int dd = upper_bound(posx[xid].begin(), posx[xid].end(), r) - posx[xid].begin();
        --dd;
        if (dd >= 0 && dd < posx[xid].size() && posx[xid][dd] >= l)
            return posx[xid][dd];
        else return -1;
    }
}
int queryy(int yid, int l, int r, int o){
    if (posy[yid].empty()) return -1;
    if (o == 1){
        // ->
        int dd = lower_bound(posy[yid].begin(), posy[yid].end(), l) - posy[yid].begin();
        if (dd >= 0 && dd < posy[yid].size() && posy[yid][dd] <= r)
            return posy[yid][dd];
        else return -1;
    }else {
        int dd = upper_bound(posy[yid].begin(), posy[yid].end(), r) - posy[yid].begin();
        --dd;
        if (dd >= 0 && dd < posy[yid].size() && posy[yid][dd] >= l)
            return posy[yid][dd];
        else return -1;
    }
}
void solve(){
    int dir = 0, up_bd = 0, down_bd = n + 1, left_bd = 0, right_bd = m + 1;
    ll cnt = 0;
    for (; ; ){
        //cout << up_bd << "  " << down_bd << "  " << left_bd << "  " << right_bd << endl;
        if (dir == 0){
            int curx = up_bd + 1, cury = left_bd;
            if (curx == 1 && cury == 0) cury = 1;    // (0, 0)
            int tary = right_bd - 1;
            if (tary < cury)
                break;
            int res = queryx(curx, cury + 1, tary, 1);
            if (res != -1)
                tary = res - 1, right_bd = res;
            if (tary < cury)
                break;
            dir = 1, ++up_bd;
            if (tary - cury != 0)
                cnt += 1ll * (tary - cury);
            else {
                if (curx != 1 || cury != 1){
                    ++cnt;
                    break;
                }
            }
        }else if (dir == 1){
            int curx = up_bd, cury = right_bd - 1;
            int tarx = down_bd - 1;
            if (tarx < curx)
                break;
            int res = queryy(cury, curx + 1, tarx, 1);
            if (res != -1)
                tarx = res - 1, down_bd = res;
            if (tarx < curx)
                break;
            dir = 2, --right_bd;
            if (tarx - curx != 0)
                cnt += 1ll * (tarx - curx);
            else {
                ++cnt;
                break;
            }
        }else if (dir == 2){
            int curx = down_bd - 1, cury = right_bd;
            int tary = left_bd + 1;
            if (tary > cury)
                break;
            int res = queryx(curx, tary, cury - 1, -1);
            if (res != -1)
                tary = res + 1, left_bd = res;
            if (tary > cury)
                break;
            dir = 3, --down_bd;
            if (cury - tary != 0)
                cnt += 1ll * (cury - tary);
            else {
                ++cnt;
                break;
            }
        }else {
            int curx = down_bd, cury = left_bd + 1;
            int tarx = up_bd + 1;
            if (tarx > curx)
                break;
            int res = queryy(cury, tarx, curx - 1, -1);
            if (res != -1)
                tarx = res + 1, up_bd = res;
            if (tarx > curx)
                break;
            dir = 0, ++left_bd;
            if (curx - tarx != 0)
                cnt += 1ll * (curx - tarx);
            else {
                ++cnt;
                break;
            }
        }
        //cout << cnt << endl;
    }
    if (cnt == 1ll * n * m - k)
        printf("Yes\n");
    else printf("No\n");
}
int main(){
    init();
    solve();
    return 0;
}