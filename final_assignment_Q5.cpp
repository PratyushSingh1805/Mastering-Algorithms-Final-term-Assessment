#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v,d;
        cin >> u >> v >> d;
        adj[u].push_back({v,d});
    }

    vector<long long> dist(n+1,1e18);
    dist[1]=0;
    set<pair<long long,int>> pq;
    pq.insert({0,1});

    while(!pq.empty()){
        auto it = *(pq.begin());
        int node = it.second;
        long long dis = it.first;
        pq.erase(it);
        for(auto it:adj[node]){
            int adjnode = it.first;
            long long edge = it.second;
            if(dist[adjnode]>dis+edge){
                if(dist[adjnode]!=1e18){
                    pq.erase({dist[adjnode],adjnode});
                }

                dist[adjnode]=dis+edge;
                pq.insert({dist[adjnode],adjnode});
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << dist[i] << ' ';
    }

    return 0;
}