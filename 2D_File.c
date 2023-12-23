#include <stdio.h>
#include "array.h"
#define Max_Size 10

// All the following functions deal only with int (data type) passed aray 

void Int2D(int Arr[][Max_Size], int Row, int Col);
void Print2D(int Arr[][Max_Size], int Row, int Col);
void MultMatBy(int Arr[][Max_Size], int Sum[][Max_Size], int Mult, int R1, int C1); //taken 1_1Op
int  MainDiagSum(int Arr[][Max_Size] ,int R ,int C);                               //taken 2_1Op
void SumofEachRow(int Arr[][Max_Size] ,int R ,int C);                              //taken 3_1Op
void InterChangeDiag(int Arr[][Max_Size] ,int R ,int C);                           //taken 4_1Op
int  CheckUpperorLower(int Arr[][Max_Size] ,int R ,int C);                         //taken 5_1Op
void TransposeMat(int Arr[][Max_Size] ,int Trans[][Max_Size] ,int R ,int C);       //taken 6_1Op
int  CheckSparse(int Arr[][Max_Size ],int R ,int C);                               //taken 7_1Op
int  CheckSymmetric(int Arr[][Max_Size] ,int R ,int C);                            //taken 8_1Op
void AddTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size]  ,int Sum[][Max_Size] ,int R1 ,int C1);                    //taken 1_2Op
void SubtractTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size]  ,int Sum[][Max_Size] ,int R1 ,int C1);               //taken 2_2Op
void MultTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size] ,int Result[][Max_Size] ,int R1 ,int C1 ,int R2 ,int C2); //taken 3_2Op
int  CheckEquality(int Arr1[][Max_Size] ,int Arr2[][Max_Size] ,int R1 ,int C1);                                      //taken 4_2Op




