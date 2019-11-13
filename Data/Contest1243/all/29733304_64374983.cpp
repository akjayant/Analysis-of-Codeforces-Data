#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        sort(a.begin() , a.end() , greater<int>());
        int minvalue = INT_MAX;
        int maxvalue = 0;
        for(int i = 0; i < n; ++i){
            minvalue = min(minvalue , a[i]);
            if(minvalue >= (i + 1)){
                maxvalue = max(maxvalue , i + 1);
            }
        }
        cout << maxvalue << "\n";
    }
return 0;
}
