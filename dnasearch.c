/* dnasearch.c, 600.120 Spring 2015
 * JHED: amehndi1
 * Name: Anuj Mehndiratta
 * Date: February 22, 2016
 */
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dnasearch.h"

//Checks if the file entered fits all of the requirements
int isValidFile(char dnastring[]) {
    int i = 0;
    int counter = 0;
    while (dnastring[i] != '\0') {
        counter++;
        i++;
    }
    if (counter == 0) {
        printf("invalid input file -- the file is empty\n");
        return 1;
    }
    for (int i = 0; i < counter; i++) {
        if (dnastring[i] != 'A' && dnastring[i] != 'T' && dnastring[i] != 'C' && 
                    dnastring[i] != 'G' && dnastring[i] != ' ' && dnastring[i] != '\n') {
            printf("invalid input file -- there are non amino acids in the file\n");
            return 1;
        }
    }
    if (dnastring[15000] != '\0') {
        printf("invalid input file -- the file is too long\n");
        return 1;
    }
    return 0;
}

//gets the dna segments and their positions
int getdnasegments (char dnastring[], char segments[], int position[]) {
    
    //gets size of the segments array
    int i = 0;
    int counter = 0;
    while (segments[i] != '\0') {
        counter++;
        i++;
    }
    int lengthofsegment = counter;

    //gets size of the entire dnastring array
    i = 0;
    counter = 0;
    while (dnastring[i] != '\0') {
        counter++;
        i++;
    }
    int lengthofdna = counter;
    //used later in order to know when to stop going through the array
    //this way I can stop as soon as I see negative number
    for (int r = 0; r < 15000; r++) {
        position[r] = -1;
    }

    int match = 0;//this serves the same role as the boolean did in the algorithm given
    int index = 0;
    int k = 0;
    for (int j = 0; j <= lengthofdna - lengthofsegment; j++) {
        match = 0;
        k = j;
        for (int v = 0; v < lengthofsegment; v++) {
            if (segments[v]!= dnastring[k+v]) {
                match = 1;
                v=lengthofsegment;
            }
        }
        if (match == 0) { 
            position[index] = j;
            index++;
        }
    }
    printf ("%s ", segments);
    int is_1 = 0;
    
    for (unsigned int a = 0; a < 15000; a++) {
        if (position[a] >= 0) {
            is_1 = 1;
        }
    }
    if (is_1 == 0) {
        printf("Not found\n");
        return 1; 
    } else {
        for (unsigned int b = 0; b < 15000; b++) {
            if (position[b] >= 0) { 
                printf("%d ", position[b]);
            }
        }
    }
    puts(" ");
    return 0;
}


