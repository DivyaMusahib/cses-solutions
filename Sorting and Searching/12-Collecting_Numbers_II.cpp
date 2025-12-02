// https://cses.fi/paste/6465b768050a6860ec019f/
/*
    Same logic as previous one 
    the differnce is queries 
    we know if we swap 2 indices 
    we dont need to re calculate the answer we can check the change in number of rounds
    occured when swapped 2 indexes 
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    int n , m;
    cin >> n >> m;

    vector<int>mpInd(n+2);
    vector<int>mpNum(n+2);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        mpInd[i] = x;
        mpNum[x] = i;
    }
    mpNum[n+1] = n+1;
    mpInd[n+1] = n+1;
    mpNum[0] = 0;
    mpInd[0] = 0;
    
    long long ans = 1;
    long long prev = 0;
    for(auto j : mpNum) {
        if(j < prev) ans++;
        prev = j;
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int numA = mpInd[a], numB = mpInd[b];
        if(a == b) {}
        else if(abs(numA-numB) == 1) {
            
            int cnt = 0;
            for(int ii = min(numA, numB) ; ii <= max(numA, numB) + 1; ii++) {
                if(mpNum[ii] < mpNum[ii-1]) cnt++;
            }
            
            mpInd[a] = numB;
            mpInd[b] = numA;
            
            mpNum[numA] = b;
            mpNum[numB] = a;            
            
            int cnt2 = 0;
            for(int ii = min(numA, numB) ; ii <= max(numA, numB) + 1; ii++) {
                if(mpNum[ii] < mpNum[ii-1]) cnt2++;
            }
            
            ans += (cnt2 - cnt);
            
        } else {
            
            if(mpNum[numA-1] < mpNum[numA] && mpNum[numA] < mpNum[numA+1]) {
                
                if(mpNum[numA-1] > mpNum[numB]) ans++;
                if(mpNum[numB] > mpNum[numA+1]) ans++;
                
            } else if(mpNum[numA-1] < mpNum[numA] && mpNum[numA] > mpNum[numA+1]) {
                
                if(mpNum[numA-1] > mpNum[numB]) ans++;
                if(mpNum[numB] < mpNum[numA+1]) ans--;
                
            } else if(mpNum[numA-1] > mpNum[numA] && mpNum[numA] < mpNum[numA+1]) {
                
                if(mpNum[numA-1] < mpNum[numB]) ans--;
                if(mpNum[numB] > mpNum[numA+1]) ans++;
                
                
            } else if(mpNum[numA-1] > mpNum[numA] && mpNum[numA] > mpNum[numA+1]) {
                
                if(mpNum[numA-1] < mpNum[numB]) ans--;
                if(mpNum[numB] < mpNum[numA+1]) ans--;
                
            }

            
            if(mpNum[numB-1] < mpNum[numB] && mpNum[numB] < mpNum[numB+1]) {
                
                if(mpNum[numB-1] > mpNum[numA]) ans++;
                if(mpNum[numA] > mpNum[numB+1]) ans++;
                
            } else if(mpNum[numB-1] < mpNum[numB] && mpNum[numB] > mpNum[numB+1]) {
                
                if(mpNum[numB-1] > mpNum[numA]) ans++;
                if(mpNum[numA] < mpNum[numB+1]) ans--;
                
            } else if(mpNum[numB-1] > mpNum[numB] && mpNum[numB] < mpNum[numB+1]) {
                
                if(mpNum[numB-1] < mpNum[numA]) ans--;
                if(mpNum[numA] > mpNum[numB+1]) ans++;
                
                
            } else if(mpNum[numB-1] > mpNum[numB] && mpNum[numB] > mpNum[numB+1]) {
                
                if(mpNum[numB-1] < mpNum[numA]) ans--;
                if(mpNum[numA] < mpNum[numB+1]) ans--;
                
            }
            
            mpInd[a] = numB;
            mpInd[b] = numA;
            
            mpNum[numA] = b;
            mpNum[numB] = a;
        }
        
        cout << ans << "\n";
    }
}