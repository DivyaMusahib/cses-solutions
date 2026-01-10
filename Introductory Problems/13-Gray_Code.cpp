// Method - 1 https://cses.fi/paste/4c712d53ce3b6fc2f20a7b/
// Method - 2 https://cses.fi/paste/3b67a56bda98e1acf20b02/

/*
    There are 2 Method to generate gray codes
    1) Direct formula based
        - graycode -> int n = n ^ (n >> 1)
        - https://cp-algorithms.com/algebra/gray-code.html
    
    2) Reflection property
        - we use a reflection property
        suppose we need to find gray code for n = 3, so we need 2 
        - we will put all the gray codes of 2 and append '0' in front of all of them
        - we will now arrange the gray code of 2 in reverse order of occurence and append '1' in front of all of them

        0           0 --->  00          00  --->    000
        1           1 --->  01          01  --->    001
                    ______              11  --->    011
                    1 --->  11          10  --->    010
                    0 --->  10          _______
                                        10  --->    110
                                        11  --->    111
                                        01  --->    101
                                        00  --->    100
*/
// Method 1 - Formula Based
// #include<bits/stdc++.h>
// using namespace std;

// string getGrayCode(int x, int n) {
//     int num = x ^ (x >> 1);
//     string s = "";
//     while(n--) {
//         if(num&1) s = '1' + s;
//         else s = '0' + s;
//         num = num >> 1;
//     }
//     return s;
// }

// int main() {
//     int n;
//     cin >> n;
//     for(int i = 0; i < (1 << n); i++) {
//         cout << getGrayCode(i, n) << "\n";
//     }
// }

// Method - 2
#include<bits/stdc++.h>
using namespace std;

vector<string>getGrayCode(int n) {
    if(n == 1) return {"0", "1"};
    
    vector<string>currGrayCodes;
    
    vector<string>grayCode_n_minus_1 = getGrayCode(n-1);
    
    for(int i = 0; i < (int)grayCode_n_minus_1.size(); i++) {
        currGrayCodes.push_back("0" + grayCode_n_minus_1[i]);
    }
    for(int i = (int)grayCode_n_minus_1.size() - 1; i >= 0; i--) {
        currGrayCodes.push_back("1" + grayCode_n_minus_1[i]);
    }

    return currGrayCodes;
}

int main() {
    int n; 
    cin >> n;
    vector<string>grayCodes = getGrayCode(n);
    for(auto grayCode: grayCodes) {
        cout << grayCode << "\n";
    }
}