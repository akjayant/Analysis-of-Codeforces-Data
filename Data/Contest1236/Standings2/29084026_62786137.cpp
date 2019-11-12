#include<bits/stdc++.h>
using namespace std;

int main (){
	int q, Q, a, b, c, ans=0;
	cin >> Q;
	for (q=1; q<=Q; q++){
        cin >> a >> b >> c;
        ans = 0;
        if (b >= c/2){
            ans += (c/2*2 + c/2);
            b -= c/2;
        }else{
            ans += 3*b;
            cout << ans << "\n";
            continue;
        }

        if (a >= b/2){
            ans += b/2*2 + b/2;
        }else{
            ans += 3*a;
        }
        cout << ans << "\n";
	}
	return 0;
}
