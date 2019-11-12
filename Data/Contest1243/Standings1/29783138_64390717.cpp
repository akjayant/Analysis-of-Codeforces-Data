#include<bits/stdc++.h>
using namespace std;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
const int M=1e9+7;
const int maxn=5e5+5;


 
int main(){
 ios_base::sync_with_stdio(false);
 	
 	int t;
 	cin>>t;

 	while(t--){
 		int n;
 		cin>>n;

 		string s1,s2;
 		cin>>s1>>s2;

 		int cnt[26]={0};

 		set<int> v1[26],v2[26];

 		for(int i=0;i<n;i++){
 			cnt[s1[i]-'a']++;
 			cnt[s2[i]-'a']++;
 			if(s1[i]!=s2[i]){
 				v1[s1[i]-'a'].insert(i);
 				v2[s2[i]-'a'].insert(i);
 			}
 			
 		}

 		int flag=0;

 		f(i,0,26){
 			if(cnt[i]%2==1){
 				flag=1;
 				break;
 			}
 		}

 		if(flag){
 			cout<<"No"<<endl;
 			continue;
 		}

 		cout<<"Yes"<<endl;

 		vector<pair<int,int> > moves;

 		f(i,0,n){
 			int key=s1[i]-'a';
 			int key1=s2[i]-'a';
 			if(v1[key].find(i)!=v1[key].end())
 				v1[key].erase(i);
 			if(v2[key1].find(i)!=v2[key1].end())
 				v2[key1].erase(i);

 			if(s1[i]!=s2[i]){
 				
 				if(v1[key].size()!=0){
 					int ind=*v1[key].begin();
 					moves.push_back({ind+1,i+1});
 					//cout<<ind+1<<" "<<i+1<<endl;
 					swap(s1[ind],s2[i]);

 					v1[key].erase(v1[key].begin());
 					v1[key1].insert(ind);
 				}
 				else{
 					int ind=*v2[key].begin();
 					moves.push_back({ind+1,ind+1});
 					int tempkey=s1[ind]-'a';
 					swap(s1[ind],s2[ind]);
 					moves.push_back({ind+1,i+1});
 					swap(s1[ind],s2[i]);
 					v2[key].erase(v2[key].begin());
 					v1[tempkey].erase(ind);
 					v2[tempkey].insert(ind);
 					v1[key1].insert(ind);
 				}
 			}
 		}

 		cout<<moves.size()<<endl;

 		for(auto it:moves){
 			cout<<it.first<<" "<<it.second<<endl;
 		}

 	}
 	
 	
	return 0;
}