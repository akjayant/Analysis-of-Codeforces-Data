#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t, a, b, c;

    cin >> t;

    while(t--){
        cin >> a >> b >> c;

        int ans = 0;

        for(int i=0; i<=55; i++){
            for(int j=0; j<=55; j++){
                int sum = i + 2*i;
                sum += j + 2*j;
                if(i<=a and (2*i + j)<=b and 2*j<=c) ans = max(sum, ans);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
