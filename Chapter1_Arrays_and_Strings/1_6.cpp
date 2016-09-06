#include <iostream>
#include <memory.h>

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
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }

	cout << endl;

    rotate(*matrix, 5);

    for(int i = 0; i != N; i ++){
        for(int j = 0; j != N; j ++){
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    
    return 0;
}

void rotate(int* matrix, int n){
    int temp = 0;
    int last_x = 0;
    int last_y = 0;
	int temp_position = 0;

	int endpoint = (n % 2 == 0)?(n/2):(n/2 + 1);

	bool visit[N*N];

	memset(visit, false, sizeof(visit));

    for(int x = 0; x != endpoint; x ++){
        for(int y = 0; y != endpoint; y ++){
			if(visit[y * n + x]){
				break;
			}
            temp = matrix[y * n + x];
            last_x = x;
            last_y = y;

			visit[y * n + x] = true;
            
            for(int i = 0; i != 3; i ++){
                matrix[last_y * n + last_x] = matrix[last_x * n + n - last_y - 1];
				temp_position = last_y;
                last_y = last_x;
				last_x = n - temp_position - 1;
				visit[last_y * n + last_x] = true;
            }
            
            matrix[last_y * n + last_x] = temp; 
        }
    }
}
