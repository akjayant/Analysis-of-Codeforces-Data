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
set<pair<int, int>> Map, Map2, Map3, Map4;
int main() {
	int N=read(), M=read(), K=read();
	for(int i=1; i<=K; i++){
		int a=read(), b=read();
		Map.insert(make_pair(a, b));
		Map2.insert(make_pair(b, a));
		Map3.insert(make_pair(-a, -b));
		Map4.insert(make_pair(-b, -a));
	}
	int nL=1, nR=M, nU=1, nD=N;
	int dir = 1;
	while(true){
		if(dir==1){
			auto f = Map.lower_bound(make_pair(nU, nL));
			if(f != Map.end() && (*f).first == nU && (*f).second <=nR){
				int x = (*f).second;
				for(int i = x; i <= nR; i++){
					for(int j = nU; j <= nD; j++){
						if(Map2.find(make_pair(i, j))==Map2.end()){
							return puts("NO"), 0;
						}
					}
				}
				nR = x-1;
			}
			nU++;
			dir = 2;
		}
		else if(dir == 2){
			auto f = Map2.lower_bound(make_pair(nR, nU));
			if(f != Map2.end() && (*f).first == nR && (*f).second <=nD){
				int x = (*f).second;
				for(int i = nL; i <= nR; i++){
					for(int j = x; j <= nD; j++){
						if(Map2.find(make_pair(i, j))==Map2.end()){
							return puts("NO"), 0;
						}
					}
				}
				nD = x-1;
			}
			nR--;
			dir = 3;
		}
		else if(dir == 3){
			auto f = Map3.lower_bound(make_pair(-nD, -nR));
			if(f != Map3.end() && (*f).first == -nD && -(*f).second >= nL){
				int x = -(*f).second;
				for(int i = nL; i <= x; i++){
					for(int j = nU; j <= nD; j++){
						if(Map2.find(make_pair(i, j))==Map2.end()){
							return puts("NO"), 0;
						}
					}
				}
				nL=x+1;
			}
			nD--;
			dir = 4;
		}
		else if(dir == 4){
			auto f = Map4.lower_bound(make_pair(-nL, -nD));
			if(f != Map4.end() && -(*f).first == nL && -(*f).second >=nU){
				int x = -(*f).second;
				for(int i = nL; i <= nR; i++){
					for(int j = nU; j <= x; j++){
						if(Map2.find(make_pair(i, j))==Map2.end()){
							return puts("NO"), 0;
						}
					}
				}
				nU=x+1;
			}
			nL++;
			dir = 1;
		}
		if(nU>nD || nL>nR)break;
	}
	puts("YES");
	return 0;
}
