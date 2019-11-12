#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define fin for(i=0;i<n;i++)
#define fim for(i=0;i<m;i++)
#define fjn for(j=0;j<n;j++)
#define fjm for(j=0;j<m;j++)
#define pb push_back
 
ll i,j,k,t;

int main(){
	cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        ll h1[200]={0},h2[200]={0};

        fin{
            h1[s1[i]]++;
            h2[s2[i]]++;
        }
        ll f=0;
        for(i=1;i<200;i++){
            if((h1[i]+h2[i])%2==1){
                f=1;
                break;
            }
        }
        vector <pair<ll,ll> > v;
        if(f==0){
            for(i=0;i<n;i++){
                
                if(s1[i]!=s2[i]){
                    fjn{
                        h1[s1[j]]=0;
                        h1[s2[j]]=0;
                        h2[s1[j]]=0;
                        h2[s2[j]]=0;
                    }
                    fjn{
                        h1[s1[j]]++;
                        h2[s2[j]]++;
                    }

                    //cout<<s1<<" "<<s2<<endl;
                    if(h2[s1[i]]<h1[s1[i]]){
                        for(j=i+1;j<n;j++){
                            if(s1[j]==s1[i]){
                                break;
                            }
                        }
                        v.pb(make_pair(j+1,i+1));
                        /*h2[s2[i]]--;
                        h2[s1[i]]++;
                        h1[s1[i]]--;
                        h1[s2[i]]++;*/
                        swap(s1[j],s2[i]);
                    }else{
                        for(j=i+1;j<n;j++){
                            if(s2[j]==s1[i]){
                                break;
                            }
                        }
                        v.pb(make_pair(n,j+1));
                        v.pb(make_pair(n,i+1));
                        
                        /*h2[s1[n-1]]++;
                        h1[s2[i]]--;*/
                        swap(s1[n-1],s2[j]);
                        swap(s1[n-1],s2[i]);
                    }
                }
            }
        }
        //cout<<s1<<" "<<s2<<endl;
        if(f==0){
            cout<<"Yes\n";
            cout<<v.size()<<endl;
            for(i=0;i<v.size();i++){
                cout<<v[i].first<<" "<<v[i].second<<endl;
            }
        }else{
            cout<<"No\n";
        }
    }
}