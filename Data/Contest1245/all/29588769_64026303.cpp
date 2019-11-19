#include <bits/stdc++.h>
using namespace std;
const int N =2e3+9;
const int MX = 5e6;
const int mod = 1e9+7;
typedef long long ll;

ll c[N],k[N];
int link[N],size[N];
bool don[N];
pair<int,int> p[N];
ll man(int i,int j){
	//cout<<i<<" "<<j<<" "<<(abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second))<<endl;
	return (k[i]+k[j])*(abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second));
}
int find(int x){
	if(x!=link[x]){
        link[x]=find(link[x]);
    }
    return link[x];
}
bool same(int a,int b){
    return find(a)==find(b);
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(size[b]>size[a])
        swap(a,b);
    size[a]+=size[b];
    link[b]=a;
    don[a] = don[b]|don[a];
}
int main() {  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,a,b;
	cin>>n;
	vector<pair<ll,pair<int,int>>> ed;
	for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++) cin>>k[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			ed.push_back({man(i,j),{i+1,j+1}});
		}
	for(int i=0;i<n;i++) ed.push_back({c[i],{-1,i+1}}); // for points
	sort(ed.begin(),ed.end());
	int sz = ed.size();
	for(int i=1;i<=n;i++)
            link[i]=i,size[i]=1;
    ll ans = 0;
    vector<int> light;
    vector<pair<int,int>> con;
    for(int i=0;i<sz;i++){
        a=ed[i].second.first;
        b=ed[i].second.second;
        //cout<<ed[i].first<<" "<<a<<" "<<b<<endl;
        if(a==-1){ // point
        	//cout<<"-1 "<<find(b)<<" "<<don[find(b)]<<endl;
        	if(don[find(b)]) continue;
        	ans+= c[b-1];
        	light.push_back(b);
        	don[find(b)] = true;
		}
		else{
        	//cout<<"yo "<<find(a)<<" "<<don[find(a)]<<endl;
        	//cout<<"yoyo "<<find(b)<<" "<<don[find(b)]<<endl;
			if(don[find(a)]&don[find(b)]) continue;
			if(!same(a,b)){
				unite(a,b);
	            ans+=ed[i].first;
	            con.push_back({a,b});
			}
		}
    }
	cout<<ans<<"\n";
	cout<<light.size()<<"\n";
	for(auto u:light) cout<<u<<" ";
	cout<<"\n"<<con.size()<<"\n";
	for(auto u:con) cout<<u.first<<" "<<u.second<<"\n";
}