//
//  print.cpp
//  lab_06
//
//  Created by Mike Mikulin on 19.10.2023.
//

#include "commonheader.hpp"

using namespace std;
void PrintTabl(I_print i_prn[], int k)
{
    const int m = 7;
    int wn[m] = { 18,20,25,16, 25,16,  11 };
    const char* title[m] = { "Function","Integral","IntSum_Trap","N_Trap", "IntSum_Rect","N_Rect",  "Eps" };
    int size[m];
    for (int i = 0; i < m; i++)
        size[i] = strlen(title[i]);
    cout << char('+') << setfill(char('-'));
    for (int j = 0; j < m - 1; j++)
        cout << setw(wn[j]) << char('+');
    cout << setw(wn[m - 1]) << char('+') << endl;
    cout << char('|');
    for (int j = 0; j < m; j++)
        cout << setw((wn[j] - size[j]) / 2) << setfill(' ') << ' ' << title[j]
        << setw((wn[j] - size[j]) / 2) << char('|');
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        cout << char('+') << fixed;
        for (int j = 0; j < m - 1; j++)
            cout << setfill(char('-')) << setw(wn[j]) << char('+');
        cout << setw(wn[m - 1]) << char('+') << setfill(' ') << endl;
 
        cout << char('|') << setw((wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
            << setw((wn[0] - strlen(i_prn[i].name)) / 2) << char('|');
        cout << setw(wn[1] - 1) << setprecision(6) << i_prn[i].i_toch << char('|')
            << setw(wn[2] - 1) << i_prn[i].i_sum_Trap << setprecision(6) << char('|')
            << setw(wn[3] - 1) << i_prn[i].n_Trap << char('|') << setw(wn[4] - 1) << i_prn[i].i_sum_Rect << char('|') << setw(wn[5] - 1) << i_prn[i].n_Rect << char('|')
            << setw(wn[6] - 1) << pow(10, i_prn[i].eps) << char('|') << endl;
    }
    cout << char('+') << setfill(char('-'));
    for (int j = 0; j < m - 1; j++)
        cout << setw(wn[j]) << char('+');
    cout << setw(wn[m - 1]) << char('+') << setfill(' ') << endl;
}
