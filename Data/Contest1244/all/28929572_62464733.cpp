#include <bits/stdc++.h>
using namespace std;
const int NMAX =1e5+4;

int n,t;

int main(){
    int a,b,c,d,k,nr1,nr2;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        nr1=a/c+(bool)(a%c);
        nr2=k-nr1;
        if(nr2*d >= b){
            cout<<nr1<<' '<<nr2;
        }else
            cout<<-1;
        cout<<'\n';
    }
    return 0;
}
