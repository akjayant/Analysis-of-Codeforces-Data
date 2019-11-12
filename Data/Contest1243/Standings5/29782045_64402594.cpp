#include <iostream>
using namespace std;

int main() {
    int k,n,x,res;
    cin>>k;
    int c[1001];
    while(k--){
        cin>>n;
        for(int i=0;i<=1000;i++) c[i]=0;
        for(int i=0;i<n;i++){
            cin>>x;
            c[x]++;
        }
        for(int i=n-1;i>0;i--){
            c[i]+=c[i+1];
        }
        for(int i=n;i>0;i--){
            if(c[i]>=i){
                res=i;
                break;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
