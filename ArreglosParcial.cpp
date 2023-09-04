#include <iostream>
#include <conio.h>

using namespace std;

int digitos[] = {28,13,2,17,8,19,14,20,6,22,11,3,24,5,10,29,12,7,9,4,25,15,16,21,23,18,27,30,26,1};
int p, b, a;

int main(){
for (p=0; p<30; p++){
	for(b=0; b<30; b++){
		if(digitos[b]>digitos[b+1]){
		a = digitos[b];
		digitos[b] = digitos [b+1];
		digitos [b+1] = a;
		}
	}
}

cout<< "Orden Ascendiente: ";
for(p=1; p<31; p++){
	cout<< digitos[p] <<" ";
}


getch();
return 0;
}












