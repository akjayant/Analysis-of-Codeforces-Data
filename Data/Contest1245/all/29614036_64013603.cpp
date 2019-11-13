#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long>
#define pll pair<long long, long long>
#define pt complex<double>
#define ft first
#define sc second
#define mod 1000000007
using namespace std;

int res[100005];

int main(){
    int i;
    string s;
    cin>>s;
    res[0] = 1;
    res[1] = 1;
    bool malo = false;
    if(s[0] == 'm' || s[0] == 'w')malo = true;
    for(i=1; i<s.length(); i++){
        res[i+1] = res[i];
        if(s[i] == 'm' || s[i] == 'w')malo = true;
        if(s[i] == 'u' && s[i-1] == 'u' || s[i] == 'n' && s[i-1] == 'n'){
            res[i+1] = (res[i+1] + res[i-1])% mod;
        }
    }
    if(malo)cout<<0<<endl;
    else cout<<res[s.length()]<<endl;
}
