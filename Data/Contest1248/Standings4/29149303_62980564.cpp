//in the name of god
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int q;
    cin>>q;
    int n,m;
    int nz1=0,nf1=0;
    int h;
    int nz2=0,nf2=0;
    while(q--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>h;
            if(h%2){
                nf1++;
            }
            else{
                nz1++;
            }
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>h;
            if(h%2){
                nf2++;
            }
            else{
                nz2++;
            }
        }
        cout<<nf1*nf2+nz1*nz2<<endl;
        nz1=0,nf1=0,nz2=0,nf2=0;
    }
}
