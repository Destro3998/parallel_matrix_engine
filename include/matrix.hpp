#pragma once
#include <vector>
#include <cstddef>

class Matrix {
public:
    Matrix(size_t rows, size_t cols);
    static Matrix random(size_t rows, size_t cols, double min=0.0, double max=1.0);

    double& operator()(size_t i, size_t j);
    double operator()(size_t i, size_t j) const;
    size_t rows() const;
    size_t cols() const;

    // Operations
    Matrix multiplySequential(const Matrix& B) const;
    Matrix multiplyParallel(const Matrix& B, int numThreads) const;
    void LUDecompose();

private:
    size_t r_, c_;
    std::vector<double> data_; // row major
};
