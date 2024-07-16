#include<bits/stdc++.h>
using namespace std;

# define M 1000000007

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> adj[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            if(temp){
                adj[i].push_back(j);
            }
        }
    }

    vector<int> prev(n,1);
    vector<int> curr(n,0);

    for(int i=2; i<=k+1; i++){
        for(int j=0; j<n; j++){
            int sum = 0;
            for(auto it:adj[j]){
                sum=(sum+prev[it])%M;
            }
            curr[j]=sum;
        }
        prev = curr;
    }

    int finsum = 0;
    for(int i=0; i<n; i++){
        finsum=(finsum+prev[i])%M;
    }

    cout << finsum;

    return 0;
}