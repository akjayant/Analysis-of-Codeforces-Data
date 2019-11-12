#include <bits/stdc++.h>

using namespace std;
int n,q,c,k,r,p,sc,a,b,o,aa,lsc,bb,cc,jj,arrs[102],arrt[102];
string s,t;
char a1,a2,b1,b2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int l=0;l<q;l++){
        cin>>n;
        cin>>s>>t;
        int ltrs[26]={0};
        int ltrt[26]={0};
        for(int i=0;i<n;i++){
            ltrs[s[i]-'a']++;
            ltrt[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if((ltrs[i]+ltrt[i])%2!=0){a=-1;break;}
        }
        //for(int i=0;i<26;i++) cout<<ltrt[i];
        if(a==-1){
            cout<<"No"<<'\n';
            a=0;
            continue;
        }

        a=aa=0;
        for(int i=0;i<n;i++){
            aa=0;
            if(s[i]==t[i]) continue;
            for(int j=i+1;j<n;j++){
                if(s[j]!=s[i]) continue;
                s[j]=t[i];
                t[i]=s[i];
                arrs[a]=j+1;
                arrt[a]=i+1;
                a++;
                aa=1;
                break;
            }
            if(aa==1) continue;
            for(int j=i+1;j<n;j++){
                if(t[j]!=t[i]) continue;
                t[j]=s[i];
                s[i]=t[i];
                arrs[a]=i+1;
                arrt[a]=j+1;
                a++;
                aa=1;
                break;
            }
            if(aa==1) continue;
            for(int j=i+1;j<n;j++){
                if(t[j]!=s[i]) continue;
                t[j]=s[j];
                s[j]=s[i];
                arrs[a]=arrt[a]=j+1;
                a++;
                i--;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                cout<<"No"<<'\n';
                continue;
            }
        }
        cout<<"Yes"<<'\n';
        cout<<a<<'\n';
        for(int i=0;i<a;i++){
            cout<<arrs[i]<<' '<<arrt[i]<<'\n';
        }
        /*for(int i=0;i<n;i++){
            if(s[i]==t[i]) continue;
            c++;
            if(c>2) break;
            if(c==1) {a1=s[i]; b1=t[i]; continue;}
            if(c==2) {a2=s[i]; b2=t[i]; continue;}
        }
        if(c>2 || c==1){cout<<"No"<<'\n';continue;}
        if(a1==a2 && b2==b1){cout<<"Yes"<<'\n';continue;}
        else{cout<<"No"<<'\n';continue;}*/
    }
}
