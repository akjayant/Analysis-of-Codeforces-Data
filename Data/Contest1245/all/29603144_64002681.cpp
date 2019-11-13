#include<bits/stdc++.h>
#define LL long long
#define MAXN 300005
#define INF (1<<25)
#define P int(998244353)
using namespace std;

int N;
int r,p,s;
int r1,p1,s1;
string ss,t;


int main(){
	
	ios::sync_with_stdio(0);
	
	int T;
	cin>>T;
	
	while(T--){
		cin>>N;
		cin>>r>>p>>s;
		cin>>ss;
		
		t = "";
		r1 = p1 = s1 = 0;
		int cnt = 0;
		for(int i=0;i<N;i++){
			char c = ss[i];
			if(c=='S' && r){
				--r;
				t += 'R';
				++cnt;
				continue;
			}
			if(c=='R' && p){
				--p;
				t += 'P';
				++cnt;
				continue;
			}
			if(c=='P' && s){
				--s;
				t += 'S';
				++cnt;
				continue;
			}
			
			t += ' ';
		}
		
		if(cnt*2 < N){
			cout<<"NO"<<endl;
			continue;
		}
		
		
		cout<<"YES"<<endl;
		for(int i=0;i<N;i++){
			if(t[i]==' '){
				if(r) t[i] = 'R', r--;
				else if(p) t[i] = 'P', p--;
				else t[i] = 'S', s--;
			}
		}
		cout<<t<<endl;
	}
	
	
	return 0;
}