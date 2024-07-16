#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,size;
public :
    DisjointSet(int V){
        parent.resize(V+1);
        size.resize(V+1,1);
        for(int i=0; i<=V; i++){
            parent[i]=i;
        }
    }

    int findpar(int i){
        if(parent[i]==i) return i;
        return parent[i]=findpar(parent[i]);
    }

    int findimpar(int i){
        return parent[i];
    }

    void union_size(int u,int v){
        int up_u=findpar(u);
        int up_v=findpar(v);
        if(up_u!=up_v){
            if(size[up_u]>size[up_v]){
                parent[up_v]=up_u;
                size[up_u]+=size[up_v];
            }
            else{
                parent[up_u]=up_v;
                size[up_v]+=size[up_u];
            }
        }
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    DisjointSet roads(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        roads.union_size(u,v);
    }

    vector<int> ultpar;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(roads.findimpar(i)==i){
            ultpar.push_back(i);
            cnt++;
        }
    }

    cout << cnt-1 << '\n';

    for(int i=0; i<cnt-1; i++){
        cout << ultpar[i] << ' ' << ultpar[i+1] << '\n';
    }

    return 0;
}