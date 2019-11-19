#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef long long ll;

const int N = 1e5+5;
set<int> iToj[N];
set<int> jToi[N];

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<k;++i){
        int I,J;
        cin>>I>>J;
        iToj[I].insert(J);
        jToi[J].insert(I);
    }
    int mni = 0, mxi = n+1, mnj = 0, mxj = m+1;
    pair<int, int> pos = {1,1};
    int dir = 0;
    int cnt = 1;
    bool First = true;
    while(true) {
        assert(!iToj[pos.first].count(pos.second));//remove
        //cout << "here, cnt: " << cnt << endl;
        //cout << "here, pos: " << pos.first << ' '<< pos.second << endl;
        //cout << "bounds: "<< mni << ' ' << mnj << ' ' << mxi << ' ' << mxj << endl;
            //cout << "\n\n";
        if(dir == 0) {
            pair<int,int> next = pos;
            next.second = mxj-1;
            auto it = iToj[pos.first].upper_bound(pos.second);
            if(it != iToj[pos.first].end()) {
                next.second = min(next.second, *it-1);
            }
            if(next.second <= pos.second) {
                if(First) {
                    dir = (dir+1)%4;
                    First = false;
                    continue;
                }
                break;
            }
            cnt += next.second - pos.second;
            mxj = next.second;
            mni = next.first;
            pos = next;
        } else if(dir == 1) {


            pair<int,int> next = pos;
            next.first = mxi-1;
            auto it = jToi[pos.second].upper_bound(pos.first);
            if(it != jToi[pos.second].end()) {
                next.first = min(next.first, *it-1);
            }
            if(next.first <= pos.first) {
                //cout << "deuaslfj\n";
                break;
            }

            cnt += next.first - pos.first;
            mxi = next.first;
            mxj = next.second;
            pos = next;



        } else if(dir == 2) {
            pair<int,int> next = pos;
            next.second = mnj+1;
            auto it = iToj[pos.first].lower_bound(pos.second);
            if(it != iToj[pos.first].begin()) {
                --it;
                next.second = max(next.second, *it+1);
            }
            if(next.second >= pos.second) {

                break;
            }
            cnt += pos.second - next.second;
            mnj = next.second;
            mxi = next.first;
            pos = next;

        } else {
            pair<int,int> next = pos;
            next.first = mni+1;
            auto it = jToi[pos.second].lower_bound(pos.first);
            if(it != jToi[pos.second].begin()) {
                --it;
                next.first = max(next.first, *it+1);
            }
            if(next.first >= pos.first) {

                break;
            }
            cnt += pos.first - next.first;
            mni = next.first;
            mnj = next.second;
            pos = next;

        }
        dir = (dir+1)%4;
        First = false;
    }
    //cout << "cnt: " << cnt << endl;
    cout << (cnt + k == n*m ? "Yes":"No");
}
