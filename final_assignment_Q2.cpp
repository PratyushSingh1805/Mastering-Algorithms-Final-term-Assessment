#include<bits/stdc++.h>
using namespace std;    
    
    
static bool comparator(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}

int scheduleCourse(vector<vector<int>>& courses) {

    sort(courses.begin(),courses.end(),comparator);
    priority_queue<int> pq;
    int total = 0;
    for(auto it:courses){
        pq.push(it[0]);
        total+=it[0];
        if(total>it[1]){
            total-=pq.top();
            pq.pop();
        }
    }

    return pq.size();
}