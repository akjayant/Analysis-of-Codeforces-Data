#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
 
using namespace std;
 
#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll; 
void vdeb(vector<int> &da){
    int size=da.size();
    for(int i=0;i<size;i++){
        if(i==size-1){
			printf("%d\n",da[i]);
        }
        else{
			printf("%d ",da[i]);
        }
    }
}
int solve(){
	int a,b,c;
	cin >> a >>	b >> c;
	int ret=min(b,c/2);
	b-=ret;
	ret+=min(b/2,a);
	return ret*3;
}

int main(){
	int t;
	cin >> t;
	vector<int> ans(t);
	rip(i,t,0){
		ans[i]=solve();
	}
	rip(i,t,0){
		printf("%d\n",ans[i]);
	}
}