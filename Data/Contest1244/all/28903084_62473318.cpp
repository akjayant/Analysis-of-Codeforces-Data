#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int,int> pii;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	INT n,p,w,d;
	cin>>n>>p>>w>>d;
	if(w*n<p) {printf("-1\n");return 0;}
	INT N=p/w;
	INT per=p%w;
	if(N==0){
		if(p==d) {
			cout<<0<<' '<<1<<' '<<n-1<<endl;
			return 0;
		}
		else if(p==0) {
			cout<<0<<' '<<0<<' '<<n<<endl;
			return 0;
		}
		else {
			cout<<"-1"<<endl;
			return 0;
		}
	}
	for(int i=0;i<=min(N,d);i++){
		if((i*w+per)%d==0){
			if(N-i+(i*w+per)/d<=n) {
				cout<<N-i<<' '<<(i*w+per)/d<<' '<<n-(N-i+(i*w+per)/d)<<endl;
			}
			else {
				printf("-1\n");
			}
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
                  