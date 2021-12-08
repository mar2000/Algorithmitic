#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    string napis;
    cin >> napis;
    int n = napis.size();
    char pop = '(';
    int popWsp = -1, L = n + 1;
    for (int i=0; i<n; i++) {
        if (napis[i] != '*') {
            if (pop != '(' && napis[i] != pop) L = min(L, i - popWsp + 1);
            pop = napis[i];
            popWsp = i;  
        }
    }
    }
    cout << n + 2 - L;
}
