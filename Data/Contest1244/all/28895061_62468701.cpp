#include<bits/stdc++.h>
#define Task ""

using namespace std;
char can[10005];

int main(){
    /*
	#ifndef ONLINE_JUDGE
	freopen(Task".inp","r",stdin);
	freopen(Task".out","w",stdout);
	#endif
	*/
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int q, n;
    cin >> q;
    while (q--){
        cin >> n;
        for(int i = 1; i<=n; ++i) cin >> can[i];
        int res = 0;
        for(int i = 1; i<=n; ++i)
            if (can[i] == '1')
                res = max(res, max(n - i + 1, i) * 2);
        res = max(res, n);
        cout << res << "\n";
    }
	return 0;
}
