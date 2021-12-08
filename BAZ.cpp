#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	int n;
    cin >> n;
    long long tab[n];    
    for (int i=0; i<n; i++) {
        cin >> tab[n-1-i];
    }
    long long pref[n];
    pref[0] = tab[0];
    for (int i=1; i<n; i++) {
        pref[i] = pref[i-1] + tab[i];
    }    
    long long nparzL[n], nparzP[n], parzL[n], parzP[n];
    if (tab[0] % 2 == 0) {
        nparzL[0] = -1;
        parzL[0] = tab[0];
    }
    if (tab[0] % 2 == 1) {
        nparzL[0] = tab[0];
        parzL[0] = -1;
    }
    if (tab[n-1] % 2 == 0) {
        nparzP[n-1] = -1;
        parzP[n-1] = tab[n-1];
    }
    if (tab[n-1] % 2 == 1) {
        nparzP[n-1] = tab[n-1];
        parzP[n-1] = -1;
    }
    for (int i=1; i<n; i++) {
        if (tab[i] % 2 == 1) {
            nparzL[i] = tab[i];
            parzL[i] = parzL[i-1];
        }
        if (tab[i] % 2 == 0) {
            nparzL[i] = nparzL[i-1];
            parzL[i] = tab[i];
        }
        
    }
    for (int i=n-2; i>=0; i--) {
        if (tab[i] % 2 == 1) {
            nparzP[i] = tab[i];
            parzP[i] = parzP[i+1];
        }
        if (tab[i] % 2 == 0) {
            nparzP[i] = nparzP[i+1];
            parzP[i] = tab[i];
        }
        
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        if (pref[x-1] % 2 == 1) cout << pref[x-1] << '\n';
        else {
            long long pom1=0, pom2=0;
            if (nparzL[x-1] == -1 || parzP[x] == -1) pom1 = -1;
            if (parzL[x-1] == -1 || nparzP[x] == -1) pom2 = -1;
            if ((pom1 == -1 && pom2 == -1) || x == n) cout << -1 << '\n';
            else if (pom1 == -1) cout << pref[x-1] - abs (parzL[x-1] - nparzP[x]) << '\n';
            else if (pom2 == -1) cout << pref[x-1] - abs (nparzL[x-1] - parzP[x]) << '\n';
            else {
                pom1 = abs (nparzL[x-1] - parzP[x]);
                pom2 = abs (parzL[x-1] - nparzP[x]);
                cout << pref[x-1] - min(pom1, pom2) << '\n'; 
            }
        }
    }
}
