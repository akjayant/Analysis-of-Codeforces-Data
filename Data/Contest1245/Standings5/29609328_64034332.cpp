#include<bits/stdc++.h>

using namespace std;

class pont{
public:
	long long x, y, c, k;
	int szulo;
	int index;
	bool vanAram=0;
	int getSzulo();
	void merge(int mivel);
};

class fejlesztes{
public:
	bool kabel;
	int x, y;
	long long ar;
};

vector<pont> p;

int pont::getSzulo(){
	if(index==szulo) return index;
	return szulo=p[szulo].getSzulo();
}

void pont::merge(int mivel){
	if(szulo==index && mivel == p[mivel].szulo){
		szulo=mivel;
	} else {
		p[getSzulo()].merge(p[mivel].getSzulo());
	}
}

int n;

vector<fejlesztes> f;

bool operator<(fejlesztes f1, fejlesztes f2){
	return f1.ar < f2.ar;
}

int ab(int a){
	if(a>0) return a;
	return -a;
}

int main(){
	cin >> n;
	p.resize(n);
	f.resize(n*n);
	for(int i=0;i<n;i++){
		p[i].szulo=i;
		p[i].index=i;
		cin >> p[i].x;
		cin >> p[i].y;
	}
	for(int i=0;i<n;i++){
		cin >> p[i].c;
	}
	for(int i=0;i<n;i++){
		cin >> p[i].k;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				f[i*n+j]={0,i,i,p[i].c};
			} else {
				f[i*n+j]={1,i,j,(p[i].k+p[j].k)*(ab(p[i].x-p[j].x)+ab(p[i].y-p[j].y))};
			}
		}
	}
	sort(f.begin(),f.end());
	vector<int> allomas;
	vector<pair<int,int>> vez;
	long long ossz=0;
	for(int i=0;i<f.size();i++){
		if(f[i].kabel){
			if((!p[f[i].x].vanAram || !p[f[i].y].vanAram) && p[f[i].x].getSzulo() != p[f[i].y].getSzulo()){
				if(p[f[i].x].vanAram){
					int s = p[f[i].y].getSzulo();
					for(int j=0;j<n;j++){
						if(p[j].getSzulo()==s){
							p[j].vanAram=1;
						}
					}
				}
				if(p[f[i].y].vanAram){
					int s = p[f[i].x].getSzulo();
					for(int j=0;j<n;j++){
						if(p[j].getSzulo()==s){
							p[j].vanAram=1;
						}
					}
				}
				p[f[i].x].merge(f[i].y);
				vez.push_back({f[i].x,f[i].y});
				ossz+=f[i].ar;
			}
		} else {
			if(!p[f[i].x].vanAram){
				allomas.push_back(f[i].x);
				int s = p[f[i].x].getSzulo();
				for(int j=0;j<n;j++){
					if(p[j].getSzulo()==s){
						p[j].vanAram=1;
					}
				}
				ossz+=f[i].ar;
			}
		}
	}
	cout << ossz << "\n";
	cout << allomas.size() << "\n";
	for(int i:allomas) cout << i+1 << " ";
	cout << "\n" << vez.size() << "\n";
	for(pair<int,int> i:vez) cout << i.first+1 << " " << i.second+1 << "\n";
return 0;
}