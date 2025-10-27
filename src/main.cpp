#include "matrix.hpp"
#include <iostream>
#include <chrono>

int main(int argc, char** argv){
    int threads = 4;
    if(argc > 1) threads = atoi(argv[1]);
    size_t N = 1000;

    Matrix A = Matrix::random(N,N);
    Matrix B = Matrix::random(N,N);

    auto start = std::chrono::high_resolution_clock::now();
    Matrix C = A.multiplyParallel(B, threads);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> dt = end - start;
    std::cout << "Matrix size: " << N << "x" << N
              << " | Threads: " << threads
              << " | Time: " << dt.count() << " s\n";
    return 0;
}
