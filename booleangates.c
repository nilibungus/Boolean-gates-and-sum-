
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
  
  if (result[0] == 1){
  for (int i = 0; i < max + 1; i++){
    printf("%d", result[i]);
  }

} else {
    for (int i = 1; i < max + 1; i++){
    printf("%d", result[i]);
  }
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
   // get max and min lengths of the two input arrays
   
   int max; 
   if (n1 > n2) {
      max = n1;
   } else{ max = n2;
}
    int min; 
   if (n1 > n2) {
      min = n2;
   } else{ min = n1;
}

   // get the longer array 
   int bigarr[max];
   if (n1 > n2){
       for(int i = 0; i < n1; i++){
           bigarr[i] = arr1[i];
       }
   } else {
       for(int i = 0; i < n2; i++){
           bigarr[i] = arr2[i];
       }
   }
   // get the shorter array
   int smallarr[min];
   if (n1 > n2){
       for(int i = 0; i < n2; i++){
           smallarr[i] = arr2[i];
       }
   } else {
       for(int i = 0; i < n1; i++){
           smallarr[i] = arr1[i];
       }
   }
   // get an array with the length of the longer array which has zeros in the first positions and then the shorter array, i.e: if we have 111 and 11 get 011
   int arr3[max];
   for(int i = 0; i < max - min; i ++){
       arr3[i] = 0;
   }
   for(int i = (max - min) ; i < max; i ++){
       arr3[i] = smallarr[i - (max - min)];
   }
   
   //sum the "zeroed" array and the longest array 
   int c = 0;
   
  
   for(int i = max - 1; i >= 0; i--){
      int c_out;
      int s;
      FULLADDER(bigarr[i], arr3[i], c, &c_out, &s);
      result[i + 1] = s;
      c = c_out;
   }
   result[0] = c;
   
}

