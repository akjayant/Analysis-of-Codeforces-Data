#include <bits/stdc++.h>
using namespace std;


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    while(t--){
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        int x = (a+(c-1))/c;
        int y = (b+(d-1))/d;
        if(x+y>k){
            cout << "-1" << endl;
        }
        else{
            cout << x << " " << y << endl;
        }
    }
    







}