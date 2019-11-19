#include <bits/stdc++.h>
using namespace std;
int T,a,b,c,d,k;
int main(){
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> d >> k;
        int ak = (a - 1) / c + 1;
        int ab = (b - 1) / d + 1;
        if(ak + ab > k)puts("-1");
        else printf("%d %d\n",ak,k-ak);
    }
    return 0;
}