#include <bits/stdc++.h>
#include <algorithm>
#define pi 3.14159265358
using namespace std;
typedef long long ll;
const ll mod=1000000007;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int maxn = 3e6 + 5;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char ch[1010];
vector<int> vec;
int main(){
	int t,n;
	t=read();
	while(t--){
		vec.clear();
		n=read();
		scanf("%s",ch);
		if(ch[0]=='1'||ch[n-1]=='1'){
			printf("%d\n",2*n);
		}
		else{
			for(int i=0;i<n;i++){
				if(ch[i]=='1'){
					vec.push_back(i);
				}
			}
			int ans=0;
			if(vec.size()==0){
				ans=n;
			}
			else{
				ans=n+vec.size();
			}
			if(vec.size()!=0){
				ans=max(ans,2*(n-vec[0]));
				ans=max(ans,2*(vec[vec.size()-1]+1));
			}
			printf("%d\n",ans);
		}
	}
}