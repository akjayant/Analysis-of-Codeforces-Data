#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	int N, M, K; cin >> N >> M >> K; 
	vector<int> R[100010] = {}; 
	vector<int> C[100010] = {}; 
	for(int i = 0; i < K; i++){
		int a, b; cin >> a >> b; 
		a--; b--; 
		R[a].push_back(b); 
		C[b].push_back(a); 
	}
	for(int i = 0; i < N; i++){
		R[i].push_back(-114514); 
		R[i].push_back(114514); 
		sort(R[i].begin(), R[i].end()); 
	}
	for(int i = 0; i < M; i++){
		C[i].push_back(-114514); 
		C[i].push_back(114514); 
		sort(C[i].begin(), C[i].end()); 
	}
  bool exception = 1; 
  for(int i = 1; i < M; i++){
   if(C[i].size() != N + 2) exception = 0; break; 
  }
  for(int i = 1; i < C[0].size() - 1; i++){
    if(C[0].at(i) != N + i + 1 - C[0].size()) exception = 0; 
  }
  if(exception){
    cout << "Yes" << endl; return 0; 
  }
	long long int count = 1; 
	int left = 0; int right = M-1; int top = 0; int bottom = N-1; 
	int nowx = 0; int nowy = 0; 
	while(1){
		int m1 = lower_bound(R[nowx].begin(), R[nowx].end(), nowy) - R[nowx].begin(); 
      if(nowy == right) break; 
		if(R[nowx].at(m1) > right){
			count += (long long) right - nowy; 
			nowy = right; 
		}
		else if(R[nowx].at(m1) == nowy + 1) break; 
		else{
			count += (long long) R[nowx].at(m1) - 1 - nowy; 
			nowy = R[nowx].at(m1) - 1; 
		}
		top = nowx + 1; // direction 1 
		int m2 = lower_bound(C[nowy].begin(), C[nowy].end(), nowx) - C[nowy].begin(); 
       if(nowx == bottom) break; 
		if(C[nowy].at(m2) > bottom){
			count += (long long) bottom - nowx; 
			nowx = bottom; 
		}
		else if(C[nowy].at(m2) == nowx + 1) break; 
		else{
			count += (long long) C[nowy].at(m2) - 1 - nowx; 
			nowx = C[nowy].at(m2) - 1; 
		}
		right = nowy - 1; // direction 2
		int m3 = lower_bound(R[nowx].begin(), R[nowx].end(), nowy) - R[nowx].begin(); 
      if(nowy == left) break; 
		if(R[nowx].at(m3-1) < left){
			count += (long long) nowy - left; 
			nowy = left; 
		}
		else if(R[nowx].at(m3-1) == nowy - 1) break; 
		else{
			count += (long long) nowy - R[nowx].at(m3-1) - 1; 
			nowy = R[nowx].at(m3-1) + 1; 
		}
		bottom = nowx - 1; // direction 3
		int m4 = lower_bound(C[nowy].begin(), C[nowy].end(), nowx) - C[nowy].begin(); 
      if(nowx == top) break; 
		if(C[nowy].at(m4-1) < top){
			count += (long long) nowx - top; 
			nowx = top; 
		}
		else if(C[nowy].at(m4-1) == nowx - 1) break; 
		else{
			count += (long long) nowx - C[nowy].at(m4-1) - 1; 
			nowx = C[nowy].at(m4-1) + 1; 
		}
		left = nowy + 1; // direction 4
	}
	long long int cell = (long long) N * M - K; 
	if(count == cell) cout << "Yes" << endl; 
	else cout << "No" << endl; 
}