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

int t,n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		string s,t;
		vector<ii> v;
		cin>>s>>t;
		bool anotherfuck=false;
		for (int i=0;i<n-1;i++) {
			if (s[i]==t[i]) continue;
			bool fuck=false;
			for (int j=i+1;j<n;j++) {
				if (s[i]==s[j]) {
					v.pb(MP(j,i));
					s[j]=t[i];
					t[i]=s[i];
					fuck=true;
					break;
				}
			}
			if (!fuck) {
				for (int j=i+1;j<n;j++) {
					if (s[i]==t[j]) {
						v.pb(MP(i+1,j));
						v.pb(MP(i+1,i));
						t[j]=s[i+1];
						s[i+1]=t[i];
						t[i]=s[i];
						fuck=true;
						break;
					}
				}
				if (!fuck) {
					printf("No\n");
					anotherfuck=true;
					break;
				}
			}
		}
		if (!anotherfuck) {
			if (s!=t) {
				printf("No\n");
			} else {
				printf("Yes\n%d\n", v.size());
				for (int i=0;i<v.size();i++) {
					printf("%d %d\n", v[i].fi+1,v[i].se+1);
				}
			}
		}
	}
	return 0;
}