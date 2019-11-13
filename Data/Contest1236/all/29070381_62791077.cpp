/*
त्यक्तवाधर्मं च लोभं च
मोहंचो द्यमास्थिता।
युद्ध्यध्वमनहंकारा
यतो धर्मस्ततो जयः।।
*/
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
using namespace std;
#define int     long long int
#define ld      long double
#define pb      push_back
#define pa      pair<int,int>
#define v1d     vector<int>
#define v2d     vector<vector<int> >
#define M       1000000007
#define MN      LLONG_MIN
#define MX      LLONG_MAX
#define ff      first
#define ss      second
#define endl    "\n"
#define v1s     vector<string>
#define S(v)    sort(v.begin(),v.end())
#define RS(v)   sort(v.rbegin(),v.rend())
#define R(v)    reverse(v.begin(),v.end())
#define mxpq(T)    priority_queue <T>
#define mnpq(T)    priority_queue<T,vector<T>,greater<T>>
#define T       int tc;cin>>tc;while(tc--)
#define p2d(v)     for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define P(a)    cout<<a<<" ";
#define p1d(v)      for(auto a:v)cout<<a<<" ";cout<<endl

void Weapons19(){
    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
    #endif
}
#define qqq 400005

int32_t main(){
    Weapons19();
 	int n;cin>>n;
 	v2d v(n,v1d(n));
 	int c=1,p=0;
 	for(int i=0;i<n;i++){
 		if(p==0){
	 		for(int j=0;j<n;j++){
	 			v[j][i]=c;c++;
	 		}p=1;
	 	}
	 	else{
	 		for(int j=n-1;j>=0;j--){
	 			v[j][i]=c;c++;
	 		}
	 		p=0;
	 	}

 	}
 	p2d(v);

















}

