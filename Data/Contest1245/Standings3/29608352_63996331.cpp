#include <iostream>

using namespace std;
int t, a ,b;
int gcd(int a, int b){
    return a % b == 0 ? b : gcd(b, a%b);
}
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(gcd(a, b) == 1) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }
    return 0;
}
