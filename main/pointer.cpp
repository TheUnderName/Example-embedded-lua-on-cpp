#include <iostream>
#include <memory>
using namespace std;

int* make_array(int size) {
    int* arr = new int[size];
    for(int i=0; i < size; i++) {
        arr[i] = i + 1 * 2;
    }
    return arr;
}
int **make_array(int n,int m) {
    int** arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for(int j=0; j < m; j++) {
            arr[i][j] = i + j + 1;
        
        }
    } 
    return arr;
}
int main() {
    int n = 2; // ????
    int m = 2; // ??? ??
    
    int** arr = make_array(n,m);
    for(int i = 0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cout << arr[i][j] << endl;
        
        }
    } 


    return 0;
}
