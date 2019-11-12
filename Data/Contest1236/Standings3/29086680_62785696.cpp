#include <iostream>
using namespace std;

int main(){
    int t,a,b,c,res;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        res=0;
        for(int i=0;i<=a;i++){
            if(b<2*i) break;
            res=max(res,i+min(b-2*i,c/2));
        }
        cout<<3*res<<"\n";
    }
    return 0;
}