#include <iostream>

using namespace std;

#define N 5

void rotate(int* matrix, int n);

int main(){
    int matrix[5][5] = {{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}};

    for(int i = 0; i != N; i ++){
        for(int j = 0; j != N; j ++){
            cout << matrix[i][j] + '0' << '\t';
        }
        cout << endl;
    }

    rotate(*matrix, 5);

    for(int i = 0; i != N; i ++){
        for(int j = 0; j != N; j ++){
            cout << matrix[i][j] + '0' << '\t';
        }
        cout << endl;
    }
    
    return 0;
}

void rotate(int* matrix, int n){
    int temp = 0;
    int last_x = 0;
    int last_y = 0;

    for(int x = 0; x != n/2 + 1; x ++){
        for(int y = 0; y != n/2 + 1; y ++){
            temp = matrix[y * n + x];
            last_x = x;
            last_y = y;
            
            for(int i = 0; i != 3; i ++){
                matrix[last_y * n + last_x] = matrix[last_x * n + n - last_y - 1];
                last_x = n - last_y - 1;
                last_y = last_x;
            }
            
            matrix[last_y * n + last_x] = 
        }
    }
}
