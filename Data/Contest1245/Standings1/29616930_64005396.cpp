//Rochy'.'
#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define fl(i,a,b) for(int i=a;i<b;++i)
#define fa(i,a) for(auto (i):(a))
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define vi vector <int>
#define ii pair <int,int>
#define pb push_back
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));
if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
template <typename R, typename D> inline void Min(R &a, D b){if(a>b) a=b;}
template <typename D, typename R> inline void Max(D &a, R b){if(a<b) a=b;}
const int N=0000;
int T,n,a[3],b[3],cnt;
int main(){
	ios_base::sync_with_stdio(NULL);
	cin. tie(NULL); cout. tie(NULL);
//	freopen(".inp" , "r", stdin);
//	freopen(".out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cin>>a[0]>>a[2]>>a[1];
		string s;cin>>s;
		string t;
		fl(i,0,n) t+='?';
		b[0]=b[1]=b[2]=0;
		fl(i,0,n){
			if(s[i]=='R') ++b[0];
			if(s[i]=='S') ++b[1];
			if(s[i]=='P') ++b[2];
		}
		cnt=min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0]);
		if(cnt<(n+1)/2){
			cout<<"NO\n";
			continue;
		}
		fo(i,1,min(a[0],b[1])){
			fl(j,0,n){
				if(s[j]=='S'){
					t[j]='R';
					s[j]='?';
					break;
				}
			}
		}
		a[0]-=min(a[0],b[1]);
		fo(i,1,min(a[1],b[2])){
			fl(j,0,n){
				if(s[j]=='P'){
					t[j]='S';
					s[j]='?';
					break;
				}
			}
		}
		a[1]-=min(a[1],b[2]);
		fo(i,1,min(a[2],b[0])){
			fl(j,0,n){
				if(s[j]=='R'){
					t[j]='P';
					s[j]='?';
					break;
				}
			}
		}
		a[2]-=min(a[2],b[0]);
		fl(i,0,n) if(t[i]=='?'){
			if(a[0]){
				t[i]='R';
				--a[0];
				continue;
			}
			if(a[1]){
				t[i]='S';
				--a[1];
				continue;
			}
			if(a[2]){
				t[i]='P';
				--a[2];
				continue;
			}
		}
		cout<<"YES\n"<<t<<'\n';
	}
	return 0;
}