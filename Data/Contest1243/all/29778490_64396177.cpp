#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("testcases.txt", "r", stdin);
 
    int t;
    cin>>t;
 
    while(t--) {
        int n;
        cin>>n;
 
        string a,b;
        cin>>a>>b;
 
        if(a==b) {
            cout<<"Yes"<<endl;
            continue;
        }

        vector<pair<int,int> >ans;
        bool ok=1;

        for(int i=0;i<n;i++) {
            if(a[i]!=b[i]) {
                int plc=-1;
                for(int j=i+1;j<n;j++) {
                    if(a[j]==a[i]) {
                        plc=j;
                        break;
                    }
                }
                if(plc!=-1) {
                    swap(a[plc],b[i]);
                    ans.push_back({plc+1,i+1});
                    continue;
                }

                for(int j=i+1;j<n;j++) {
                    if(b[j]==a[i]) {
                        plc=j;
                        break;
                    }
                }

                if(plc==-1) {
                    ok=0;
                    break;
                }

                swap(b[plc],a[plc]);
                ans.push_back({plc+1,plc+1});
                swap(a[plc],b[i]);
                ans.push_back({plc+1,i+1});

            }
        }

        if(ok) {
            cout<<"Yes"<<endl;
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++) {
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
        } else {
            cout<<"No"<<endl;
        }
    }
 
 
 
 
    return 0;
}