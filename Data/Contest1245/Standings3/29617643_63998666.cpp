#include <bits/stdc++.h>

using namespace std;
int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}
int main(){
    int t;
    cin>>t;
    while(t){
        t--;
        int a,b;
        cin>>a>>b;
        if(gcd(a,b)==1)
            cout<<"Finite"<<endl;
        else
            cout<<"Infinite"<<endl;
    }
    return 0;
}