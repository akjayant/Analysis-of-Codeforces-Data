#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN=1e5;

ll n,d,e,ide,a1,b1,c1,rj,br,a2,b2,c2;
ll a[5][MAXN+5];
vector <int> djc[MAXN+5];
int boja[MAXN+5];

void DFS(int x){
	for(int i=0; i<djc[x].size(); i++){
		if(boja[djc[x][i]]==0){
			boja[djc[x][i]]=boja[x]%3+1;
			DFS(djc[x][i]);
		}
	}
}

int main () {
	
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[0][i];
	}
	for(int i=0; i<n; i++){
		cin>>a[1][i];
	}
	for(int i=0; i<n; i++){
		cin>>a[2][i];
	}
	for(int i=0; i<n-1; i++){
		cin>>d>>e;
		djc[d-1].PB(e-1);
		djc[e-1].PB(d-1);
		if(djc[d-1].size()>2){
			cout<<"-1";
			return 0;
		}
		if(djc[e-1].size()>2){
			cout<<"-1";
			return 0;
		}
	}
	for(int i=0; i<n; i++){
		if(djc[i].size()==1){
			ide=i;
			break;
		}
	}
	boja[ide]=1;
	DFS(ide);
	rj=1e15;
	for(int i=0; i<=2; i++){
		for(int j=0; j<=2; j++){
			for(int k=0; k<=2; k++){
				a1=i;
				b1=j;
				c1=k;
				if(a1!=b1 && a1!=c1 && b1!=c1){
					br=0;
					for(int l=0; l<n; l++){
						if(boja[l]==1){
							br+=a[a1][l];
						}
						if(boja[l]==2){
							br+=a[b1][l];
						}
						if(boja[l]==3){
							br+=a[c1][l];
						}
					}
					if(br<rj){
						rj=br;
						a2=a1;
						b2=b1;
						c2=c1;
					}
				}
			}
		}
	}
	cout<<rj<<endl;
	for(int l=0; l<n; l++){
						if(boja[l]==1){
							cout<<a2+1<<" ";
						}
						if(boja[l]==2){
							cout<<b2+1<<" ";
						}
						if(boja[l]==3){
							cout<<c2+1<<" ";
						}
					}
	
	return 0;
}
