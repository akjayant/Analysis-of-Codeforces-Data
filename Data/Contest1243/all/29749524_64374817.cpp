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

int t,n,a[1005];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		f(i,1,n) scanf("%d", &a[i]);
		sort(a+1,a+1+n);
		int ans=1;
		f_(i,n-1,1) {
			if (a[i]>=ans+1) ans++;
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}