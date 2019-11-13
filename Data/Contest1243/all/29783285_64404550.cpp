#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <cstring>
#include <numeric>
#include <stack>
#include <iomanip>
using namespace std;
 
#define inf 200000000000000
#define mod 1000000007
#define eps 1e-7
#define PI 3.1415926535897932385
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",mark)
#define sl(mark) scanf("%lld",&mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define setinf(mark) memset(mark,0x3f,sizeof(mark))
 
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
 
#define int ll
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
 
#ifndef KaalaNamak
#define endl '\n'
#define trace(...)
#define start_routine() 
#define end_routine()
#endif
 
signed main() {
    start_routine();
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(10);
    int t=1;
    cin>>t;
    #ifdef KaalaNamak
        // t=3;
    #endif
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int arr[26];
        int qw[26];
        clr(arr);
        clr(qw);
        for(int i=0;i<n;i++){
            arr[a[i]-'a']++;
            qw[a[i]-'a']++;
            arr[b[i]-'a']++;
        }
        bool f=0;
        for(int i=0;i<26;i++){
            if(arr[i]%2!=0){
                f=1;
                break;
            }
            // trace(arr[i]);
        }
        if(f){
            cout<<"No\n";
            continue;
        }
        vp res;
        for(int i=0;i<(n-1);i++){
            qw[a[i]-'a']--;
            if(a[i]!=b[i]){
                if(qw[a[i]-'a']>0){
                    // trace(i);
                    int j;
                    for(j=(i+1);j<n;j++){
                        if(a[j]==a[i]) break;
                    }
                    res.pb(mp(j+1,i+1));
                    a[j]=b[i];
                    qw[a[j]-'a']++;
                    qw[a[i]-'a']--;
                }
                else{
                    int j;
                    for(j=(i+1);j<n;j++){
                        if(b[j]==a[i]) break;
                    }
                    res.pb(mp(i+2,j+1));
                    res.pb(mp(i+2,i+1));
                    b[j]=a[i+1];
                    qw[a[i+1]-'a']--;
                    a[i+1]=b[i];
                    qw[a[i+1]-'a']++;
                }
            }
        }
        cout<<"Yes\n";
        cout<<res.size()<<"\n";
        for(int i=0;i<res.size();i++){
            cout<<res[i].F<<" "<<res[i].S<<"\n";
        }
        
        
 
    }
    end_routine();
 
}