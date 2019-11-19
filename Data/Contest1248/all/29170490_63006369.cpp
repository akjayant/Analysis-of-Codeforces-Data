#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll infll=1e18+69;
const ll mod=1e9+7;
const ld pi=acos(-1.0L);
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define	ed return 0
#define hi hfvjidwkofiuhgaew
#define all(v) v.begin(), v.end()
int n; string s;
int ans, l, r;
int main(){
	fio;
	cin>>n>>s;
	int l=0, r=0;
	for(int i=0; i<n; i++){
		if(s[i]=='(') l++;
		else r++;
	}
	if(l!=r){
		cout<<"0\n1 1\n"; return 0;
	}
	ans=-1;
	for(int i=1; i<n; i++){
		for(int j=0; j<=i; j++){
			string tmp=s;
			char tttmp=tmp[i];
			tmp[i]=tmp[j];
			tmp[j]=tttmp;
			int mini=0, idx=-1, cnt=0, cntt=0;
			for(int i=0; i<n; i++){
				if(tmp[i]=='(') cnt++;
				else cnt--;
				if(cnt<0 && cnt<mini){
					mini=cnt; idx=i;
				}
			}
			string t;
			for(int i=idx+1; i<n; i++) t+=tmp[i];
			for(int i=0; i<=idx; i++) t+=tmp[i];
			cnt=0;
			for(int i=0; i<n; i++){
				if(t[i]=='(') cntt++;
				else cntt--;
				if(cntt==0) cnt++;
			}
			if(ans<cnt){
				ans=cnt; l=j+1; r=i+1;
			}
		}
	}
	cout<<ans<<endl;
	cout<<l<<" "<<r<<endl;
	ed;
}