#include<bits/stdc++.h>
using namespace std;

int ntest;
int a,b;

int GCD(int a,int b){
    if (b==0) return a;
    return GCD(b,a%b);
}

int main(){
    cin>>ntest;
    for(int nt=1;nt<=ntest;nt++){
        cin>>a>>b;
        if (GCD(a,b)==1) cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
}
