#include<bits/stdc++.h>
using namespace std;

void tc(){
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    int tmp1=(a+c-1)/c;
    int tmp2=(b+d-1)/d;
    if(tmp1+tmp2>k){
        cout<<"-1\n";
        return;
    }
    cout<<tmp1<<' '<<tmp2<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) tc();
    return 0;
}
