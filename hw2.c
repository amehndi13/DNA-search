/* hw2a.c, 600.120 Spring 2015
 * JHED: amehndi1
 * Name: Anuj Mehndiratta
 * Date: February 22, 2016
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dnasearch.h"


int main (int argc, char* argv[]) {
    //makes sure that a file was entered when compiling
    if (argc < 2) {
        puts("Please enter a file as a command line argument");
        return 1;
    }
    //reads file in and adds all of the input from the file into the dna array
    FILE* inFile = fopen(argv[1],"r");
    char dnastring[15002] = {'\0'};
    char aminoacid;
    int p = 0;
    while ((aminoacid = fgetc(inFile))!= EOF) {
        if (aminoacid !='\n' && !isspace(aminoacid)) {
            dnastring[p]=aminoacid;
            p++;
        }
    }
    //counts number of actual amino acids in the dna file
    int i = 0;
    int numaminoacids = 0;
    while (dnastring[i] != '\0') {
        numaminoacids++;
        i++;
    }
    //makes all of the amino acids from the file upper case.
    for (int i = 0; i < numaminoacids; i++) {
        int y = 0;
        dnastring[y] = toupper(dnastring[y]);
    }
    //Checks if file is valid or not
    isValidFile(dnastring);

    fclose(inFile);
    //ends the file reading portion of main

    //Reading in the segments that the user is looking for 
    printf("Enter the DNA segments that you would like to search for: ");
    char userinputs[15001] = {'\0'};
    int position[15000] = {'\0'};
    fgets(userinputs, 15000, stdin);
    int j = 0;
    char amino[15000] = {'\0'};
    for (int i = 0; i < 15001; i++){
        if (userinputs[0]==' ') { 
            i++;
        } else if (isspace(userinputs[i])){
            amino[j]= '\0';
            //gets the locations of the segments
            getdnasegments(dnastring, amino, position);
            j = 0;
            //sets the size of memory appropriately
            memset(&amino,'\0',sizeof(amino));
        } else {
            amino[j] = toupper(userinputs[i]);
            j++;
        }
    }
    return 0;
}
