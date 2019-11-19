#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;

int n, m, k;
set<int> obsy[110000], obsx[110000];

int main(){
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		obsx[x].insert(y);
		obsy[y].insert(x);
	}
	int x = 1, y = 1, o = 1, minx = 1, maxx = n, miny = 1, maxy = m;
	while (1){
		if (k == 0) break;
		if (o == 1){
			if (!obsx[x].empty()){
				int p = *(obsx[x].begin());
				long long num = (long long)(maxy - p + 1) * (maxx - minx + 1);
				if (num > k){
					printf("No\n");
			//		cout << o << endl;
					return 0;
				}
				for (int i = p; i <= maxy; i++)
					for (int j = minx; j <= maxx; j++){
						if (obsy[i].find(j) != obsy[i].end()){
							obsy[i].erase(j);
							obsx[j].erase(i);
							k--;
						}	else{
							printf("No\n");
							return 0;
						}
					}
				y = p - 1;
				maxy = p - 1;
				minx ++;
				o = 2;
			}	else{
				y = maxy;
				minx++;
				o = 2;
			}	
		}	else
		if (o == 2){
			if (!obsy[y].empty()){
				int p = *(obsy[y].begin());
				long long num = (long long)(maxx - p + 1) * (maxy - miny + 1);
				if (num > k){
					printf("No\n");
					
			//		cout << o << endl;
					return 0;
				}
				for (int i = p; i <= maxx; i++)
					for (int j = miny; j <= maxy; j++){
						if (obsx[i].find(j) != obsx[i].end()){
							obsx[i].erase(j);
							obsy[j].erase(i);
							k--;
						}	else{
							printf("No\n");
							return 0;
						}
					}
				x = p - 1;
				maxx = p - 1;
				maxy --;
				o = 3;
			}	else{
				x = maxx;
				maxy --;
				o = 3;
			}	
		}	else
		if (o == 3){
			if (!obsx[x].empty()){
				set<int>::iterator it = obsx[x].end();
				int p = *(--it);
				long long num = (long long)(p - miny + 1) * (maxx - minx + 1);
				if (num > k){
					printf("No\n");
					
					//cout << o << endl;
					return 0;
				}
				for (int i = miny; i <= p; i++)
					for (int j = minx; j <= maxx; j++){
						if (obsy[i].find(j) != obsy[i].end()){
							obsy[i].erase(j);
							obsx[j].erase(i);
							k--;
						}	else{
							printf("No\n");
							return 0;
						}
					}
				y = p + 1;
				miny = p + 1;
				maxx --;
				o = 4;
			}	else{
				y = miny;
				maxx --;
				o = 4;
			}				
		}	else
		if (o == 4){
			if (!obsy[y].empty()){
				set<int>::iterator it = obsy[y].end();
				int p = *(--it);
				long long num = (long long)(p - minx + 1) * (maxy - miny + 1);
				
				//cout << p << endl;
				if (num > k){
					printf("No\n");
				//	cout << o << endl;
					return 0;
				}
				for (int i = minx; i <= p; i++)
					for (int j = miny; j <= maxy; j++){
						if (obsx[i].find(j) != obsx[i].end()){
							obsx[i].erase(j);
							obsy[j].erase(i);
							k--;
						}	else{
							printf("No\n");
							return 0;
						}
					}
				x = p + 1;
				minx = p + 1;
				miny ++;
				o = 1;
			}	else{
				x = minx;
				miny++;
				o = 1;
			}							
		}
	}
	
	printf("Yes\n");
	
	return 0;
}