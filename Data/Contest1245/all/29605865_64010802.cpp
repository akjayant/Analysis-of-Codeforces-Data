#include<iostream>
#include<string.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main(){
    int i,n,t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(gcd(a,b)==1) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }
    return 0;

}


