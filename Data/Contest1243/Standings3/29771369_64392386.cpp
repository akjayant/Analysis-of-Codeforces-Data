#include <bits/stdc++.h>
using namespace std;
#define opt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long int
// I might be a loser, but I have nothing to lose :p
int main()
{
opt;
ll k,n,f,f1;
string s,t;
cin>>k;
while(k--)
{
    vector<int> m(26);
    cin>>n;
    cin>>s>>t;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
            ans.push_back(i);
    }
    if(ans.empty()==1 || (ans.size()==2 && s[ans[0]]==s[ans[1]] && t[ans[0]] == t[ans[1]]) )
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
return 0;
}