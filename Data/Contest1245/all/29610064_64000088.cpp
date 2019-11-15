#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a % b);
}

int main(){
    int T,a,b;
    cin >>T;
    while(T--){
        cin >> a >> b;
        int gc = gcd(a,b);
        if(gc == 1){
            cout << "Finite" << endl;
        }
        else cout << "Infinite" << endl;
    }
}