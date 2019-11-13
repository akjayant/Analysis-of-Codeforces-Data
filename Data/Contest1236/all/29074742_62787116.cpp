#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
inline int read(){
	register int res=0, c;
	while(c=getchar(), c<'0'||c>'9');
	do{
		res=(res*10)+(c^48);
	} while(c=getchar(), c>='0'&&c<='9');
	return res;
}
int main() {
	int T=read();
	while(T--){
		int a=read(), b=read(), c=read();
		int ans = 0;
		if(c/2>=b){
			ans = b*3;
		}
		else{
			ans = c/2*3;
			int temp = (b-c/2)/2;
			if(temp >= a){
				ans += a*3;
			}
			else ans += temp*3;
		}
		printf("%d\n", ans);
	}
	return 0;
}