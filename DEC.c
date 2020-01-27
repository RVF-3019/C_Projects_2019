/*
 ============================================================================
 Name        : DEC.c
 Author      : RVF
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// import -> include
// <>
// stdio.h (standard input output) -> not studio
// stdlib.h

#include <stdio.h>
#include <stdlib.h>
void revStr(char *str, int length, int a, int b){
char* result = (char*)malloc(sizeof(char)*length);
int i;
for( i = 0 ; i < length ; i++){
result[i] = str[length-i-1];
}
printf("The conversion of %d to base-%d is: ", a, b);
for(i = 0 ; i < length; i++){
printf("%c",result[i]);
}
// set the point of str -> str_rev
}
void dec2base(int input,int base,char *str){


int q = input;
int i = 0;
while(q > 0)
{
int r = q%base;
q = q/base;
//store r as a character
char rChar;
if(r < 10)
rChar = '0'+r;
else
rChar = 'A'+(r-10);
str[i] = rChar;
i++;
}
revStr(str,i, input, base);
}

int main(int argc, char *argv[])
{
int a;
sscanf(argv[1], "%d", &a);
if(a < 0 || a>2147483647){ // upper and down limit of the input
		printf( "Error : input  be in the range of [0,2147483647]\n");
		return -1;
	}
int b;
sscanf(argv[2], "%d", &b);
if(b < 2 || b>36){ // upper and down limit of the input
		printf( "Error : base be in the range of [2,36]\n");
		return -1;
	}
int q = a;
int length = 0;
while(q > 0)
{
q = q/b;
length++;
}
char* str = (char*)(malloc(sizeof(char)*length));
dec2base(a,b,str);
return 0;
}
