#include <iostream>
using namespace std;
class Matrix {
private:
    int** arr;
    int rows;
    int columns;

public:
    // Default constructor
    Matrix() : rows(3), columns(3) {
        cout << "I am default constructor" << endl;
        arr = new int* [rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[columns];
            for (int j = 0; j < columns; j++) {
                arr[i][j] = 0;
            }
        }
    }

    // Overloaded constructor
    Matrix(int r, int c) : rows(r), columns(c) {
       cout << "I am overloaded constructor with rows = " << r << " and columns = " << c << endl;
        arr = new int* [rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[columns];
            for (int j = 0; j < columns; j++) {
                arr[i][j] = 0;
            }
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    // Overloaded input operator
    friend istream& operator>>(istream& in, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.columns; j++) {
                cout << "Enter element in row  " << i << "  and column  " << j << endl;
                in >> matrix.arr[i][j];
            }
        }
        return in;
    }

    // Overloaded output operator
    friend ostream& operator<<(ostream& out, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.columns; j++) {
                out << matrix.arr[i][j] << ' ';
            }
            out << endl;
        }
        return out;
    }

    // Unary operator to check if the matrix is an identity matrix
    bool operator!() const {
        if (rows != columns) {
            return false;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (i == j && arr[i][j] != 1) {
                    return false;
                }
                else if (i != j && arr[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Matrix A;
    Matrix B(4, 4);
    cin >> A;
    cout << A;

    if (!A) {
        cout << "It is an Identity matrix" << endl;
    }
    else {
        cout << "It is not an Identity matrix" <<endl;
    }

    return 0;
}
