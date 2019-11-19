#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,k,pen,pens,t;

int main(){

    cin>>t;

    while(t--){
        cin>>a>>b>>c>>d>>k;
        pen = a/c;
        if(pen*c<a) pen++;
        pens = b/d;
        if(pens*d<b) pens++;
        if(pen + pens > k)
            cout<<-1;
        else cout<<pen<<' '<<pens;
        cout<<'\n';

    }

    return 0;
}
