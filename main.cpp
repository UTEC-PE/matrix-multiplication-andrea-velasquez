#include <iostream>
#include <vector>
#include <thread>

using namespace std;

/* Set sizes
	Matrix 	[row][column]
	Matrix 1	[M][N]
	Matrix 2	[N][P]
*/
#define M 5
#define N 3
#define P 3

void multiply_row_column(int row[N], int matrix2[N][P], int matrix_ans[M][P], int row_number){
	int ans;
	for (int i=0; i<N; ++i){
		ans = 0;
		for (int j=0; j<P; ++j){
			ans+= matrix2[j][i] * row[j];
		}
		matrix_ans[row_number][i] = ans;
	}
}

int main(int argc, char *argv[]){
	// Fill and create matrices
	int c=0;
	auto matrix1 = new int[M][N];
	for (int i=0; i<M; ++i) for (int j=0; j<N; ++j) matrix1[i][j]=++c;
	auto matrix2 = new int[N][P];
	for (int i=0; i<N; ++i) for (int j=0; j<P; ++j) matrix2[i][j]=++c;
	auto matrix_ans = new int[M][P] {};

	// Threads
	thread threads[M];
    for (int i=0; i<M; ++i) threads[i] = thread(multiply_row_column, matrix1[i],  matrix2, matrix_ans, i);
    for (int i = 0; i <M; ++i) threads[i].join();

    // Print
    cout << "\nMatrix 1: \n";
	for (int i=0; i<M; ++i){
		for (int j=0; j<N; ++j){
			cout << matrix1[i][j] << "\t";
		}
		cout <<endl;
	}

	cout << "\nMatrix 2: \n";
	for (int i=0; i<N; ++i){
		for (int j=0; j<P; ++j){
			cout << matrix2[i][j] << "\t";
		}
		cout <<endl;
	}

	cout << "\nMatrix ans: \n";
	for (int i=0; i<M; ++i){
		for (int j=0; j<P; ++j){
			cout << matrix_ans[i][j] << "\t";
		}
		cout <<endl;
	}

	// Clean
	delete[] matrix1;
	delete[] matrix2;
	delete[] matrix_ans;

	return EXIT_SUCCESS;
}