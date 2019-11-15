#include <bits/stdc++.h>
using namespace std;
int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int r,p,s;cin>>r>>p>>s;
		string st;cin>>st;
		int r1=0,p1=0,s1=0;
		queue<int> rq;
		queue<int> pq;
		queue<int> sq;
		int present[n] = {0};
		for(int i=0;i<n;i++){
			if(st[i] == 'R'){
				p1++;
				pq.push(i);
			}
			else if(st[i] == 'P'){
				s1++;
				sq.push(i);
			}
			else{
				r1++;
				rq.push(i);
			}
		}
		int wincount = (n+1)/2;
		int r2 = min(r,r1);
		int p2 = min(p,p1);
		int s2 = min(s,s1);

		if(r2+p2+s2>=wincount){
			cout<<"YES"<<endl;
			string out = "";
			for(int i=0;i<n;i++){
				out+="R";
			}
			int pdone = 0;
			int sdone = 0;
			while(p2--){
				out[pq.front()] = 'P';
				present[pq.front()] = 1;
				pq.pop();
				pdone++;
			}
			while(s2--){
				out[sq.front()] = 'S';
				present[sq.front()] = 1;
				sq.pop();
				sdone++;
			}
			while(r2--){
				present[rq.front()] = 1;
				rq.pop();
			}
			// cout<<pdone<<endl;
			// for(int i=0;i<n;i++){
			// 	cout<<present[i]<<" ";
			// 	cout<<endl;
			// }
			for(int i=0;i<n;i++){
				if(pdone==p){
					break;
				}
				if(present[i] == 0){
					present[i] = 1;
					out[i] = 'P';
					pdone++;
				}
			}
			for(int i=0;i<n;i++){
				if(sdone==s){
					break;
				}
				if(present[i] == 0){
					present[i] = 1;
					out[i] = 'S';
					sdone++;
				}
			}
			cout<<out<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}