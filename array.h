#ifndef _FILE_H_
#define _FILE_H_
#define Max_Size 10

/*-----------------------------------2D Array Section----------------------------------*/
void Int2D(int Arr[][Max_Size] , int Row , int Col);
void Print2D(int Arr[][Max_Size] , int Row , int Col);
void MultMatBy(int Arr[][Max_Size] ,int Sum[][Max_Size],int Mult ,int R1 ,int C1); //taken 1_1Op
int  MainDiagSum(int Arr[][Max_Size] ,int R ,int C);                               //taken 2_1Op
void SumofEachRow(int Arr[][Max_Size] ,int R ,int C);                              //taken 3_1Op
void InterChangeDiag(int Arr[][Max_Size] ,int R ,int C);                           //taken 4_1Op
int  CheckUpperorLower(int Arr[][Max_Size] ,int R ,int C);                         //taken 5_1Op
void TransposeMat(int Arr[][Max_Size] ,int Trans[][Max_Size] ,int R ,int C);       //taken 6_1Op
int  CheckSparse(int Arr[][Max_Size ],int R ,int C);                               //taken 7_1Op
int  CheckSymmetric(int Arr[][Max_Size] ,int R ,int C);                            //taken 8_1OP
void AddTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size]  ,int Sum[][Max_Size] ,int R1 ,int C1);                    //taken 1_2Op
void SubtractTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size]  ,int Sum[][Max_Size] ,int R1 ,int C1);               //taken 2_2Op
void MultTwoMat(int Arr1[][Max_Size] ,int Arr2[][Max_Size] ,int Result[][Max_Size] ,int R1 ,int C1 ,int R2 ,int C2); //taken 3_2Op
int  CheckEquality(int Arr1[][Max_Size] ,int Arr2[][Max_Size] ,int R1 ,int C1);                                      //taken 4_2Op

#endif 
