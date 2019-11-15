#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main()
{
	int t;
	cin>>t;
	while(t--){
        int c1[3];
        int c2[3];
        memset(c1,0,sizeof c1);
            memset(c2,0,sizeof c2);
        string s;
        int n;
        cin>>n;
        for(int i=0;i<3;i++)cin>>c1[i];
        cin>>s;
        for(auto x:s){
            if(x=='R')c2[0]++;
            else if(x=='P')c2[1]++;
            else c2[2]++;
        }
        int k=0;
        for(int i=0;i<3;i++){
            int x=min(c2[i],c1[(i+1)%3]);
            k+=x;
        }

        if(k>=(n+1)/2){
            puts("YES");
            vector<int> ans(n,-1);
            for(int i=0;i<n;i++){
                int id=0;
                if(s[i]=='P')id=1;
                else if(s[i]=='S')id=2;
                int id2=(id+1)%3;
                if(c1[id2]){
                    c1[id2]--;
                    ans[i]=id2;
                }
            }
            for(int i=0;i<n;i++){
                if(ans[i]==-1){
                    for(int j=0;j<3;j++){
                        if(c1[j]){
                            c1[j]--;
                            ans[i]=j;
                            break;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                char x='R';
                if(ans[i]==1)x='P';
                else if(ans[i]==2)x='S';
                cout<<x;
            }
            cout<<endl;
        }else {
            puts("NO");
        }
	}
    return 0;
}
