#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mm 1000000007
#define ll long long
ll n,m,t,ans,an,a,b,c,cc[200005],aa[200005],bb[200005];
priority_queue<int > q;
char s[200005],ss[205];
vector<int > ee[200005];
struct yo{
	int x,y;
	bool operator < (const yo & tt) const{
		return x<tt.x;
	}
};
int main(){
	gets(s);
	n = strlen(s);
	for (int i=0;i<n;i++) if (s[i] == 'm' || s[i] == 'w') an = 1;
	if (an){
		printf("0\n");
		return 0;
	}else{
		bb[0] = 1;
		bb[1] = 1;
		for (int i=2;i<=n;i++){
			bb[i] = (bb[i-1] + bb[i-2])%mm;
		}
		ans = 1;
		a = 0;
		for (int i=0;i<n;i++) if (s[i]=='n'){
			a++;
		}else{
			ans = (ans * bb[a])%mm ;
			a = 0;
		}
		ans = (ans * bb[a])%mm ;
		a = 0;
		for (int i=0;i<n;i++) if (s[i]=='u'){
			a++;
		}else{
			ans = (ans * bb[a])%mm ;
			a = 0;
		}
		ans = (ans * bb[a])%mm ;		
		printf("%I64d\n",ans);
	}
	return 0;
}