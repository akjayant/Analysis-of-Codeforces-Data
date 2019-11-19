#include <cstdio>
//#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <random>
 
#define turbo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define scint(x) int x; scanf("%d", &x)
#define scll(x) ll x; scanf("%lld", &x)
#define print(x) printf("%d", x)
#define prll(x) printf("%lld", x)
#define prsp printf(" ")
#define prnl printf("\n")
#define ST first
#define ND second
#define PB push_back
 
using namespace std;
typedef long long int ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< int, pii > tii;
typedef vector< int > vi;
typedef vector< ll > vll;
typedef vector< vi > vvi;
typedef vector< pii > vpii;
typedef vector< pll > vpll;
typedef vector< tii > vtii;
typedef deque< int > di;
typedef deque< ll > dll;
typedef deque< di > ddi;
typedef deque< pii > dpii;
typedef set< int > si;
typedef set< ll > sll;
typedef set< pii > spii;
typedef multiset< int > msi;
typedef multiset< ll > msll;
typedef multiset< pii > mspii;
 
const ll MOD = 998244353;
const int INF = 1000000100;
const ll INFll = 1000000000001000000;
 
namespace B{
	ll gcd(ll a, ll b){
		return b ? gcd(b, a%b) : a;
	}
	
	bool prime(ll p){
		for(ll i = 2; i*i <= p; i++){
			if(p%i == 0) return false;
		}
		return true;
	}
	
	ll pow(ll b, ll e, ll mod){
		if(!e) return 1;
		if(e%2) return (b*pow(b, e-1, mod))%mod;
		return pow((b*b)%mod, e/2, mod);
	}
	
	ll revmod(ll a, ll p){
		return pow(a, p-2, p);
	}
	
	ll fact(ll n, ll mod){
		if(n >= mod) return 0;
		ll out = 1;
		for(ll i; i <= n; i++){
			out *= i;
			out %= mod;
		}
		return out;
	}
}

void TC(){
	scint(n);
	bool tab[n];
	char c;
	int cntr=0;
	for(int i = 0; i < n; i++){
		scanf(" %c", &c);
		if(c == '1'){
			tab[i] = true;
			cntr++;
		}
		else tab[i] = false;
	}
	
	if(cntr == 0){
		print(n);
		prnl;
		return;
	}
	
	if(cntr == 1){
		print(n+1);
		prnl;
		return;
	}
	
	int left = n;
	int right = 0;
	for(int i = 0; i < n; i++){
		if(tab[i]){
			left = min(i, left);
			right = max(i, right);
		}
	}
	
	int out = n + cntr;

	print(max(out, max(n-left+n-left, right+1+right+1)));
	prnl;
}


int main(){
	
	//scint(t);
	//while(t--) TC();
	
	scint(n);
	scll(k);
	
	int a[n];
	for(int i = 0;i < n; i++) scanf("%d", &a[i]);
	
	sort(a, a+n);
	
	deque< pii > nums;
	for(int i = 0; i < n; i++){
		if(nums.empty() || nums.back().first != a[i]) nums.push_back({a[i], 1});
		else nums.back().second++;
	}
	
	sort(nums.begin(), nums.end());
	
	//for(int i = 0; i < nums.size(); i++){
	//	printf("%d %d\n", nums[i].first, nums[i].second);
	//}
	
	bool flag = true;
	while(nums.size() > 1 && k > 0 && flag){
		flag = false;
		if(nums.front().second <= nums.back().second){
			ll diff = nums[1].first - nums[0].first;
			ll change = min((k/nums.front().second)*nums.front().second, diff*nums.front().second);
			//printf("F %lld %lld %lld\n", diff, change, k);

			k -= change;
			if(change > 0) flag = true;
			change /= nums.front().second;
			if(change == diff){
				nums[1].second += nums.front().second;
				nums.pop_front();
			}else{
				pii hm = nums.front();
				nums.pop_front();
				nums.push_front({hm.first+change, hm.second});
			}
		//				for(int i = 0; i < nums.size(); i++){
		//printf("%d %d\n", nums[i].first, nums[i].second);
//	}
		}else{
			ll diff = nums[nums.size()-1].first - nums[nums.size()-2].first;
			ll change = min((k/nums.back().second)*nums.back().second, diff*nums.back().second);
		//	printf("B %lld %lld %lld\n", diff, change, k);

			k -= change;
			if(change > 0) flag = true;
			change /= nums.back().second;
			if(change == diff){
				nums[nums.size()-2].second += nums.back().second;
				nums.pop_back();
			}else{
				pii hm = nums.back();
				nums.pop_back();
				nums.push_back({hm.first-change, hm.second});
			}
		//				for(int i = 0; i < nums.size(); i++){
//		printf("%d %d\n", nums[i].first, nums[i].second);
//	}
		}
	}
	
	printf("%d", nums.back().first - nums.front().first);
	
	return 0;
}
