#include <bits/stdc++.h>

using namespace std;

int synowie[10000009];

struct DP {
    int wielkosc;
    vector <int> drzewo;
    
    DP (int N) {
        wielkosc = 1;
        while (wielkosc < N) {
            wielkosc = wielkosc * 2;
        }
        
        drzewo.resize(wielkosc * 2);
        
        for (int i=wielkosc; i<2*wielkosc; i++) {
            synowie[i] = 1;
        }
        
        for (int i=wielkosc-1; i>0; i--) {
            synowie[i] = synowie[i * 2] + synowie[i * 2 + 1];
        }
    }
    
    int suma () {
        return drzewo[1];
    }
        
    void maluj (int a, int b, char c) {
        zamien(a, b, 1, 0, wielkosc - 1, c);
    }
    
    void zamien (int a, int b, int w, int l, int p, char c) {
        if (a <= l && b >= p) {
            if (c == 'C') {
                drzewo[w] = 0;
            }
            if (c == 'B') {
                drzewo[w] = synowie[w];
            }
            w = w / 2;
            while (w > 0) {
                drzewo[w] = drzewo[w * 2 + 1] + drzewo[w * 2];
                w = w / 2;
            }
            return;
        }
        if (drzewo[w] == synowie[w]) {
            drzewo[2 * w] = synowie[2 * w];
            drzewo[2 * w + 1] = synowie[2 * w + 1];
        }
        if (drzewo[w] == 0) {
            drzewo[2 * w] = 0;
            drzewo[2 * w + 1] = 0;
        }        
        int s = (l + p) / 2;
        if (a <= s) zamien (a, b, w * 2, l, s, c);
        if (b > s) zamien(a, b, w * 2 + 1, s + 1, p, c);
        return;
    }
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    int m, n, a, b;
    char c;
    cin >> n >> m;
    DP drzewo(n);
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        drzewo.maluj(a, b, c);
        cout << drzewo.suma() << '\n';
    }
}
