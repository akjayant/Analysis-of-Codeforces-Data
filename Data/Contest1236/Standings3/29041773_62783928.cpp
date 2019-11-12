#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl

int v[200005];

int main(){
	
    cout.sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int res = 0;
        for(int i = 0; i <= a; i++)
            for(int j = 0; j <= b; j++){
                if(b-2*i-j >= 0 and c-2*j >= 0){
                    res = max(res, i + 2*i + j + 2*j);
                }
            }
        cout << res << endl;
    }
        
	return 0;
}
