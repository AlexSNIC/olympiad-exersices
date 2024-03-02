#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<bool>>& mat) {
    for (vector<bool> vec : mat) {
        for (bool val : vec) {
            cout << val << ' ';
        }
        cout << endl;
    }
}
int sum(vector<vector<bool>>& mat) {
    int sum{};
    for (vector<bool> vec : mat) {
        for (bool val : vec) {
            sum += val;
        }
    }
    return sum;
}

void addSquare(vector<vector<bool>>& mat, int xStart, int yStart, int xEnd, int yEnd) {
    int maxX = max(xStart, xEnd);
    int maxY = max(yStart, yEnd);
    if(maxY > mat.size()) mat.resize(maxY);
    if(maxX > mat.at(0).size()){
        for(vector<bool>& vec : mat){
            vec.resize(maxX);
        }
    }
    for (int i = yStart; i < yEnd; i++) {
        for (int j = xStart; j < xEnd; j++) {
            mat.at(i).at(j) = 1;
        }
    }
}

int main() {
    ifstream fin("drept.in");
    ofstream fout("drept.out");

    int n; fin >> n;
    vector<vector<bool>> mat;
    int xStart, yStart, xEnd, yEnd;
    while (fin >> xStart >> yStart >> xEnd >> yEnd) {
        addSquare(mat, xStart, yStart, xEnd, yEnd);
    }
    // print(mat);
    cout << sum(mat);



    fin.close();
    fout.close();
    return 0;
}