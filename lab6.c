#include <stdio.h>
#include <string.h>

int main() {
	
    FILE *file1;
    FILE *file2;

    file1 = fopen("input.txt", "r");
    file2 = fopen("result.txt", "w");
	char word [256];
    while (fgets(word, 256, file1) != NULL){
        int i = 0, j = 0;
		char lastname[40];
        while (word[i] != ' ' && word[i] != '\0'){
            lastname[j] = word[i];
            i++;
            j++;
        }
        lastname[j] = '\0';
        i++;
        j = 0;
        char name[40];
        while (word[i] != ' ' && word[i] != '\0') {
            name[j] = word[i];
            i++;
            j++;
        }
        name[j] = '\0';
        i++;
        j = 0;
        char middlename[50];
        while (word[i] != ' ' && word[i] != '\0') {
            middlename[j] = word[i];
            i++;
            j++;
        }
        middlename[j] = '\0';
        i++;
        j = 0;
        char year[5];
        while (word[i] != '\0'){
            year[j] = word[i];
            i++;
            j++;
        }
        year[j] = '\0';
        int year_i = atoi(year);
        if (year_i > 1980){
            fprintf(file2, "%s %s %s %d\n", lastname, name, middlename, year_i);
        }
    }

    fclose(file1);
    fclose(file2);

    return 0;
}
