#include<bits/stdc++.h>
using namespace std;
long long T, n, m;
int main(){
    ios::sync_with_stdio(false);
    long long t, t1, t2, t3, t4, T;
    cin>>T;
    while(T--){
        t1 = t2 = 0;
        t3 = t4 = 0;
        cin>>n;
        for(long long i = 1; i <= n; i++){
            cin>>t;
            if(t % 2) t1++;
            else t2++;
        }
        cin>>m;
        for(long long i = 1; i <= m; i++){
            cin>>t;
            if(t % 2) t3++;
            else t4++;
        }
        cout<<t1 * t3 + t2 * t4<<endl;
    }
    return 0;
}
