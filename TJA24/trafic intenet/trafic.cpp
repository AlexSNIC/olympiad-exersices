#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int sum = 0;

    if(n <= 10){
        sum = 5 * n;
    }
    else if (n <= 20){
        sum = 50 + (n - 10) * 3;

    }
    else{
        sum = 80 + n - 20;
    }
    cout << sum << " lei";

    return 0;
}
