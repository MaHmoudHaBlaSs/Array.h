#include <stdio.h>
#include <conio.h>
#include "array.h"

#define Max_Size 10

int Result_Arr[Max_Size][Max_Size],A[Max_Size][Max_Size], B[Max_Size][Max_Size];
int R1 , C1 , R2 , C2 ,Result_Num,Operation,Num;
short Sentinel = 1 ,Op = 0 ;

int main()
{


    while(Sentinel != 27)
    {
        printf("Enter The Type of Operation 1 for 1-Operand Opperation & 2 for 2-Operand Operation :\n");
        scanf("%hd" , &Op);
        // for operations that requires only One operand.
        if(Op == 1)
        {
            //Initialization of The Matrix
            printf("Enter Number of Rows : ");
            scanf("%d" , &R1);
            printf("Enter Number of Columnes : ");
            scanf("%d" , &C1);
            printf("Initialize The Matrix : \n");
            Int2D(A,R1,C1);
            Print2D(A,R1,C1);
            //Selecting Operation
            printf("Select Operation :\n1-Multiply Matrix By Number [Scalar Multiplication].\n");
            printf("2-Get Summation of The Main Diagonal.\n3-Get Sum Of Each Row.\n4-Interchange The Diagonals.\n");
            printf("5-Check Lower ,Upper Or Diagonal Matrix.\n6-Transpose Matrix\n7-Check Sparse.\n");
            printf("8-Check Symmetric\n");
            scanf("%d" ,&Operation);

            switch (Operation)
            {
                case 1 : //Scalar Multiplication.
                    printf("Enter The Multiplied Number : ");
                    scanf("%d" ,&Num);
                    MultMatBy(A,Result_Arr,Num,R1,C1);
                    Print2D(Result_Arr,R1,C1);
                break;
                case 2 : //Main Diagonal Summation
                    Result_Num = MainDiagSum(A,R1,C1);
                    printf("Main Diagonal Sum = %d\n", Result_Num);
                break;
                case 3 : // Sum of Each Row.
                    SumofEachRow(A,R1,C1);
                break;
                case 4 : // Interchange The Diagonals.
                    if(R1==C1)
                    {
                        InterChangeDiag(A,R1,C1);
                        Print2D(A,R1,C1);
                    }
                    else
                    {
                        printf("Invalid Dimensions Passed !\n");
                    }
                break;
                case 5 : // Check Upper , Lower Or Maing Diagonal Matrix. 
                    Result_Num = CheckUpperorLower(A,R1,C1);
                    if(Result_Num == -1)
                    {
                        printf("Lower Matrix Entered.\n");
                    }
                    else if(Result_Num == 1)
                    {
                        printf("Upper Matrix Entered.\n");
                    }
                    else if(Result_Num == 2)
                    {
                        printf("Diagonal Matrix Entered.\n");
                    }
                    else
                    {
                        printf("Non-Characteristic Matrix Entered.\n");
                    }
                break;
                case 6 : // Transpose The Matrix.
                    TransposeMat(A,Result_Arr,R1,C1);
                    Print2D(Result_Arr,R1,C1);
                break;
                case 7 : // Check For Sparse Matrix [Sparse Matrix Has Zero as Most of Its Elements]
                    Result_Num = CheckSparse(A,R1,C1);
                    if(Result_Num == 1)
                    {
                        printf("Sparse Matrix Entered.\n");
                    }
                    else
                    {
                        printf("Non-Sparse Matrix Entered.\n");
                    }
                break;
                case 8 : // Check Symmetric Matrix or Not
                    Result_Num = CheckSymmetric(A,R1,C1);;
                    if(Result_Num == 1)
                    {
                        printf("Symmetric Matrix Entered.\n");
                    }
                    else
                    {
                        printf("Non-Symmetric Matrix Entered.\n");
                    }
                break;
            }
        }
        // for operations that requires Two operands.
        else if(Op == 2)
        {
            // Initialization of the first Matrix
            printf("Enter Number of Rows For The First Matrix : ");
            scanf("%d" , &R1);
            printf("Enter Number of Columns For The First Matrix : ");
            scanf("%d" , &C1);
            printf("Initialize The First Matrix : \n");
            Int2D(A,R1,C1);
            Print2D(A,R1,C1);
            //Initialization of the second Matrix
            printf("Enter Number of Rows For The Second Matrix : ");
            scanf("%d" , &R2);
            printf("Enter Number of Columns For The Second Matrix : ");
            scanf("%d" , &C2);
            printf("Initialize The Second Matrix : \n");
            Int2D(B,R2,C2);
            Print2D(B,R2,C2);
            //Selecting Operation
            printf("Select Operation :\n1-Add The Two Matrices.\n2-Subtract The Two Matrices.\n");
            printf("3-Multiply The Two Matrices.\n4-Check Equality of The Two  Matrices\n");
            scanf("%d" ,&Operation);
            switch (Operation)
            {
                case 1 :
                    if(R1 == C1)
                    {
                        AddTwoMat(A,B,Result_Arr,R1,C1);
                        Print2D(Result_Arr,R1,C1);
                    }
                    else
                    {
                        printf("Invalid Dimensions Passed !\n");
                    }
                break;
                case 2 :
                    if(R1 == C1)
                    {
                        SubtractTwoMat(A,B,Result_Arr,R1,C1);
                        Print2D(Result_Arr,R1,C1);
                    }
                    else
                    {
                        printf("Invalid Dimensions Passed !\n");
                    }
                break;
                case 3 :
                    MultTwoMat(A,B,Result_Arr,R1,C1,R2,C2);
                    Print2D(Result_Arr,R1,C2);
                break;
                case 4 :
                    if((R1 != R2) || (C1 != C2))
                    {
                        printf("Invalid Dimensionsn Passed !\n");
                    }
                    else
                    {
                        Result_Num = CheckEquality(A,B,R1,C1);
                        if(Result_Num == 1)
                        {
                            printf("Identical Matrices.\n");
                        }
                        else
                        {
                            printf("Non-Identical Matrices.\n");
                        }
                    }
                break;
            }
        }
        else
        {
            printf("Out Of Range OPeration !\n");
        }
        printf("Press Esc to Exit , Else to Continue ... \n");
        Sentinel = getch();
    }
    
    return 0;
}
