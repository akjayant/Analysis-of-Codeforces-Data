#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
typedef long long int lo;
const int N=500005,mod=1000000007;
lo a,b,c,d,e,f,g,h[N],arr[N];
string s;
vector<lo>v;
char ch[5000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> g;
    while(g--){
    	cin >> a;
    	lo ilk=0,son=0;
    	for(lo i=1;i<=a;i++){
    		cin >> ch[i];
    		if(ilk==0 and ch[i]=='1'){
    			ilk=i;
    		}
    	}
    	for(lo i=a;i>=1;i--){
    		if(son==0 and ch[i]=='1'){
    			son=i;
    		}
    	}
    	if(ilk==0){
    		cout << a << endl;
    		continue;
    	}
    	cout << max(max(a,2*son),2*(a-ilk+1)) << endl;
    }
}