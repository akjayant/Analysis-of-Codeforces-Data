#include<bits/stdc++.h>
#define Task ""

using namespace std;

int main(){
	/*
	#ifndef ONLINE_JUDGE
	freopen(Task".inp","r",stdin);
	freopen(Task".out","w",stdout);
	#endif
	*/
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int a, b, c, d, k, q;
    cin >> q;
    while (q--){
        cin >> a >> b >> c >> d >> k;
        bool ok = false;
        for(int x = 1; x <=k; ++x){
            for(int y = 1; y <= k; ++y){
                if (x + y > k) continue;
                if ((x * c >= a) && (y * d >= b)){
                    cout << x << " " << y << "\n";
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (!ok) cout << -1 << "\n";
    }

	return 0;
}
