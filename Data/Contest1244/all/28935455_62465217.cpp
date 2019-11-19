#include<bits/stdc++.h>
using namespace std;
int main() {
    //do this
    int t;
    for(cin>>t;t>0;t--) {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int x = (a+c-1)/c;
        int y = (b+d-1)/d;
        if(x+y>k) {
            cout<<-1<<endl;
        }
        else {
            cout<<x<<" "<<y<<endl;
        }
    }

}

