//
//  main.cpp
//  Codeforces Round #597 (Div. 2)
//
//  Created by Augustinas Jucas on 01/11/2019.
//  Copyright © 2019 Augustinas Jucas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const long long dydis = 2104;
bool found[dydis] = {false};
long long atstumas[dydis] = {0};
long long isKur[dydis] = {0};
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<pair<long long, long long>> city;
    vector<long long> cost(n);
    vector<long long> con(n);
    long long ats = 0;
    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        city.push_back({a, b});
    }
    for(long long i = 0; i < n; i++) cin >> cost[i];
    for(long long i = 0; i < n; i++) cin >> con[i];
    for(long long i = 0; i < n; i++) atstumas[i] = cost[i];
    for(long long i = 0; i < n; i++) isKur[i] = i;
    while(true){
        bool br = true;
        for(long long i = 0; i < n; i++){
            br = br && found[i];
        }
        if(br) break;
        pair<long long, long long> minCity = {7000000000000000000, 7000000000000000000};
        for(long long i = 0; i < n; i++){
            if(found[i]) continue;
            minCity = min(minCity, {atstumas[i], i});
        }
        long long atIkiV = minCity.first;
        long long v = minCity.second;
        
        //cout << "Rastas maziausias atstumas = " << atIkiV << " (iki) " << v << endl;
        
        found[v] = true;
        ats += atIkiV;
        for(long long i = 0; i < n; i++){
            if(found[i]) continue;
            if(atstumas[i] > (abs(city[v].first - city[i].first) + abs(city[v].second - city[i].second)) * (con[i] + con[v])){
                atstumas[i] = (abs(city[v].first - city[i].first) + abs(city[v].second - city[i].second)) * (con[i] + con[v]);
                isKur[i] = v;
            }
        }
        
    }
    
    vector<long long> pats;
    vector<long long> su;
    for(long long i = 0; i < n; i++){
        if(isKur[i] == i) pats.push_back(i);
        else su.push_back(i);
    }
    
    cout << ats << "\n";
    cout << pats.size() << "\n";
    for(long long i = 0; i < pats.size(); i++) cout << pats[i]+1 << " ";
    cout << "\n" << su.size() << "\n";
    for(long long i = 0; i < su.size(); i++){
        
        cout << su[i] +1<< " " << isKur[su[i]]+1 << "\n";
    }
    
    
    return 0;
}
