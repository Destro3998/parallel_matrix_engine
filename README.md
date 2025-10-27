# Parallel Matrix Engine 

My University class cmpt-214 project for building a high-performance C++ matrix multiplication engine that demonstrates parallel computing concepts using multi-threading.

## What This Project Does

Built a matrix multiplication engine that can perform operations both sequentially and in parallel. The parallel version uses a custom thread pool to distribute work across multiple CPU cores, significantly speeding up large matrix operations.


## Tech Stack

- **C++17** - Modern C++ features and standard library
- **CMake** - Cross-platform build system
- **Google Test** - Unit testing framework
- **Homebrew LLVM** - Compiler toolchain
- **Threading** - `std::thread`, `std::mutex`, `std::condition_variable`

## Results

```
Matrix size: 1000x1000 | Threads: 4 | Time: 0.0441896 s
```

- ✅ Scalable thread pool implementation
- ✅ Memory-efficient matrix storage

## Learnings

- **Parallel Programming**: How to break down matrix operations into parallel tasks
- **Thread Synchronization**: Using mutexes and condition variables for thread-safe operations
- **C++ Modern Features**: Lambda captures, move semantics, and RAII
- **Build Systems**: CMake configuration and dependency management
- **Performance Optimization**: Identifying bottlenecks and parallelizing compute-intensive operations

## Build & Run

```bash
mkdir build && cd build
cmake .. -DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm/bin/clang++
make -j$(sysctl -n hw.ncpu)
./matrix_engine
./test_matrix
```