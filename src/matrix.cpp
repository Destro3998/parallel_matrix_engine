#include "matrix.hpp"
#include <random>
#include <thread>
#include <cassert>

Matrix::Matrix(size_t r, size_t c): r_(r), c_(c), data_(r*c, 0.0) {}

Matrix Matrix::random(size_t r, size_t c, double min, double max) {
    Matrix M(r, c);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    for(size_t i = 0; i < r*c; ++i) M.data_[i] = dis(gen);
    return M;
}

double& Matrix::operator()(size_t i, size_t j){ return data_[i*c_ + j]; }
double Matrix::operator()(size_t i, size_t j) const { return data_[i*c_ + j]; }
size_t Matrix::rows() const { return r_; }
size_t Matrix::cols() const { return c_; }

// Sequential multiplication
Matrix Matrix::multiplySequential(const Matrix& B) const {
    assert(c_ == B.rows());
    Matrix C(r_, B.cols());
    for(size_t i=0; i<r_; ++i)
        for(size_t k=0; k<c_; ++k){
            double aik = (*this)(i,k);
            for(size_t j=0; j<B.cols(); ++j)
                C(i,j) += aik * B(k,j);
        }
    return C;
}

// Parallel multiplication using std::thread
Matrix Matrix::multiplyParallel(const Matrix& B, int numThreads) const {
    assert(c_ == B.rows());
    Matrix C(r_, B.cols());
    size_t rowsPerThread = r_ / numThreads;
    std::vector<std::thread> threads;

    for(int t=0; t<numThreads; ++t){
        size_t start = t * rowsPerThread;
        size_t end = (t == numThreads-1) ? r_ : start + rowsPerThread;
        threads.emplace_back([this, &C, &B, start, end](){
            for(size_t i = start; i < end; ++i)
                for(size_t k = 0; k < c_; ++k){
                    double aik = (*this)(i,k);
                    for(size_t j=0; j<B.cols(); ++j)
                        C(i,j) += aik * B(k,j);
                }
        });
    }

    for(auto &th : threads) th.join();
    return C;
}

// LU decomposition placeholder
void Matrix::LUDecompose() {
    // You can implement Doolittle or Crout algorithm later
}
