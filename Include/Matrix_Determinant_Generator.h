/**
 * Jack Robbins
 * Class for a custom matrix determinant pseudorandom number generator
*/

#ifndef MATRIX_DETERMINANT_RNG_H_
#define MATRIX_DETERMINANT_RNG_H_

#include <time.h>
#include <random>


class Matrix_Determinant_RNG {
    private:
        int matrix[3][3];

    //Constructor
    public:
        Matrix_Determinant_RNG(){
            //seed the rng
            srand(time(NULL));
        }

        //just here to have
        ~Matrix_Determinant_RNG(){};

        int getNextNumber(){
            //rewrite the class's matrix every time
            for(int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    this->matrix[i][j] = rand();
                }
            }
            return std::abs(matrix_determinant());
        }


    private:
        int matrix_determinant(){
            //will take in a 3-by-3 matrix and find determinant
            //no need for fancy recursion here, use the formula for 3-by-3
            int subdet1, subdet2, subdet3;

            subdet1 = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2]*matrix[2][1]);
            subdet2 = matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2]*matrix[2][0]);
            subdet3 = matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1]*matrix[2][0]);
            
            return subdet1 + subdet2 + subdet3;
        }
};




#endif /* MATRIX_DETERMINANT_RNG_H_ */