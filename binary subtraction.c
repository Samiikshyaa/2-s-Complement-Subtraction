#include<stdio.h>
#include<conio.h>
#include<math.h>
void decimalToBinary(int op1, int aOp[], int isSubtrahend)
{
	int result, i = 0;
	do
	{
		result = op1 % 2;
		op1 /=2;
		aOp[i] = result;
		i++;
	}while (op1 > 0);
	if(isSubtrahend) twoComplement(aOp);
}

int binaryTodecimal(int array[])
{
	int sum = 0, i;
	for(i =0; i < 7; i++)
	{
		if(array[i]) sum = sum + pow(2,i);
	}
	if(array[7]) sum = sum - pow(2,7);
	return sum;
}

void showBinary(int array[], int n)
{
	int i;
	for(i = n-1; i >= 0; i--)
	{
		printf("%d", array[i]);
	}
	printf("\n");
}

int addBinary(int a1[], int a2[], int result[])
{
	int i, c = 0;
	for(i = 0; i < 8; i++)
	{
		result[i] = ((a1[i] ^ a2[i]) ^ c);
		c = ((a1[i] & a2[i]) | (a1[i] & c)) | (a2[i] &c);
	}
	result[i] = c;
	return c;
}

void twoComplement(int array[])
{
    int i;
    int one[8] ={0,0,0,0,0,0,0,0};
    decimalToBinary(1, one, 0);
    int result[8] = {0,0,0,0,0,0,0,0};
    for(i=0; i < 8; i++)
    {
        if(array[i]) array[i] = 0;
        else array[i] = 1;
    }
    addBinary(array, one, result);
    for(i=0; i < 8; i++)
    {
        array[i] = result[i];
    }
}

int main()
{
	int op1, op2, diff;
	int aOp1[8] = {0,0,0,0,0,0,0,0};
	int aOp2[8] = {0,0,0,0,0,0,0,0};
	int aDiff[8] = {0,0,0,0,0,0,0,0};
	printf("Samikshya(HCE076BCT034)\n\n");
	printf("******BINARY SUBTRACTION******");
	printf("\nEnter Minuend: ");
	scanf("%d",&op1);
	while(op1<0 || op1>127)
	{
		printf("Enter Minuend: ");
		scanf("%d", &op1);
	}
    printf("\nEnter Subtrahend: ");
	scanf("%d",&op2);
	while(op2<0 || op2>127)
	{
		printf("Enter Subtrahend: ");
		scanf("%d", &op2);
	}
    decimalToBinary(op1, aOp1, 0);
	decimalToBinary(op2, aOp2, 1);

    printf("\nBinary Equivalent of %d is  ",op1);
    showBinary(aOp1, 8);
    printf("\n2's Complement Equivalent of %d is ",op2);
    showBinary(aOp2, 8);
    addBinary(aOp1, aOp2, aDiff);
	printf("\nDifference in Binary: ");
    showBinary(aDiff, 8);
    diff = binaryTodecimal(aDiff);
    printf("\nDifference in Decimal: %d", diff);
return 0;
}
