#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<lli,lli> pll;
typedef std::vector<lli> vll;
typedef std::vector<pll> vpll;
typedef std::vector<bool> vbb;
typedef map<lli,lli>mll;
typedef map<lli,lli,greater<lli>>mllg;
lli MOD=1e9 +7;
lli INF=1e14;
#define forr(i,p,n) for(i=p; i<n; i++)
#define be(a) a.begin(),a.end()
#define mp make_pair
#define um unordered_map
#define eb emplace_back 
#define pb push_back 
#define F first
#define S second
#define PI 3.14159265358979323846
lli sub(lli a,lli b,lli p=MOD){return ((a%p)-(b%p)+p)%p;}
lli mult(lli a,lli b, lli p=MOD) {return ((a%p)*(b%p))%p;}
lli add(lli a, lli b, lli p=MOD) {return (a%p + b%p)%p;}
lli fpow(lli n, lli k, lli p = MOD) {lli r = 1; while(k > 0) {if (k & 1) r = r * n%p; n = n * n%p; k = k >> 1;} return r;}
lli inv(lli a, lli p = MOD) {return fpow(a, p - 2, p);}
lli fdiv(lli a,lli b,lli p=MOD){
	lli yinv=inv(b);
	lli ans=(a*yinv)%p;
	return ans;
}
ull I1018=1000000000000000000;const ull I10e5=100000;const lli I10e6=1e6;
lli ZERO=0;ull I10e9=1000000000;lli ONE=1;
void printVecpll(std::vector<pll> v){
	for(auto p:v){
		cout<<(char)p.first<<" "<<p.second<<endl;
	}
}
void printVec(std::vector<lli> v){
	for(lli i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
vll read_vec(lli n){lli i;
	vll v(n);
	forr(i,0,n){
		cin>>v[i];
	}
	return v;
}
std::vector<bool> is_prime;
std::vector<lli> primes;
void sieve(lli n){
	is_prime.resize(n+2,true);
	primes.clear();
	lli p;
	for(p=2;p*p<=n;p++){
		if(is_prime[p]){
			lli i;
			for(i=p*p;i<=n;i+=p){
				is_prime[i]=false;
			}
		}
	}
	is_prime[0]=is_prime[1]=false;
	lli i;
	for(i=2;i<=n;i++){
		if(is_prime[i]){
			primes.eb(i);
		}
	}
}
set<lli> prime_factor(lli n){
	lli i;
	set<lli>s;
	for(auto p:primes){		
		if(p>sqrt(n))break;
		while(n%p==0 && n>1){
			s.insert(p);
			n/=p;
		}
	}
	if(n>1){
		s.insert(n);
	}
	return s;
}

//     //FACTORIAL
// std::vector<lli> fact_vec(10004);
// void fact_fun(lli n){
// 	lli i;
// 	fact_vec[0]=1;
// 	for(i=1;i<=n+2;i++){
// 		fact_vec[i]=(fact_vec[i-1]*i)%MOD;
// 	}
// }

    //declare

// class Sol{      	
// public: 	


// };

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif	
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		vll v=read_vec(n);
		sort(v.begin(),v.end());
		lli i;
		lli ans=0;
		for(i=0;i<n;i++){
			lli next=v[i]-1;
			lli curr=1;
			for(lli j=i+1;next>0 && j<n;j++){
				curr++;
				next--;
			}
			ans=max(ans,curr);
		}
		cout<<ans<<endl;
	}
	return 0;
}   


