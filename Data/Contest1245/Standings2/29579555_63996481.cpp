#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main()
{
	int t,a,b;
	cin>>t;
	while(t--){
        cin>>a>>b;
        if(__gcd(a,b)==1)cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
	}
    return 0;
}