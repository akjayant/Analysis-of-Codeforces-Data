#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int main(){
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int n1=0,n2=0;
        n1=min(b,c/2);
        b-=n1;
        n2=min(a,b/2);
        cout<<(n1+n2)*3<<endl;
    }
}