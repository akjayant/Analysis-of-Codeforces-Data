#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ipair pair<ll int,ll int>
#define veci vector<ll int>
#define vecb vector<bool>
#define vecp vector< ipair >
#define vecs vector<string>
#define vecc vector<char>
#define vecd vector< vector<int> >
#define us unordered_set
#define um unordered_map
#define mnh priority_queue<ll int,vector<ll int>,greater<ll int> >
#define mxh priority_queue<ll int>
#define ms(c,val) memset(c,val,sizeof(c))
#define ret return
#define mxe *max_element
#define mne *min_element
#define fi first
#define se second
#define br break
#define len length()
#define sz size()
#define em empty()
#define con continue
#define all(c) c.begin(),c.end()
using namespace std;
ll int M=1e9+7;
void swap(ll int *x,ll int *y){
    ll int t=*x;
    *x=*y;
    *y=t;
}

void init(vector<ll int> &v,ll int n){
    for(ll int i=0;i<n;i++){
        cin>>v[i];
    }
}
void print(vector<ll int> &v){
    for(ll int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void initg(vector< vector<ll int> > &v,ll int m){
    ll int i,x,y;
    for(i=0;i<m;i++){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
}

void swp(char *c1,char *c2){

    char c3=*c1;
    *c1=*c2;
    *c2=c3;
}

ll fnd(ll x,string s,char c){

    for(ll i=x;i<s.len;i++){
        if(s[i]==c){
            ret i;
        }
    }
    ret -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll int t1,n,m,x1,x2,x3,x4,x5,x6,k,i,j,x,y;
    string s1,s2,s,s3;
    bool t5;

    cin>>t1;
    while(t1--)
    {
        t5=true;
        cin>>n>>s1>>s2;
        vecp ans;
        for(i=0;i<n;i++){
                if(s1[i]==s2[i])
                    con;
            x1=fnd(i+1,s1,s1[i]);
            if(x1!=-1){
                ans.pb(mp(x1+1,i+1));
                swp(&s1[x1],&s2[i]);
                con;
            }
            x1=fnd(i,s2,s1[i]);
            if(x1==-1){
                cout<<"No"<<endl;
                t5=false;
                br;
            }
            ans.pb(mp(x1+1,x1+1));
            ans.pb(mp(x1+1,i+1));
            swp(&s1[x1],&s2[x1]);
            swp(&s1[x1],&s2[i]);

        }
        if(t5){
            cout<<"Yes"<<endl;
            cout<<ans.sz<<endl;
            for(i=0;i<ans.sz;i++){
                cout<<ans[i].fi<<" "<<ans[i].se<<endl;
            }
        }



















    }
}
