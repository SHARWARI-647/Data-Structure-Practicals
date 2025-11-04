/*Write a C program (name it "filecopy. c")  that copies the contents of one file to a destination file. 
This program will read data from one file and copy them to another.
The first input that the program will need is the names of the two files: input file ("input.txt") and output file ("output.txt"). 
Once the two file names have been obtained, the program must open the input file and create and open the output file.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    char ch;
    
    // Get input and output file names
    printf("Enter source file name (e.g., input.txt): ");
    scanf("%s", sourceName);

    printf("Enter destination file name (e.g., output.txt): ");
    scanf("%s", destName);

    // Open source file in read mode
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file %s\n", sourceName);
        exit(1);
    }

    // Open destination file in write mode
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Cannot create destination file %s\n", destName);
        fclose(sourceFile);
        exit(1);
    }

    // Copy contents character by character
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully from %s to %s\n", sourceName, destName);

    // Close both files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
