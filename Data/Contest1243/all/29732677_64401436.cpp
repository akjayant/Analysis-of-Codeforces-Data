#include<bits/stdc++.h>

using namespace std;

#define Q int t, q; scanf("%d", &t); for(q=1; q<=t; q++)
#define lli long long int

int zero[1000000];

int main()
{
    Q
    {
        int n, i, j;
        map<char, int> mp;
        vector<pair<int, int> > v;
        string a, b;
        cin >> n >> a >> b;
        for(i=0; i<n; i++){
            mp[a[i]]++;
            mp[b[i]]++;
        }
        bool fl=true;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(it->second%2){
                fl = false;
                break;
            }
        }
        if(fl){
            printf("Yes\n");
        }
        else{
            printf("No\n");
            continue;
        }
        for(i=0; i<n; i++){
            if(a[i] != b[i]){
                fl = true;
                for(j=i+1; j<n; j++){
                    if(a[i] == b[j]){
                        v.push_back({(i+1), (i+1)});
                        swap(a[i], b[i]);
                        v.push_back({(i+1), (j+1)});
                        swap(a[i], b[j]);
                        fl = false;
                        break;
                    }
                }
                if(fl){
                    for(j=i+1; j<n; j++){
                        if(a[i] == a[j]){
                            v.push_back({(j+1), (i+1)});
                            swap(a[j], b[i]);
                            break;
                        }
                    }
                }
            }
        }
        cout << v.size() << "\n";
        for(auto it=v.begin(); it!=v.end(); it++){
            cout << it->first << " " << it->second << "\n";
        }
    }

    return 0;
}
