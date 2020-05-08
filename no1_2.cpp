#include<iostream>
using namespace std;

void input(char *A) {
	for(int i = 0; i < 1000; i++) {
		char c;
		cin >> c;
		if(c == ' ' || c == '\n' || c == '\r')
			return;
		else 
			A[i] = c;
	}
}

int length(char *A){
	for(int i = 0; i < 1000; i++) {
		if(A[i] == '\0')//error
			return i + 1 ;
	}
}

char* upsideDown(char *A) {
	int l = length(A);
	char C[1000];
	while(i < l) {
		C[l--] = A[i++];
	}
	return C;
}



int main() {
	char A[], B[];
	input(A);
	input(B); 
	retrun 0;
} 
