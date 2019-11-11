#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;



int main()
{
    int TC;
    cin >> TC;
    while(TC--){
        ll x, y;
        cin >> x >> y;
        ll gcd = __gcd(x, y);
        if(gcd != 1){
            cout <<"Infinite"<<endl;
        }
        else{
            cout <<"Finite"<<endl;
        }
    }
    return 0;
}
