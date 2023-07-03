#include <iostream>
#include <vector>

using Line       = std::vector<int>;
using MatrixImpl = std::vector<Line>;

struct Matrix {
    MatrixImpl Mat;
    int        lines;
    int        columns;

    friend void operator<<(std::ostream &os, const Matrix &Matrix)
    {
        for (auto &line : Matrix.Mat) {
            for (auto &elem : line) {
                std::cout << elem << ' ';
            }
            std::cout << '\n';
        }
    }
};

void fillMatrix(Matrix &Matrix)
{
    int         lines = Matrix.lines, columns = Matrix.columns;
    MatrixImpl &Mat = Matrix.Mat;

    for (int i = 0; i < lines; ++i) {
        Line line;
        for (int j = 0; j < columns; ++j) {
            int temp = 0;
            std::cin >> temp;
            line.push_back(temp);
        }

        Mat.push_back(line);
    }
}

void add(Matrix &first, Matrix &second)
{
    int         lines = first.lines, columns = first.columns;
    MatrixImpl &Mat1 = first.Mat, Mat2 = second.Mat;

    for (int i = 0; i < lines; ++i) {
        Line &line1 = Mat1[i], line2 = Mat2[i];
        for (int j = 0; j < columns; ++j) {
            line1[j] += line2[j];
        }
    }
}

int main()
{
    int lines = 0, columns = 0;
    std::cin >> lines >> columns;

    Matrix first{{}, lines, columns}, second{{}, lines, columns};
    fillMatrix(first);
    fillMatrix(second);

    add(first, second);

    std::cout << first;

    return 0;
}
