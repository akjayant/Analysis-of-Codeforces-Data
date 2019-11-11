#include <iostream>
using namespace std;

const int MAXN=10;

int c[MAXN];

int gcd(int a,int b){
    return !b?a:gcd(b,a%b);
}
int main(){
    int kase;cin>>kase;
    while(kase--){
        int a,b;cin>>a>>b;
        if(gcd(a,b)==1){
            cout<<"Finite\n";
        }else cout<<"Infinite\n";
    }

    return 0;
}