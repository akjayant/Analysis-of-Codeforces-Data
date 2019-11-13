/***********************************************************
	When you are inspired by passion 
	and you want to live for the current moment

	When your every thought and action
	has the power to become the story of your future

	When difficulties stand to demolish your Glory
	Just remember that Life is a 'Golden adverse Story'

	Withstand it to acheive your passion and dreams
	more amazingly more easily.

	Why then? When writing the story of your Life
	You want to Let someone else hold your pen

					huzaifa242©

***********************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int int32_t
#define MAX 100005
#define x first 
#define y second

int seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l=0,int r=INT_MAX)
{return uniform_int_distribution<int>(l,r)(rng);}

template <typename T,typename G>
ostream& operator << (ostream& out, const pair<T,G> &a) 
{return out<<"("<<a.x<<" , "<<a.y<<")";}

template <typename T>
ostream& operator << (ostream& out, const vector<T> &a) 
{out<<"[";for(const auto &i:a)out<<i<<" , ";return out<<"]"<<endl;}

template <typename T>
ostream& operator << (ostream& out, const set<T> &a) 
{out<<"{";for(const auto &i:a)out<<i<<" , ";return out<<"}"<<endl;}

template <typename T,typename G>
ostream& operator << (ostream& out, const map<T,G> &a) 
{out<<"<";for(const auto &i:a)out<<i<<" , ";return out<<">"<<endl;}

template<typename T, size_t N>
typename enable_if<!is_same<typename remove_cv<T>::type, char>::value,
ostream&>::type operator<<(ostream& out, T(&a)[N])
{out<<'[';for(size_t i=0;i<N;++i)out<<a[i]<<" , ";out <<"]"<<endl;return out;}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);  
	#endif
	int t;
	cin>>t;
	while(t--){
		int n,i,j;
		cin>>n;
		string a,b;
		cin>>a>>b;
		vector<int> cnt(26,0);
		for(i=0;i<n;i++){
			cnt[a[i]-'a']++;
			cnt[b[i]-'a']++;
		}
		for(i=0;i<26;i++){
			if(cnt[i]&1)
				break;
		}
		if(i<26){
			cout<<"No\n";
			continue;
		}
		vector<pair<int,int> > ans;
		for(i=0;i<n;i++){
			if(a[i]==b[i])
				continue;
			int ps=-1;
			for(j=i+1;j<n;j++){
				if(b[j]==b[i]){
					ps=j;
					break;
				}
			}
			if(ps==-1){
				for(j=i+1;j<n;j++){
					if(b[i]==a[j]){
						ps=j;
						break;
					}
				}
				swap(a[ps],b[ps]);
				ans.push_back({ps,ps});
			}
			swap(a[i],b[ps]);
			ans.push_back({i,ps});
		}
		cout<<"Yes\n";
		cout<<ans.size()<<"\n";
		for(auto u:ans)
			cout<<u.x+1<<" "<<u.y+1<<"\n";
	}
	return 0;
}
