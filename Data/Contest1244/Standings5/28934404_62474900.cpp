#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t-- > 0){
        int n, ans, left = -1, right;
        string s;
        cin >> n >> s;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                if(left == -1)left = i;
                right = i;
            }
        }
        if(left >= 0){
            ans = max(n*2-left*2, right*2+2);
        }else{
            ans = n;
        }
        cout << ans << endl;
    }
    
}
