//scnucjh
#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;



int main() {
#ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) {
        long long a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        long long x = (a+c-1)/c, y = (b+d-1)/d;
        if(x+y>k) cout<<-1<<endl;
        else cout<<x<<" "<<y<<endl;
    }
    

    return 0;
}


