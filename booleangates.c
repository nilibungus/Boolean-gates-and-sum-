/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int AND (int a, int b);
int OR (int a, int b);
int NOT (int a);
int XOR(int a, int b);
void HALFADDER(int a, int b, int *sum, int *carry);
void FULLADDER(int a, int b, int c_in, int *c_out, int*sum);
void SUM(int arr1[], int n1, int arr2[], int n2, int result[]);


int main(void){
   int truth_value1, truth_value2;
   //get the truth values for simple boolean operations
   printf("A: ");
   scanf("%d", &truth_value1);
   printf("B: ");
   scanf("%d", &truth_value2);
   //get the arrays to sum
   int n1, n2;
   printf("Enter the size of the first binary number array: ");
   scanf("%d", &n1);
   printf("Enter the size of the second binary number array: ");
   scanf("%d", &n2);
   int arr1[n1], arr2[n2];
   for (int i = 0; i < n1; i++){
      printf("Enter element %d for first array: ", i);
      scanf("%d", &arr1[i]);
   }
    for (int i = 0; i < n2; i++){
      printf("Enter element %d for second array: ", i);
      scanf("%d", &arr2[i]);
   }
   
   
   


  printf("A and B = %i\n", AND(truth_value1, truth_value2));
  printf("A or B = %i\n", OR(truth_value1, truth_value2));
  printf("not A = %i\n", NOT(truth_value1));
  printf("not B = %i\n", NOT(truth_value2));
  int max = (n1 > n2)?  n1:n2;
  int result[max + 1];
  SUM(arr1, n1, arr2, n2, result);
  
  
  for (int i = 0; i < max + 1; i++){
    printf("%d", result[i]);
  }

}

int AND (int a, int b){return a && b;}
int OR (int a, int b){return a||b;}
int NOT (int a){return !a;}
int XOR (int a, int b){return OR(AND (a, NOT (b)), AND (NOT (a), b));}
void HALFADDER(int a, int b, int *sum, int *carry){
    *sum = XOR (a, b);
    *carry = AND (a, b);}
void FULLADDER(int a, int b, int c_in, int *c_out, int*sum){
    *sum = XOR(XOR(a, b), c_in);
    *c_out = AND(a, b) + AND(c_in, XOR(a, b));}

void SUM(int arr1[], int n1, int arr2[], int n2, int result[]){
   //apply halfadder to the last indices of the arrays:
   int s, c;
   HALFADDER(arr1[n1 - 1], arr2[n2 - 1], &s, &c);
   result[(n1 > n2? n1: n2)] = s;
   int min; 
   if (n1 > n2) {
      min = n2;
   } else{ min = n1;
}
   for(int i = min -2; i >= 0; i--){
      int c_out;
      FULLADDER(arr1[i], arr2[i], c, &c_out, &s);
      result[i + 1] = s;
      c = c_out;
   }
   result[0] = c;
   
}

