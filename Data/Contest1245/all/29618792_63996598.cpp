#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,T;
    cin >> T;

    for(t=1;t<=T;t++){
        int a,b;
        cin >> a >> b;
        if(gcd(min(a,b),max(a,b)) == 1)
            cout << "Finite\n";
        else
            cout << "Infinite\n";

    }
    return 0;
}