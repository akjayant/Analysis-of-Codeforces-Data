#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef complex<double> cp;
typedef pair<int,int> pii;

const int maxn=(int)2e5+9;
const ll mod=(ll)1e9+7;
const db pi=acos(-1);
const db eps=1e-15;

#define dbg(x) cerr<<#x<<" is "<<x<<endl;

int n;
int a,b,c;
int ca,cb,cc;
char s[maxn];

void init(){
	scanf("%d",&n);
	scanf("%d%d%d%s",&a,&b,&c,s);
}

char as[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		init();
		ca=cb=cc=0;
		for(int i=0;i<n;i++){
			if(s[i]=='S')ca++;
			if(s[i]=='R')cb++;
			if(s[i]=='P')cc++;
		}
		int ans=0;
		ans+=min(ca,a);
		ans+=min(cb,b);
		ans+=min(cc,c);
		if(ans*2>=n){
			printf("YES\n");
			for(int i=0;i<n;i++){
				as[i]=0;
				if(s[i]=='S'&&a){
					as[i]='R';
					a--;
				}
				if(s[i]=='R'&&b){
					as[i]='P';
					b--;
				}
				if(s[i]=='P'&&c){
					as[i]='S';
					c--;
				}
			}
			for(int i=0;i<n;i++){
				if(as[i])continue;
				if(a){
					as[i]='R';
					a--;
				}else if(b){
					as[i]='P';
					b--;
				}else if(c){
					as[i]='S';
					c--;
				}
			}
			as[n]=0;
			printf("%s\n",as);
		}else{
			printf("NO\n");
		}
	}
	return 0;
}

