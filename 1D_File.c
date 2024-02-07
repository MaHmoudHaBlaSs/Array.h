#include <stdio.h>
#include "array.h"
//We will deal with arrays from int datatype
/*-----------------------------------1D Array-----------------------------------*/

void Int1D(int *Arr ,const int Len); // Initialize Array
void Print1D(int *Arr ,const int Len); // Printt Array
int  Sum1D(int *Arr ,const int Len); // Array's Elements Summation
void MaxandMin(int *Arr ,const int Len ,int *Max ,int *Min); // Find Max and Min
void EvenandOdd(int *Arr ,const int Len ,int *Even ,int *Odd); // Find Even and Odd Iterations
void CpyArr(int *Arr1 , int *Arr2 ,int Len); // Copy Array to another
void InsElem(int *Arr ,int Len ,int Elem ,int Pos); // Insert Elements into the Array
void DelElem(int *Arr ,int Len ,int Pos); // Delete an Element through its position
void CountFreq(int *Arr ,int Len ,int *Freq); // Count Frequency of each element


void Int1D(int *Arr ,const int Len)
{
    for(short i = 0 ; i < Len ; i++)
    {
        scanf("%d" , &Arr[i]);
    }
}
void Print1D(int *Arr ,const int Len)
{
    for(short i = 0 ; i < Len ; i++)
    {
        printf("%d " , Arr[i]);
    }
    printf("\n");
}
int Sum1D(int *Arr ,const int Len)
{
    int Sum = 0;
    for(short i = 0 ; i < Len ; i++)
    {
       Sum += Arr[i]; // *(Arr + 1)
    }
    return Sum;
}
void MaxandMin(int *Arr ,const int Len ,int *Max ,int *Min)
{
    *Max = Arr[0];
    *Min = Arr[0];
    for(short i = 1 ; i < Len ; i++)
    {
        if(Arr[i] > *Max)
        {
            *Max = Arr[i];
        }
        else if (Arr[i] < *Min)
        {
            *Min = Arr[i];
        }
    }
}
void EvenandOdd(int *Arr ,const int Len ,int *Even ,int *Odd)
{
    *Even = 0;
    *Odd = 0;
    for(short i = 0 ; i < Len ; i++)
    {
        if(Arr[i] % 2)
        {
            (*Odd)++;
        }
        else
        {
            (*Even)++;
        }
    }
}
void CpyArr(int *Arr1 , int *Arr2 ,int Len)
{
    for(short i = 0 ; i < Len ; i++)
    {
        Arr2[i] = Arr1[i];
    }
}
void InsElem(int *Arr ,int Len ,int Elem ,int Pos)
{
    int Temp = 0;
    if((Pos < Len) && (Pos >= 0))
    {
        Temp = Arr[Pos];
        Arr[Pos] = Elem;
        for(short i = Pos+1 ; i < Len; i++)
        {
           Temp ^= Arr[i]; // XOR = is a technice used to swap two values without using Temp variable
           Arr[i] ^= Temp;
           Temp ^= Arr[i]; 
        }
    }

}
void DelElem(int *Arr ,int Len ,int Pos)
{
    if((Pos >= 0)&&(Pos < Len))
    {
        for(unsigned short i = Pos ; i < Len ; i++)
        {
            Arr[i] = Arr[i+1];
        }
    }
}
// 1 2 3 4 1 2 3 3 
void CountFreq(int *Arr ,int Len ,int *Freq)
{
    for(unsigned short i = 0 ; i < Len ; i++)
    {
        for(unsigned short j = 0 ; j < Len ; j++)
        {
            if(Arr[i] == Arr[j])
            {
                Freq[i]++;
                Arr[j] = '\0';
            }   
        }
    }
}