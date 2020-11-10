#include <iostream>

using namespace std;

void rule(int m) {

    int binary[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    cout << "Liczba binarna: ";
    for (int i = 7; i > 0; i--) {
        binary[i] = (m % 2);
        m /= 2;
    }
       
    for (int i = 0; i < 8; i++) cout << binary[i];
    cout << endl;

    int tab[9][9] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };
    int prev=0; 
    int next=0;
    
    for(int x = 1; x < 9; x++){
        for (int current = 0; current < 9; current++) {

            if (current == 0) {
                prev = tab[x-1][8];
            }
            else if (current == 8) {
                next = tab[x-1][0];
            }
            else {
                next = tab[x-1][current + 1];
                prev = tab[x-1][current - 1];
            }

            if (prev == 1) {
                if (tab[x-1][current] == 1) {
                    if (next == 1) {
                        tab[x][current] = binary[0];
                    }
                    else {
                        tab[x][current] = binary[1];
                    }
                }
                else {
                    if (next == 1) {
                        tab[x][current] = binary[2];
                    }
                    else {
                        tab[x][current] = binary[3];
                    }
                }
            }
            else {
                if (tab[x-1][current] == 1) {
                    if (next == 1) {
                        tab[x][current] = binary[4];
                    }
                    else {
                        tab[x][current] = binary[5];
                    }
                }
                else {
                    if (next == 1) {
                        tab[x][current] = binary[6];
                    }
                    else {
                        tab[x][current] = binary[7];
                    }
                }
            }
        }
    }

    cout << "Wynik po 8 iteracjach: " << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

int main()
{
    int method;
    do {
        cout << "Z ktorej metody chcesz skorzystac?" << endl
            << "1. Metoda 30" << endl
            << "2. Metoda 60" << endl
            << "3. Metoda 90" << endl
            << "4. Metoda 120" << endl
            << "5. Metoda 225" << endl
            << "6. Zakoncz." << endl
            << "Wybor: ";

        cin >> method;

        switch (method) {
        case 1:
            rule(30);
            break;
        case 2:
            rule(60);
            break;
        case 3:
            rule(90);
            break;
        case 4:
            rule(120);
            break;
        case 5:
            rule(225);
            break;
        case 6:
            cout << "Koncze dzialanie..." << endl;
            exit(0);
            break;
        default:
            cout << "Bledne polecenie." << endl;
            break;
        }
    } while (true);
}
