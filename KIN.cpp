#include <bits/stdc++.h>

using namespace std;

long long modulo = 1000000000;

struct drzewko {
    int wielkosc = 1;
    vector <int> drzewo;
    
    drzewko (int n) {
        wielkosc = 1;
        while (wielkosc < n) {
            wielkosc = wielkosc * 2;
        }
        wielkosc = wielkosc * 2;        
        drzewo.resize(wielkosc * 2);
    }
    
    void wstaw (int w, long long a) {
        w = w + wielkosc;
        drzewo[w] = a % modulo;
        w = w / 2;
        while (w > 0) {
            drzewo[w] = (drzewo[2 * w] + drzewo[2 * w + 1]) % modulo;
            w = w / 2;
        }   
    }
    
    long long suma (int a) {
        a = a + wielkosc; 
        int b = wielkosc * 2 - 1;
        long long s = drzewo[a] % modulo;
        if (a != b) s = (s + drzewo[b]) % modulo;
        while (a/2 != b/2) {
            if (a % 2 == 0) s = (s + drzewo[a + 1]) % modulo;
            if (b % 2 == 1) s = (s + drzewo[b - 1]) % modulo;
            a = a / 2;
            b = b / 2;
        }
        return s;
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k, a;
    cin >> n >> k;
        
    vector <drzewko> T;
    
    for (int i=0; i<k; i++) {
        T.emplace_back(n);
    }
    
    for (int i=0; i<n; i++) {
        cin >> a;
        T[0].wstaw(a, 1);
        for (int j=1; j<k; j++) {
            T[j].wstaw(a, T[j-1].suma(a + 1)); 
        }
    }
    
    cout << T[k-1].suma(0);
}

