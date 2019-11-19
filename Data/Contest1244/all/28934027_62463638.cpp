#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;


int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int one = (a+c-1)/c;
        int two = (b+d-1)/d;
        if(one + two > k) {
            cout<<-1<<endl;
        } else {
            cout<<one<<" "<<two<<endl;
        }
    }
}
