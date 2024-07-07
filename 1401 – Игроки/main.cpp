#include <iostream>

using namespace std;

class Gamers {
private:
	int N;
	int size;
	int** matrix;

	//функция добавления фигурки
	void add(int i, int j) {
		int tmp_i = i % 2;
		int tmp_j = j % 2;

		if (tmp_i == 1 && tmp_j == 1) {
			matrix[i - 1][j - 1] = matrix[i - 1][j] = matrix[i][j - 1] = N++;

		}
		else if (tmp_i == 0 && tmp_j == 0) {
			matrix[i + 1][j + 1] = matrix[i + 1][j] = matrix[i][j + 1] = N++;

		}
		else if (tmp_i == 0 && tmp_j == 1) {
			matrix[i + 1][j] = matrix[i][j - 1] = matrix[i + 1][j - 1] = N++;

		}
		else if (tmp_i == 1 && tmp_j == 0) {
			matrix[i - 1][j] = matrix[i][j + 1] = matrix[i - 1][j + 1] = N++;

		}
	}

	void main_solve(int row, int column, int i, int j, int size) {
		if (size == 2) {
			add(row + i % 2, column + j % 2);
			return;
		}

		int new_size = size / 2;

		if (i >= new_size && j >= new_size) {
			main_solve(row + new_size, column + new_size, i - new_size, j - new_size, new_size);

			matrix[row + new_size - 1][column + new_size - 1] =
				matrix[row + new_size][column + new_size - 1] =
				matrix[row + new_size - 1][column + new_size] = N++;

			main_solve(row, column + new_size, new_size - 1, 0, new_size);
			main_solve(row, column, new_size - 1, new_size - 1, new_size);
			main_solve(row + new_size, column, 0, new_size - 1, new_size);

		}
		else if (i < new_size && j < new_size) {
			main_solve(row, column, i, j, new_size);

			matrix[row + new_size][column + new_size] =
				matrix[row + new_size][column + new_size - 1] =
				matrix[row + new_size - 1][column + new_size] = N++;

			main_solve(row + new_size, column + new_size, 0, 0, new_size);
			main_solve(row, column + new_size, new_size - 1, 0, new_size);
			main_solve(row + new_size, column, 0, new_size - 1, new_size);

		}
		else if (i < new_size && j >= new_size) {
			main_solve(row, column + new_size, i, j - new_size, new_size);

			matrix[row + new_size][column + new_size] =
				matrix[row + new_size][column + new_size - 1] =
				matrix[row + new_size - 1][column + new_size - 1] = N++;

			main_solve(row, column, new_size - 1, new_size - 1, new_size);
			main_solve(row + new_size, column + new_size, 0, 0, new_size);
			main_solve(row + new_size, column, 0, new_size - 1, new_size);

		}
		else {
			main_solve(row + new_size, column, i - new_size, j, new_size);

			matrix[row + new_size][column + new_size] =
				matrix[row + new_size - 1][column + new_size] =
				matrix[row + new_size - 1][column + new_size - 1] = N++;

			main_solve(row, column, new_size - 1, new_size - 1, new_size);
			main_solve(row + new_size, column + new_size, 0, 0, new_size);
			main_solve(row, column + new_size, new_size - 1, 0, new_size);
		}
	}

public:
	Gamers(int** matrix, int size) {
		this->matrix = matrix;
		this->size = size;
		N = 1;
	}

	void solve(int i, int j) {
		main_solve(0, 0, i, j, size);
	}
};

int main() {
	int cages = 0, i = 0, j = 0;

	cin >> cages >> i >> j;

	int count = 1 << cages;
	int** matrix = new int* [count];

	for (int i = 0; i < count; i++) {
		matrix[i] = new int[count];
		for (int j = 0; j < count; j++)
			matrix[i][j] = 0;
	}

	Gamers gamers(matrix, count);

	gamers.solve(i - 1, j - 1);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	return 0;
    }



