#include <iostream>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m, a = 0;
        long long ans = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            int p;
            cin >> p;
            if(p%2 == 0)a++;
        }
        cin >> m;
        for(int i=0;i<m;i++){
            int p;
            cin >> p;
            if(p%2 == 0)ans += a;
            else ans += n-a;
        }
        cout << ans << endl;
    }
    
}
