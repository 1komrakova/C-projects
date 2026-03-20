#include <stdio.h>

int main(){
	char str[81];
	fgets(str, 81, stdin);
	int i = 0;
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] == 'a'){
			str[i] = 'A';
		}
		else if(str[i] == 'b'){
			str[i] = 'B';
		}
	}
	printf("%s", str);
	return 0;
}
