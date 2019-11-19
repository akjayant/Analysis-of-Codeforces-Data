#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstring>
#define FF first
#define SS second
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
typedef pair<int,int> PII;
const int MAX = 2e5 + 5;
int n;
char s[MAX];
int main()
{
	int T;
	cin>>T;
	while(T--) {		
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans = n;
		for(int i = 1; i<=n; i++) {
			if(s[i] == '1') {
				ans = max(ans,max(i+i,i+(n-i+1)));
				ans = max(ans,max(n-i+1+i,n-i+1+n-i+1));
			}
		}
		printf("%d\n",ans);
	}


	return 0 ;
}
