#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int arr[3],ans[MAXN];
char tp[]={'R','P','S'};
char s[MAXN];
int main(){
   // freopen("file.in", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--){
    	int n,cnt=0;
    	scanf("%d",&n);
    	for(int i=0;i<n;i++)
    		ans[i]=-1;
    	for(int i=0;i<3;i++)
    		scanf("%d",arr+i);
    	scanf("%s",s);	
    	for(int i=0;i<n;i++){
    		int who;
    		for(int j=0;j<3;j++)	
    			if(tp[j]==s[i])
    				who=j;
    		who=(who+1)%3;	
    		if(arr[who])
    			arr[who]--,ans[i]=who,cnt++;
    	}
    	if(cnt>=(n+1)/2){
    		puts("YES");
    		for(int i=0;i<n;i++){
    			if(~ans[i])
					printf("%c",tp[ans[i]]);
				else{
					for(int j=0;j<3;j++)
						if(arr[j]){
							arr[j]--;
							printf("%c",tp[j]);
							break;	
						}
				}
    		}
    		puts("");
    	}
    	else
    		puts("NO");
    }	
	return 0;
}
