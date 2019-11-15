#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define lim 1000000007
#define ll long long
int n,m,t,ans,an,a,b,c,cc[200005],aa[200005],bb[200005];
map<int ,int > mm;
priority_queue<int > q;
char s[200005],ss[200005];
vector<int > ee[200005];
struct yo{
	int x,y;
	bool operator < (const yo & tt) const{
		return x<tt.x;
	}
};
int main(){
	scanf("%d",&t);
	for (int i=0;i<t;i++){
		scanf("%d%d",&a,&b);
		if (__gcd(a,b) != 1) printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}