#include <iostream>

using namespace std;

void test() {
    int arr[3] = {1,2,3};
    int* arr_prt = begin(arr);
    
    for(int i = 0; i < 3; i++) {
        cout << *(arr_prt+i) << ' ';
    }
    cout << endl;

}

int main() {
    test();
    return 0;
}