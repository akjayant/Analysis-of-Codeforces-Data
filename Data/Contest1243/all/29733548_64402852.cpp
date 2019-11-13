#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3f;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
inline bool read(ll &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    } 
    if(IsN) num=-num;
    return true;
}
const int N = 10000;
int k,n;
struct node{
	int x,y;
}a[N*2];
unordered_map<int,int>  mmp;
char s[N],t[N];
void solve(){
 	mmp.clear();
		cin>>n>>s>>t;
		for(int i=0;i<n;i++){
			mmp[s[i]]++;
			mmp[t[i]]++;
		}
		bool flag=0;
		for(char i='a';i<='z';i++){
			if(mmp[i]%2==1){
                 flag=1;break;
            }
		}
		if(flag){
            cout<<"No"<<endl;
        }
		else{
			cout<<"Yes"<<endl;
			int operations=0;
			for(int i=0;i<n;i++){
				if(s[i]!=t[i]){
					for(int j=i+1;j<n;j++){
						if(s[i]==s[j]){
							a[operations].x=j; a[operations].y=i;
							swap(s[j],t[i]); operations++;
							break;
						}
						else if(t[i]==t[j]){
							a[operations].x=i; a[operations].y=j;
							swap(s[i],t[j]); operations++;
							break;
						}
						else if(s[i]==t[j]){
							a[operations].x=j; a[operations].y=j;
							swap(s[j],t[j]); operations++;

							a[operations].x=j; a[operations].y=i;
							swap(s[j],t[i]); operations++;
							break;
						}
						else if(t[i]==s[j]){
							a[operations].x=j; a[operations].y=j;
							swap(s[j],t[j]); operations++;

							a[operations].x=i; a[operations].y=j;
							swap(s[i],t[j]); operations++;
							break;
						}
					}
				}
			}
			cout<<operations<<endl;
			for(int i=0;i<operations;i++){
                cout<<a[i].x+1<<' '<<a[i].y+1<<endl;
			}
		}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>k;
	while(k--) solve();
	return 0;
}
