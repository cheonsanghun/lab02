#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;

    cout << "첫 번째 행렬의 행 수: ";
    cin >> rows;
    cout << "첫 번째 행렬의 열 수: ";
    cin >> cols;

    vector<vector<int>> matrix1(rows, vector<int>(cols));
    cout << "첫 번째 행렬의 원소를 입력하세요:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "두 번째 행렬의 행 수: ";
    cin >> rows;
    cout << "두 번째 행렬의 열 수: ";
    cin >> cols;

    vector<vector<int>> matrix2(rows, vector<int>(cols));
    cout << "두 번째 행렬의 원소를 입력하세요:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix2[i][j];
        }
    }

    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "두 행렬을 더한 결과:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

