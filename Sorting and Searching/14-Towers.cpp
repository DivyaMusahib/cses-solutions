// https://cses.fi/paste/b07fc28955c414e2ec38b3/
/*
    We can have a data structure which stores the top element size and we could easily search over it
    one such thing is a multiset , we can store the top cube size in the multiset
    as when we add a new cube we can find the cube whose size is just bigger than the current one
    using upperbound and then put the current cube on that cube removing that one
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    multiset<int>st;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        auto it = st.upper_bound(x);
        if(it != st.end()) {
            st.erase(it);
        } 
        st.insert(x);
    }
    cout << st.size();
}