#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void prim(int **a, int n, int s){
    int parent[n];
    int key[n];
    bool mstset[n];
    
    for(int i=0;i<n;i++){
        key[i] = INT_MAX;
        mstset[i]=false;
    }
    key[s]=0;
}

int main() {
    int n,m;
    cin>>n>>m;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;i<n;i++){
            a[i][j] = 0;
        }    
    }
    int s,d,w;
    while(m--){
        cin>>s>>d>>w;
        a[s][d] = w;
    }
    int beg;
    cin>>beg;
        
    return 0;
}
