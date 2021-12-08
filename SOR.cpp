#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; 
    cin >> n;
    if (n == 1) cout << 1;
    else {
        int tab[n];
        long long L[n][n], R[n][n];
        long long modulo = 1000000000;
        for (int i=0; i<n; i++) {
            cin >> tab[i];
            L[i][i] = 1;
            R[i][i] = 1;
        }
        for (int i=0; i<n-1; i++) {
            if (tab[i] < tab[i+1]) {
                L[i][i+1] = 1;
                R[i][i+1] = 1;
            }    
            else {
                L[i][i+1] = 0;
                R[i][i+1] = 0;
            }
        }
        
        for (int i=n-3; i>=0; i--) {
            for (int j=i+2; j<=n-1; j++) {
                int a, b, c, d;
                if (i < j-1) {
                    if (tab[i] < tab[i+1]) a = 1; else a = 0;
                    if (tab[i] < tab[j]) b = 1; else b = 0;
                    if (tab[j] > tab[i]) c = 1; else c = 0;
                    if (tab[j] > tab[j-1]) d = 1; else d = 0;
                    L[i][j] = ((L[i+1][j] * a) % modulo + (R[i+1][j] * b) % modulo) % modulo;
                    R[i][j] = ((L[i][j-1] * c) % modulo + (R[i][j-1] * d) % modulo) % modulo;
                }
            }
        }
        
        cout << (L[0][n-1] + R[0][n-1]) % modulo;
    }
}

