
#include <iostream>
#include <vector>

using namespace std;

void escribe_sudoku(vector <vector <int> > &s) {
    cout << "--------------" << endl;
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------" << endl;
}

void elimina(vector <vector <int> > &s, vector <bool> &posibles, int i, int j) {
    for(int k = 0; k < 9; ++k) {
        posibles[s[i][k]] = false; posibles[s[k][j]] = false;
    }
    int iaux = (i/3) * 3;
    int jaux = (j/3) * 3;
    for(int k = 0; k < 3; ++k) {
        for(int l = 0; l < 3; ++l) {
            posibles[s[iaux+k][jaux+l]] = false;
        }
    }
}


void resuelve_s(vector < vector <int> > &s, int i, int j, bool &alguno) {
    if( i == 9 ) {
        i = 0;
        ++j;
    }
    if(j == 9) {
        alguno = true;
        escribe_sudoku(s);
        return;
    }
   
    if(s[i][j] == 0) {
        vector <bool> posibles(10, true);
        elimina(s, posibles, i, j);
        for(int k = 1; k < posibles.size(); ++k) {
            if(posibles[k]) {
                s[i][j] = k;
                resuelve_s(s, i+1, j, alguno);
            }
        }
        s[i][j] = 0;
    }
    else resuelve_s(s, i+1, j, alguno);
   
}

int main() {
   
//    vector < vector <int> > s(9,9);
    vector < vector <int> > s(9);
    for (int i = 0; i < 9; i++) s[i] = vector <int> (9);
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> s[i][j];
        }
    }
    bool alguno = false;
    resuelve_s(s, 0, 0, alguno);
    if(!alguno) cout << "SENSE SOLUCIO" << endl;
   
   
}






