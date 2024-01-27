#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n; cin >> n;
    vector<string> categorii;
    vector<vector<int>> produse;

    for(int i = 0; i < n; i++){
        int pret; string nume;
        cin >> nume >> pret;

        bool found = false;
        for(int i = 0; i < categorii.size(); i++){
            if(categorii[i] == nume){
                produse[i].push_back(pret);
                found = true;
            }
        }
        if(!found){
            categorii.push_back(nume);
            produse.push_back(vector<int>());
            produse[produse.size() - 1].push_back(pret);
        }
    }

    for(int i = 0; i < categorii.size(); i++){
        for(int j = 0; j < categorii.size() - i - 1; j++){
            if(categorii[j] > categorii[j + 1]){
                swap(categorii[j], categorii[j + 1]);
                swap(produse[j], produse[j + 1]);
            }
        }
    }

    for(int i = 0; i < categorii.size(); i++){
        sort(produse[i].begin(), produse[i].end());
        reverse(produse[i].begin(), produse[i].end());
    }

    for(int i = 0; i < categorii.size(); i++){
        cout << categorii[i] << " ";
        for(int j = 0; j < produse[i].size(); j++){
            cout << produse[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
