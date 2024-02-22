#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printMat(vector<vector<char>> mat, ofstream& fout){
    for(vector<char> vec : mat){
        for(char value : vec){
            fout << value;
        }
        fout << endl;
    }
}

void alter(vector<vector<char>>& mat, int row, int col, int rows, int cols){
    if(row < 0 || row >= rows) return;
    if(col < 0 || col >= cols) return;
    if(mat.at(row).at(col) == '0') return;
    if(mat.at(row).at(col) == 'X') return;

    mat.at(row).at(col) = 'X';
    alter(mat, row + 1, col, rows, cols);
    alter(mat, row - 1, col, rows, cols);
    alter(mat, row, col + 1, rows, cols);
    alter(mat, row, col - 1, rows, cols);
}

void findPoint(vector<vector<char>>& mat, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(mat.at(i).at(j) == '2'){
                alter(mat, i, j, rows, cols);
            }
        }
    }
}


int main()
{
    ifstream fin("limonada.in");
    ofstream fout("limonada.out");

    int rows, cols;
    fin >> rows >> cols;
    vector<vector<char>> mat(rows, vector<char>(cols));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            char temp; fin >> temp;
            mat.at(i).at(j) = temp == 'X'? '2' : temp;
        }
    }


    findPoint(mat, rows, cols);
    printMat(mat, fout);


    fin.close();
    fout.close();
}