#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main(){
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cin >> s;
        if(s[0] == '1' || s[n-1] == '1'){
            printf("%d\n",2*n);
            continue;
        }
        int res = n;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                res = max(2 * n - 2 * i,res);
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1'){
                res = max(res,2*(i+1));
            }
        }
        cout << res << endl;
    }
    return 0;
}