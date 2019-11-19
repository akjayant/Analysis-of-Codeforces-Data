#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define p2(a,b) cout<<a<<" "<<b<<endl;
#define p3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;	
#define all(a) a.begin(),a.end()
#define M 1000000007

void get(ll n)  
{  
	set<ll> st;
    while(n%2 == 0)  
    {  
        st.insert(2);
        n = n/2;
    }
    
    for(ll i=3;i<=sqrt(n) && st.size()<2;i=i+2)  
    { 
        while(n%i==0)  
        {  
            st.insert(i);
            n=n/i; 
        }
    }  
    if(n>2)  
        st.insert(n);


    auto it = st.begin();
    if(st.size()==1) cout<<*it;
    else cout<<1;
}  
	
int main(){
	fastio;
	ll n;
	cin>>n;
	get(n);
	return 0;
}