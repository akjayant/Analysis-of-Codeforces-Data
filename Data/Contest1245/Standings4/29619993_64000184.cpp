#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b){
    if (b==0) return a;
    return(GCD(b, a%b));

}


int main()
{
    int t;
    cin>>t;
    int a, b;
    while(t--){
        cin>>a>>b;
        cout<<(GCD(a, b) == 1?"Finite\n":"Infinite\n");
    }
    return 0;
}
