// https://cses.fi/paste/6b89df4c18b7616deb6482/
/*
    We can store the values which had came till now with thier index in the map
    and check if (target - currValue) is available in map or not 
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    map<int,int>mp;
    for(int i=1; i<=n; i++) {
        int curr;
        cin >> curr;
        int x = target - curr;
        if(mp.find(x) != mp.end()) {
            cout << i << " " << mp[x] ;
            return 0;
        }
        mp[curr] = i;
    }
    cout << "IMPOSSIBLE";
}

// https://cses.fi/paste/40178b60fd9221fceb6540/
/*
    While above code has nlogn time complexity using map , we can do this by sorting also
    using a 2-pointer approach if the target sum is bigger we move the smaller pointer ahead
    else move the larger point backwards
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , target;
    cin >> n >> target;
    vector<pair<int,int>>a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int i = 0, j = n-1;
    while(i < j) {
        long long sum = a[i].first + a[j].first;
        if(sum == target) {
            cout << a[i].second << " " << a[j].second << "\n";
            return 0;
        } else if(sum > target) {
            j--;
        } else {
            i++;
        }
    }
    cout << "IMPOSSIBLE";
}