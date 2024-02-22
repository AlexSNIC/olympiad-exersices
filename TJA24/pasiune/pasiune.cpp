#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    int n;
    cin >> n;
    int count = 0;
    vector<int> nrs;

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        int temp = val;
        int j = 0;
        while(temp != 0){
            temp/= 10;
            j++;
        }

        int sum = 0;
        temp = val;
        for(int k = 0; k < j; k++){
            int nr = temp%10;
            temp/= 10;
            sum += pow(nr, j);
        }
        if(sum == val) {
            nrs.push_back(val);
            count++;
        }
    }
    cout << count << endl;
    for(int nr : nrs){
        cout << nr << " ";
    }



    return 0;
}
