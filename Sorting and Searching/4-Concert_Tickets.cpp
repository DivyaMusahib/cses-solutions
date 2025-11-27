// https://cses.fi/paste/80f05a3f5fd5431ceb3e36/
/*
    We need to know the just smaller or equal to price , we can use a multiset and perform binary search in it
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>h(n), t(m);
    for(auto &i : h) cin >> i;  
    for(auto &i : t) cin >> i;  
    multiset<int>st(h.begin(), h.end());
    for(int i=0; i<m; i++) {
        // upper_bound(st.begin(), st.end(), ...) is the generic STL algorithm, which does linear scan on iterators of multiset, costing O(n) every query.
        // auto it = upper_bound(st.begin(), st.end(), t[i]);

        /*
            std::upper_bound on containers: uses iterator range → O(n)
            multiset.upper_bound method: tree lookup → O(log n)
        */

        auto it = st.upper_bound(t[i]);
        if(it == st.begin()) cout << -1 << "\n";
        else {
            --it;
            cout << *it << "\n";
            st.erase(it);
        }
    }
}