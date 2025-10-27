#include "matrix.hpp"
#include <gtest/gtest.h>

TEST(MatrixOps, ParallelEqualsSequential) {
    auto A = Matrix::random(200,200);
    auto B = Matrix::random(200,200);
    auto seq = A.multiplySequential(B);
    auto par = A.multiplyParallel(B, 4);

    for(size_t i=0; i<200; ++i)
        for(size_t j=0; j<200; ++j)
            ASSERT_NEAR(seq(i,j), par(i,j), 1e-6);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
