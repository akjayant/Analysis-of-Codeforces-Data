#include <bits/stdc++.h>
 
#define ll long long int
#define ull unsigned long long int
 
#define lp(i,n) 	    for(int i=0;i<(int)(n);i++)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);i++)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);i--)
 
#define all(v)  	 ((v).begin()), ((v).end())
#define sz(v)    	 ((int)((v).size()))
#define clr(v, d)    memset(v, d, sizeof(v))
#define PB           push_back
#define MP           make_pair
#define N 200005
 
#define PI 3.14159265
 
using namespace std;
 
ll nChooseR(int n,int k);
ll gcd(ll a, ll b);
vector<string> split(string target,char c );
bool isPrime(ll h);
 
ll n,m,x,y,l,r,k,a[N],t;
ll ans;
int mod=(int)(1e9 +7);



int main() {
//  freopen("unique.in","r",stdin); 
  //freopen("output.txt","w",stdout); 
//cout.precision(9);
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
// cin>>t;
// string s,h;
// while(t--){
// 	cin>>n;
// 	cin>>s>>h;
// 	ans=0;
// 	vector<int>cnt(26,0),v;
// 	lp(i,n){
// 		cnt[s[i]-'a']++;
// 		cnt[h[i]-'a']++;
// 		if(s[i]!=v[i])v.push_back(i);
// 	}
// 	lp(i,26){
// 		if(cnt[i]%2){
// 			cout<<"no\n";
// 			goto here;
// 		}
// 	}
// 	lp(i,sz(v)-1){

// 	}

// 	here:
// 		continue;

// }
cin>>n;
int gc=0;
for(ll i=2;i*i<=n ;i++){
	if(n%i==0){
		if(!gc){
			gc=gcd(i,n/i);
		}
		else {
			gc=gcd(gc,i);
			gc=gcd(gc,n/i);
		}
	}
}
if(gc==0)cout<<n;
else cout<<gc;


}
	
 
 
 
	
ll nChooseR( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
   	ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
 
ll gcd(ll a, ll b){
	return b==0?a:gcd(b,a%b);
	}
 
 
vector<string> split(string target,char c ){
	string d="";
	vector<string>arr;
	for(auto n:target)
	{
		if(n!=c)
		d+=n;
		else if(d!="")
		arr.push_back(d),d="";
	}
	if (d!="")
	arr.push_back(d),d="";
	return arr;
}
// bool isPrime(ll h){
//      for(ll i=0;primes[i]*primes[i]<=h;i++)
//      if (h%primes[i]==0)
//      return 0;
//      return h!=1;
//  }
 bool isPrime(ll g){
   if((g%2==0 && g>2) || g==1)return 0;
   for(ll i=3;i*i<=g;i+=2)if(g%i==0)return 0;
   return 1;   
 
 }