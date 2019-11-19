    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int t;
        cin>>t;
        while(t--){
            int a , b , c , d , k;
            cin>>a>>b>>c>>d>>k;
            int ans = -1;
            for(int i = 0;i<=k;i++){
                if(c*i >= a && (k-i)*d >= b){
                    ans = i;
                    break;
                }
            }
            if(ans == -1)
                cout<<-1<<'\n';
            else
                cout<<ans<<' '<<(k-ans)<<'\n';
        }
        return 0;
    }