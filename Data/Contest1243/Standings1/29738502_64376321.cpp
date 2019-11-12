#include <bits/stdc++.h>
using namespace std;

int main()
{
 //freopen("bath.in","r",stdin);
 //freopen("bath.out","w",stdout);
 ios_base::sync_with_stdio(0);
 int t;
 cin>>t;
 for(int ii=0;ii<t;ii++){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int kol=0,fl=-1;
    for(int i=0;i<s1.size();i++)
    if (s1[i]!=s2[i]){kol++;
        if (kol==2) swap(s1[fl],s2[i]);
        fl=i;
    }
    if (kol==2&&s1==s2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
 }
}


