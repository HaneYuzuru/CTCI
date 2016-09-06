#include <iostream>
#include <memory.h>

#define M 5
#define N 7

using namespace std;

void convert(int* matrix);

int main(){
	int matrix[M][N] = {{1, 2, 3, 4, 0, 5, 6},
						{7, 0, 8, 9, 10, 0, 11},
						{12, 13, 14, 15, 16, 17, 29},
						{18, 0, 19, 20, 21, 22, 28},
						{23, 0, 24, 25, 0, 26, 27}};

	for(int i = 0; i != M; i ++){
		for(int j = 0; j != N; j ++){
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}	

	cout << endl;

	convert(*matrix);

	for(int i = 0; i != M; i ++){
		for(int j = 0; j != N; j ++){
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}	

	return  0;
}

void convert(int* matrix){
	bool is_zero_x[N];
	bool is_zero_y[M];

	memset(is_zero_x, false, sizeof(is_zero_x));
	memset(is_zero_y, false, sizeof(is_zero_y));

	for(int i = 0; i != M; i ++){
		for(int j = 0; j != N; j ++){
			cout << matrix[i * M + j] << '\t';
			if(matrix[i * M + j] == 0){
				is_zero_x[j] = true;
				is_zero_y[i] = true;
			}
		}
		cout << endl;
	}

	for(int i = 0; i != N; i ++){
		if(is_zero_x[i] == true){
			cout << "x" << i << endl;
			for(int j = 0; j != M; j ++){
				matrix[j * M + i] = 0;
			}
		}
	}

	for(int i = 0; i != M; i ++){
		if(is_zero_y[i] == true){
			cout << "y" << i << endl;
			for(int j = 0; j != N; j ++){
				matrix[i * M + j] = 0;
			}
		}
	}
}
