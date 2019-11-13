#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define ll long long
#define int long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

signed main(){
    ios_base::sync_with_stdio(false); //fast io
    cin.tie(NULL);
    int q; cin>>q;
    while(q--){
        int a,b; cin>>a>>b;
        if(a==1 || b==1)cout<<"Finite\n";
        else{
            if(gcd(a,b)!=1)cout<<"Infinite\n";
            else cout<<"Finite\n";
        }
    }
    return 0;
}
