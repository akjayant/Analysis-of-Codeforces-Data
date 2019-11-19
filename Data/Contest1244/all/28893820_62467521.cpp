#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int a, b, c, d, k;

        cin >> a >> b >> c >> d >> k;

        bool ok = false;

        for(int i=0; i<=k; i++){
            if(i*c>=a and (k-i)*d>=b){
                cout << i << " " << k-i << endl;
                ok = 1;
                break;
            }
            if((k-i)*c>=a and i*d>=b){
                cout << k-i << " " << i << endl;
                ok = 1;
                break;
            }
        }

        if(!ok) cout << -1 << endl;
    }

    return 0;
}
