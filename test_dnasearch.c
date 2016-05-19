/* dnasearch_test.c, 600.120 Spring 2015
 * JHED: amehndi1
 * Name: Anuj Mehndiratta
 * Date: February 22, 2016
 */

#include  "dnasearch.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int main(void){
    char test1[] = "";
    char test2[] = "Anuj Mehndiratta, intentionally not a dna sequence";
    char test3[] = {'A', 'G', 'D', 'T', '\0'};
    char test4[] = "TCACG";
    char test5[15001] = {'\0'};
    char test6[15001] = {'\0'};
    test6[0] = 'A'; 
    test6[1] = 'T'; 
    test6[2] = 'C'; 
    test6[3] = 'G';
    char test7[] = "atcg";
    char test8[] = "A";
    char test9[] = {'A', 'C', ' '};
    char test10[] = {'A', '\n', 'C'};
   
    assert(isValidFile(test1)==1);
    assert(isValidFile(test2)==1);
    assert(isValidFile(test3)==1);
    assert(isValidFile(test4)==0);
    assert(isValidFile(test5)==1);
    assert(isValidFile(test6)==0);
    assert(isValidFile(test7)==1);
    assert(isValidFile(test8)==0);
    assert(isValidFile(test9)==0);
    assert(isValidFile(test10)==0);
    


    char test11[] = "AAAAAAAAA";
    char test12[] = "AATCG";
    char test13[] = "AATCG";
    char test14[] = "CATCATCCCCA";
    char test15[] = "AAAAAATAC";
    int index[15000];
    char segment1[] = "CTC";
    char segment2[] = "AA";
    char segment3[] = "ATA";
    char segment4[] = "CAT";
    char segment5[] = "TAC";

    assert(getdnasegments(test11,segment1,index)==1);
    getdnasegments(test12, segment2, index);
    assert(index[0] == 0);
    getdnasegments(test13, segment3, index);
    assert(index[0] == -1);
    getdnasegments(test14, segment4, index);
    assert(index[0] == 0 && index[1] == 3);
    getdnasegments(test15, segment5, index);
    assert(index[0] == 6);    


    printf("All tests passed!\n");
return 0;
}
