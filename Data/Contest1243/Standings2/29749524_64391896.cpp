#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*---------------for_stuff-------------------*/
#define f(i,a,b) for (int i=a;i<=b;i++)
#define f_(i,a,b) for (int i=a;i>=b;i--)
/*---------------pair_stuff------------------*/
#define MP make_pair
#define ii pair<int,int>
#define Iii pair<int,ii>
#define ill pair<int,ll>
#define lli pair<ll,int>
#define iiI pair<ii,int>
#define llll pair<ll,ll>
#define fi first
#define se second
/*--------------vector_stuff-----------------*/
#define pb push_back
#define ppb pop_back
/*--------------const_stuff-----------------*/
const ll mod=1000000007;
/*--------------map_stuff--------------------*/
// why do you think I should write something in this part? :v

ll n,uoc=0;
int main() {
	cin>>n;
	for (ll i=2;i*i<=n;i++) {
		if (n%i==0) {
			uoc=i;
			break;
		}
	}
	if (uoc==0) {
		printf("%lld", n);
		return 0;
	}
	while (n%uoc==0) n/=uoc;
	if (n==1) printf("%lld", uoc);
	else printf("1");
	return 0;
}