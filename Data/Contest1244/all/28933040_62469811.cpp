#include <bits/stdc++.h>
using namespace std;

/*
1
3
110
*/
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int s = 0; s < t; s++){
        int n;
        cin >> n;
        string door;
        cin >> door;
        int best_door = -1;
        for(int i = 0; i < n; i++){
            if(door[i] == '1'){
                if(best_door == -1 || abs(2 * i - (n - 1)) > abs(2 * best_door - (n - 1)))
                    best_door = i;
            }
        }
        int i = best_door;
        if(i != -1)
            cout << 2 * max(i, n - i - 1) + 2 << "\n";
        else
            cout << n << "\n";
    }
    return 0;
}
