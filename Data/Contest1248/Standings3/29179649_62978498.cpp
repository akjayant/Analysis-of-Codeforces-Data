#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t , n , i , odd1 , odd2 , even2 , even1 , ans , x , m;
    cin >> t;
    while(t--){
        cin >> n ;
        odd2 = odd1 = even1 = even2 = 0;
        ans  = 0;
        for(i = 0 ; i < n ; i++){
            cin >> x;
            if(x & 1){
                odd1++;
            }
            else{
                even1++;
            }
        }
        cin >> m ;
        for(i = 0 ; i < m ; i++){
            cin >> x;
            if(x & 1){
                odd2++;
            }
            else{
                even2++;
            }
        }
        ans = odd2 * odd1 + even2 * even1 ;
        cout << ans << "\n";
    }
    return 0;
}