// Initialize 2D Array [Matrix].
void Int2D(int Arr[][Max_Size] , int Row , int Col)
{
    for(unsigned short i = 0 ; i < Row ; i++)
    {
        for(unsigned short j = 0 ; j < Col ; j++)
        {
            scanf("%d" , &Arr[i][j]);
        }
    }
}
// Print 2D Array [Matrix].
void Print2D(int Arr[][Max_Size] , int Row , int Col)
{
    for(unsigned short i = 0 ; i < Row ; i++)
    {
        for(unsigned short j = 0 ; j < Col ; j++)
        {
            printf("%+d " , Arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// Parameters : Arr1 -> First Array , Arr2 -> Second Array , Result -> The Result of Multiplication (Used As Indirect Return Value)
// R1 -> First Matrix Rows , C1 -> First Matrix Columns
void MultTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size] ,int Result[][Max_Size] ,int R1 ,int C1 ,int R2 ,int C2)
{
    // R1xC1 * R2xC2
    if(C1 == R2)
    {
        for(unsigned short i = 0 ; i < R1 ; i++) // R1 ->Rows of the first array
        {
            for(unsigned short j = 0 ; j < C2 ; j++) // C2 ->Columns of the second array
            {
                for(unsigned short k = 0 ; k < R2 ; k++) // R2 -> Rows of the second array
                {
                    Result[i][j] += Arr1[i][k] * Arr2[k][j];
                          //Arr1[0][0] * Arr2[0][0] + Arr1[0][1] * Arr2[1][0] + Arr1[0][2] * Arr2[2][0]
                }
            }
        }
    }
    else
    {
        printf("Dimensions Don't Match Up For The Multiplication ! \n");
    }

}
// Add two matrices and return the resulted matrix.
void AddTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size]  ,int Sum[][Max_Size] ,int R1 ,int C1)
{
    for(unsigned short i = 0 ; i < R1 ; i++)
    {
        for(unsigned j = 0 ; j < C1 ; j++)
        {
            Sum[i][j] = Arr1[i][j] + Arr2[i][j];
        }
    }
}
// Subtracts two matrices and return the resulted matrix.
void SubtractTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size]  ,int Sum[][Max_Size] ,int R1 ,int C1)
{
    for(unsigned short i = 0 ; i < R1 ; i++)
    {
        for(unsigned j = 0 ; j < C1 ; j++)
        {
            Sum[i][j] = Arr1[i][j] - Arr2[i][j];
        }
    }
}
// Function to Multiply the Array by number [Scaler Multiplication] and returns the resulted matrix.
void MultMatBy(int Arr[][Max_Size] ,int Sum[][Max_Size],int Mult ,int R ,int C)
{
    for(unsigned short i = 0 ; i < R ; i++)
    {
        for(unsigned j = 0 ; j < C ; j++)
        {
            Sum[i][j] = Mult * Arr[i][j];
        }
    }
}
// Calculates sum of the main diagonal elements and returns it.
int MainDiagSum(int Arr[][Max_Size] ,int R ,int C)
{
    if(R==C)
    {
        int Sum = 0 ;
        for(unsigned short i = 0 ; i < R ; i++)
        {
            for(unsigned j = 0 ; j < C ; j++)
            {
                if(i == j)
                {
                
                    Sum += Arr[i][j];   
                }
                else{}
            }
        }
        return (Sum);
    }
    else
    {
        printf("Invalid Dimensions Passed !\n");
        return 0;
    }
}
//Calculates sum of each row in the matrix and prints it
void SumofEachRow(int Arr[][Max_Size] ,int R ,int C)
{
    int Sum = 0;
    for(unsigned int i = 0 ; i < R ; i++)
    {
        for(unsigned int j = 0 ; j < C ; j++)
        {
            Sum += Arr[i][j];
        }
        printf("Sum Of Row %d = %d \n",i,Sum);
        Sum = 0;
    }
}
// Interchange diagonals of the matrix.
void InterChangeDiag(int Arr[][Max_Size] ,int R ,int C)
{
    if(R == C)
    {
        int Temp = 0;
        for(unsigned short i = 0 ; i < R ; i++)
        {
            for(unsigned short j = 0 ; j < C ; j++)
            {
                if( i == j)
                {
                    Temp = 0;
                    Temp = Arr[i][j];
                    Arr[i][j] = Arr[i][C-i-1];
                    Arr[i][C-i-1] = Temp;
                }

            }
        }
    }
    else{}
}
// Check whether the matrix is Lower , Upper Or Diagonal Matrix.
int  CheckUpperorLower(int Arr[][Max_Size] ,int R ,int C)
{
    int Lower = 1 , Upper = 1; // 1 for Upper , -1 for Lower , 0 for both
    for(unsigned int i = 0 ; i < R ; i++)
    {
        for(unsigned int j = 0 ; j < C ; j++)
        {
            if((i > j) && Arr[i][j] != 0)
            {
                Lower = 0;
                break;
            }
        }
        if(Lower == 0)break;
    }
    for(unsigned int i = 0 ; i < R ; i++)
    {
        for(unsigned int j = 0 ; j < C ; j++)
        {
            if((j > i) && Arr[i][j] != 0)
            {
                Upper = 0;
                break;
            }
        }
        if(Upper == 0)break;
    }
    if(Lower && Upper)
    {
        return 2; //0 for Diagonal Matrix
    }
    else if (Lower)
    {
        return -1; //-1 for Lower
    }
    else if(Upper)
    {
        return 1; //1 for Upper
    }
    else
    {
        return 0;
    }
}
// Get the transpose of Matrix.
void TransposeMat(int Arr[][Max_Size] ,int Trans[][Max_Size] ,int R ,int C)
{
    for(unsigned int i = 0 ; i < R ; i++)
    {
        for(unsigned int j = 0 ; j < C ; j++)
        {
            Trans[i][j] = Arr[j][i];
        }
    }
}
// Check Sparse [Sparse Matrix has zero as most of its elements (n*m)/2]
int CheckSparse(int Arr[][Max_Size ],int R ,int C)
{
    unsigned int Counter = 0 ;
    for(unsigned int i = 0 ; i < R ; i++)
    {
        for(unsigned int j = 0 ; j < C ; j++)
        {
            if(Arr[i][j] == 0)
            {
                Counter++;
            }
        }
    }
    if(Counter >= ((R*C) / 2))
    {
        return 1; // 1 for sparse
    }
    else
    {
        return 0; // 0 for non-sparse
    }
}
// Check Symmetry of matrix (Upper Main Diagonal equal to the Lower Main Diagonal) 
int  CheckSymmetric(int Arr[][Max_Size] ,int R ,int C)
{
    int Symmetric = 1;
    if(R == C)
    {
        for(unsigned int i = 0 ; i < R ; i++)
        {
            for(unsigned int j = 0 ; j < C ; j++)
            {
                if((Arr[i][j] != Arr[j][i]) && (i != j))
                {
                    Symmetric = 0;
                    break;
                }
            }
        }
        return Symmetric;
    }
    else
    {
        printf("Invalid Dimensions Passed !\n");
        return 0;
    }

}
//Check Matrices are equal or not.
int  CheckEquality(int Arr1[][Max_Size] ,int Arr2[][Max_Size] ,int R1 ,int C1)
{
    if(R1 == C1)
    {
        int Equality = 1; 
        for(unsigned int i = 0 ; i < R1 ; i++)
        {
            for(unsigned int j = 0 ; j < C1 ; j++)
            {
                if(Arr1[i][j] != Arr2[i][j])
                {
                    Equality = 0;
                    break;
                }
            }
            if(Equality == 0)break;
        }
        return Equality;
    }
    else
    {
        return 0;
    }
}
