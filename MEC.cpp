#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, a;
    cin >> n >> m;
    string tab[n+1];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> a;
            if (j < n/2) {
                tab[a] += 'A';
            }
            else {
                tab[a] += 'B';
            }
        }
    }
    sort(tab,  tab+(n+1));
    for (int i=0; i<n; i++) {
        if (tab[i] == tab[i+1]) {
            cout << "NIE";
            return 0;
        } 
    }
    cout << "TAK";
}

