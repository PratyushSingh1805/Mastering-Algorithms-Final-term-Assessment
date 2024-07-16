#include<bits/stdc++.h>
using namespace std;

# define M 1000000007

int main(){
    int n,sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> prev(sum+1,0);
    vector<int> curr(sum+1,0);
    for(int j=0; j<=sum; j++){
        if(j%arr[0]==0) prev[j]=1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=sum;j++){
            if(j>=arr[i]) curr[j]=(prev[j]+curr[j-arr[i]])%M;
            else curr[j]=prev[j];
        }
        prev = curr;
    }

    cout << prev[sum];
    return 0;

}