// https://cses.fi/paste/b7dffd1e4bb29bc4ec5e93/
/*
    What we can do is that maintain the length of intervals in one data structure
    another data structure we need is that when we add a traffic light the length of interval changes
    we need to get the interval coordinates
    
    Analyse what functionalities do we need
    - maintaining length 
    - accessing max length
    - removing length
    - adding new length
    - finding interval ie upperbound and upperbound-1 on adding new traffic light
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    map<int, int>lengths;
    set<int>trafficLightPos;
    
    trafficLightPos.insert(0);
    trafficLightPos.insert(x);
    lengths[x]++;

    for(int i = 0 ; i < n; i++) {
        int pos;
        cin >> pos;
        auto l = trafficLightPos.upper_bound(pos);
        auto r = l;
        --l;
        int currLength = *r - *l;
        lengths[currLength]--;
        if(lengths[currLength] == 0) lengths.erase(currLength);
        trafficLightPos.insert(pos);
        lengths[*r - pos]++;
        lengths[pos - *l]++;


        cout << lengths.rbegin()->first << " ";
    }
}