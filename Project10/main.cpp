#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    virtual double getElement(int row, int col) const = 0; 
    virtual ~Matrix() {}
};

class IntMatrix : public Matrix {
private:
    vector<vector<int>> data; 

public:
    IntMatrix(int rows, int cols) {
        data.resize(rows, vector<int>(cols, 0)); 
    }

    void setElement(int row, int col, int value) {
        if (row < 0 || row >= data.size() || col < 0 || col >= data[0].size()) {
            throw out_of_range("������: ������ ������� �� ������� �������.");
        }
        data[row][col] = value; 
    }

    double getElement(int row, int col) const override {
        if (row < 0 || row >= data.size() || col < 0 || col >= data[0].size()) {
            throw out_of_range("������: ������ ������� �� ������� �������.");
        }
        return data[row][col]; 
    }
};

class FloatMatrix : public Matrix {
private:
    vector<vector<float>> data; 

public:
    FloatMatrix(int rows, int cols) {
        data.resize(rows, vector<float>(cols, 0.0f)); 
    }

    void setElement(int row, int col, float value) {
        if (row < 0 || row >= data.size() || col < 0 || col >= data[0].size()) {
            throw out_of_range("������: ������ ������� �� ������� �������.");
        }
        data[row][col] = value; 
    }

    double getElement(int row, int col) const override {
        if (row < 0 || row >= data.size() || col < 0 || col >= data[0].size()) {
            throw out_of_range("������: ������ ������� �� ������� �������.");
        }
        return data[row][col]; 
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    int rows, cols;
    cout << "������� ���������� ����� � �������� �������: ";
    cin >> rows >> cols;

    IntMatrix intMatrix(rows, cols);
    FloatMatrix floatMatrix(rows, cols);

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            cout << "������� �������� ��� intMatrix[" << i << "][" << j << "]: ";
            cin >> value;
            intMatrix.setElement(i, j, value);
        }
    }

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            float value;
            cout << "������� �������� ��� floatMatrix[" << i << "][" << j << "]: ";
            cin >> value;
            floatMatrix.setElement(i, j, value);
        }
    }

  
    try {
        cout << "������� intMatrix[0][0]: " << intMatrix.getElement(0, 0) << endl;
        cout << "������� floatMatrix[0][0]: " << floatMatrix.getElement(0, 0) << endl;

      
        cout << "������� ������� � �������� intMatrix[5][5]: " << intMatrix.getElement(5, 5) << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}