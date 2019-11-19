#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a,b,c,d,k,ans1,ans2,ans3;
int main() {
    int t;cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>a>>b>>c>>d>>k;
        ans1=ceil((1.0*a)/(1.0*c)),ans2=ceil((1.0*b)/(1.0*d));
        if(ans1+ans2>k){cout<<"-1"<<endl;continue;}
        cout<<ans1<<' '<<ans2<<endl;
    }
}