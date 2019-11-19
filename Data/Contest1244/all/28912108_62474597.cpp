#include <iostream>
#define String string
using namespace std;

int n;
String S;

void read();
int ans();

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        read();
        cout << ans() << endl;
    }
    return 0;
}

void read(){
    cin >> n >> S;
    S = '?' + S;
}

int ans(){
    int res = n;
    for(int p = 1; p <= n; p++){
        if(S[p] == '1'){
            res = max(res, 2 * p);
            res = max(res, p + n - (p - 1));
            res = max(res, 2 * (n - p + 1));
        }
    }
    return res;
}
































