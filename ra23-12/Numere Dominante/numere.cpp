#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;



int main()
{
    ifstream fin("numere.in");
    ofstream fout("numere.out");

    int n, base;

    fin >> n >> base;
    int number = 1;
    while(n){
        number++;

        int i = 1;
        while(number % int(pow(base, i)) == 0){
          i++;
        };
        i--;

        if(i % 2 == 1){
          n--;
        }
    }

    fout << number;


    fin.close();
    fout.close();
}