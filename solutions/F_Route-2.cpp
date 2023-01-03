#include <iostream>


void make_step(int n, int (&matrix1)[100][100], int (&matrix2)[100][100], int (&input_matrix)[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix2[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int max_on_prev_step = matrix1[i][j];
            if (max_on_prev_step == 0) {
                continue;
            }
            if (i < n - 1) {
                matrix2[i + 1][j] = std::max(matrix2[i + 1][j], input_matrix[i + 1][j] + max_on_prev_step);
            }
            if (i > 0) {
                matrix2[i - 1][j] = std::max(matrix2[i - 1][j], input_matrix[i - 1][j] + max_on_prev_step);
            }
            if (j < n - 1) {
                matrix2[i][j + 1] = std::max(matrix2[i][j + 1], input_matrix[i][j + 1] + max_on_prev_step);
            }
            if (j > 0) {
                matrix2[i][j - 1] = std::max(matrix2[i][j - 1], input_matrix[i][j - 1] + max_on_prev_step);
            }
        }
    }
}

int matrix_max(int n, int matrix[100][100]) {
    int result = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = std::max(result, matrix[i][j]);
        }
    }

    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    int input_matrix[100][100];
    int matrix1[100][100];
    int matrix2[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> input_matrix[i][j];
            matrix1[i][j] = 0;
            matrix2[i][j] = 0;
        }
    }

    matrix1[0][0] = input_matrix[0][0];

    for (int i = 1; i < k; i += 1) {
        if (i % 2 == 1) {
            make_step(n, matrix1, matrix2, input_matrix);
        } else {
            make_step(n, matrix2, matrix1, input_matrix);
        }
    }

    if (k % 2 == 0) {
        std::cout << matrix_max(n, matrix2);
    } else {
        std::cout << matrix_max(n, matrix1);
    }

    return 0;
}
