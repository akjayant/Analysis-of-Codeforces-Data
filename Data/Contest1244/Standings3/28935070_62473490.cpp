#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int bio[2][2005],n;
string str;
int dfs(int x,int y) {
	//cout << x << " " << y << "\n";
	bio[x][y]=1;
	int cnt=0;
	if(str[y]=='1' && bio[1 xor x][y]==0) cnt=max(cnt,dfs(1 xor x,y));
	if(y>0 && bio[x][y-1]==0) cnt=max(cnt,dfs(x,y-1));
	if(y<n-1 && bio[x][y+1]==0) cnt=max(cnt,dfs(x,y+1));
	return cnt+1;
}
int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++) {
		cin >> n >> str;
		int r=-1,l=-1;
		for(int j=0;j<n;j++) {
			if(str[j]=='1') r=j;
			if(str[j]=='1' && l==-1) l=j;
		}
		/*int maxi=0;
		for(int j=0;j<2;j++) {
			for(int k=0;k<n;k++) {
				memset(bio,0,sizeof(bio));
				maxi=max(maxi,dfs(j,k));
			}
		}
		cout << maxi << "\n";*/
		int maxi=n;
		if(l!=-1) maxi=max(maxi,(n-l)*2);
		if(r!=-1) maxi=max(maxi,(r+1)*2);
		cout << maxi << "\n";
	}
	return 0;
}
