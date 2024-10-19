/*
 * CS:APP Binary Bomb (Autolab version)
 *
 * Copyright (c) 2004, R. Bryant and D. O'Hallaron, All rights reserved.
 * May not be used, modified, or copied without permission.
 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phases.h"
#include "support.h"

/* Global bomb ID */
int bomb_id = 198;

/* 
 * phase1c.c - The user's input must match the specified string 
 */
void phase_1(char *input)
{
#if defined(PROBLEM)
    if (strings_not_equal(input, "I turned the moon into something I call a Death Star.") != 0)
	explode_bomb();
#elif defined(SOLUTION)
    printf("I turned the moon into something I call a Death Star.\n");
#else
    invalid_phase("1c");
#endif
}
/* 
 * phase2c.c - To defeat this stage the user must enter the first six
 * fibonacci numbers (0, 1, 1, 2, 3, 5)
 */
void phase_2(char *input)
{
#if defined(PROBLEM)
    int i;
    int numbers[6];

    read_six_numbers(input, numbers);

    if (numbers[0] != 0 || numbers[1] != 1)
	explode_bomb();
    for (i = 2; i < 6; i++) {
	if (numbers[i] != numbers[i-2] + numbers[i-1]) 
	    explode_bomb();
    }

#elif defined(SOLUTION)
    printf("0 1 1 2 3 5\n");
#else
    invalid_phase("2c");
#endif
}

/* 
 * phase3c.c - A long switch statement that the compiler should implement
 * with a jump table. The user has to enter both an index into the table
 * and the character stored at that position in the table as well
 * as a number to be compared. 
 */
void phase_3(char *input) 
{
#if defined(PROBLEM)
    int index, num, numScanned = 0;
    char x, letter;
  
    numScanned = sscanf(input, "%d %c %d", &index, &letter, &num);
  
    if (numScanned < 3) {
	explode_bomb();
    }

    switch(index) {
    case 0:
	x = 'u';
	if(num != 911) {
	    explode_bomb();
	}
	break;
    case 1:
	x = 'h';
	if(num != 58) {
	    explode_bomb();
	}
	break;
    case 2:
	x = 'x';
	if(num != 972) {
	    explode_bomb();
	}
	break;
    case 3:
	x = 'r';
	if(num != 761) {
	    explode_bomb();
	}
	break;
    case 4:
	x = 'n';
	if(num != 150) {
	    explode_bomb();
	}
	break;
    case 5:
	x = 't';
	if(num != 709) {
	    explode_bomb();
	}
	break;
    case 6:
	x = 'l';
	if(num != 823) {
	    explode_bomb();
	}
	break;
    case 7:
	x = 'q';
	if(num != 293) {
	    explode_bomb();
	}
	break;
    default:
	x = 's'; /* keep gcc happy */
	explode_bomb();
    }
  
    if (x != letter) {
	explode_bomb();
    }
#elif defined(SOLUTION)
    printf("5 t 709\n");
#else
    invalid_phase("3c");
#endif
}

/* 
 * phase4c.c - A recursive function to sort out.  
 *
 *          0, if n=0
 * F(n,b) = b, if n=1, 
 *          b + F(n-1, b) + F(n-2, b), if n>1
 * 
 * For a randomly chosen n, student must enter matching F(n, b) and b.
 */

int func4(int n, int base) {
    if (n <= 0) {
	return 0;
    }
    if (n == 1) {
	return base;
    }
    return base + func4(n-1, base) + func4(n-2, base);
}

void phase_4(char *input) {
#if defined(PROBLEM)
    int n, base, val, result, numScanned;

    numScanned = sscanf(input, "%d %d", &val, &base);
    if ((numScanned != 2) || (base < 2) || (base > 4)) {
	explode_bomb();
    }

    n = 9;
    result = func4(n, base);

    if (result != val) {
	explode_bomb();
    }
#elif defined(SOLUTION)
    printf("%d %d %s\n", func4(9, 2), 2, SECRET_PHRASE);
#else
    invalid_phase("4c");
#endif
}

/*
 * phase5b.c - This stage requires the user to enter a string of
 * six characters, where each character in the string is used as an offset
 * into the character array.  The six characters indexed by the
 * offsets must spell out a particular word.
 */
void phase_5(char *input)
{
#if defined(PROBLEM)
    static char array[] = {
	'm',
	'a',
	'd',
	'u',
	'i',
	'e',
	'r',
	's',
	'n',
	'f',
	'o',
	't',
	'v',
	'b',
	'y',
	'l'
    };

    int i, length;
    char theWord[7];

    length = string_length(input);
    if (length != 6)
	explode_bomb();
    
    for (i = 0; i < 6; i++)
	theWord[i] = array[ (input[i] & 0x0f) ];
    theWord[6] = '\0';

    /* devils, flyers, flames, bruins, sabres, oilers */
    if (strings_not_equal(theWord, "bruins") != 0)
	explode_bomb();
#elif defined(SOLUTION)
    if (!strcmp("bruins", "devils"))
	printf("25l4o7\n");
    else if (!strcmp("bruins", "flyers"))
	printf("9on567\n");
    else if (!strcmp("bruins", "flames"))
	printf("9o1057\n");
    else if (!strcmp("bruins", "bruins"))
	printf("m63487\n");
    else if (!strcmp("bruins", "sabres"))
	printf("71m657\n");
    else if (!strcmp("bruins", "oilers"))
	printf("j4o567\n");
    else {
	printf("ERROR: bad short_word in phase 5b\n");
	exit(8);
    }
#else
invalid_phase("5b");
#endif
}

/* 
 * phase6b.c - The user has to enter the node numbers (from 1 to 6) in 
 * the order that they will occur when the list is sorted in descending order.
 */
listNode node6 = {551, 6, NULL};
listNode node5 = {765, 5, &node6};
listNode node4 = {781, 4, &node5};
listNode node3 = {976, 3, &node4};
listNode node2 = {627, 2, &node3};
listNode node1 = {213, 1, &node2};

#if defined(SOLUTION)
/* Sort list in descending order */
listNode *fun6(listNode *start)
{
    listNode *head = start;
    listNode *p, *q, *r;

    head = start;
    p = start->next;
    head->next = NULL;

    while (p != NULL) {
	r = head;
	q = head;

	while ((r != NULL) && (r->value > p->value)) {
	    q = r;
	    r = r->next;
	}

	if (q != r)
	    q->next = p;
	else
	    head = p;

	q = p->next;
	p->next = r;

	p = q;
    }

    return head;
}
#endif

void phase_6(char *input)
{
#if defined(PROBLEM)
    listNode *start = &node1;
    listNode *p;
    int indices[6];
    listNode *pointers[6];
    int i, j;

    read_six_numbers(input, indices);

    /* Check the range of the indices and whether or not any repeat */
    for (i = 0; i < 6; i++) {
	if ((indices[i] < 1) || (indices[i] > 6))
	    explode_bomb();
	
	for (j = i + 1; j < 6; j++) {
	    if (indices[i] == indices[j])
		explode_bomb();
	}
    }

    /* Rearrange the list according to the user input */
    for (i = 0; i < 6; i++) {
	p = start;
	for (j = 1; j < indices[i]; j++)
	    p = p -> next;
	pointers[i] = p;
    }

    start = pointers[0];
    p = start;

    for (i = 1; i < 6; i++) {
	p->next = pointers[i];
	p = p->next;
    }
    p->next = NULL;

    /* Now see if the list is sorted in descending order */
    p = start;
    for (i = 0; i < 5; i++) {
	if (p->value < p->next->value)
	    explode_bomb();
	
	p = p->next;
    }
#elif defined(SOLUTION)
    listNode *start = &node1;
    listNode *p;

    /* sort */
    start = fun6(start);

    /* emit the node indices of the sorted list */
    p = start;
    while (p) {
	printf("%d ", p->index);
	p = p->next;
    }
    printf("\n");
#else
    invalid_phase("6b");
#endif
}



/* 
 * phase7.c - The infamous secret stage! 
 * The user has to find leaf value given path in a binary tree.
 */

typedef struct treeNodeStruct
{
    int value;
    struct treeNodeStruct *left, *right;
} treeNode;

/* balanced binary tree containing randomly chosen values */
treeNode n48 = {1001, NULL, NULL};
treeNode n46 = {47, NULL, NULL};
treeNode n43 = {20, NULL, NULL};
treeNode n42 = {7, NULL, NULL};
treeNode n44 = {35, NULL, NULL};
treeNode n47 = {99, NULL, NULL};
treeNode n41 = {1, NULL, NULL};
treeNode n45 = {40, NULL, NULL};
treeNode n34 = {107, &n47, &n48};
treeNode n31 = {6, &n41, &n42};
treeNode n33 = {45, &n45, &n46};
treeNode n32 = {22, &n43, &n44};
treeNode n22 = {50, &n33, &n34};
treeNode n21 = {8, &n31, &n32};
treeNode n1 = {36, &n21, &n22};

/* 
 * Searches for a node in a binary tree and returns path value.
 * 0 bit denotes left branch, 1 bit denotes right branch
 * Example: the path to leaf value "35" is left, then right,
 * then right, and thus the path value is 110(base 2) = 6.
 */

int fun7(treeNode* node, int val)
{
    if (node == NULL) 
	return -1;
  
    if (val < node->value) 
	return fun7(node->left, val) << 1;
    else if (val == node->value) 
	return 0;
    else 
	return (fun7(node->right, val) << 1) + 1;
}
     
void secret_phase()
{

#if defined(PROBLEM)
    char *input = read_line();
    int target = atoi(input);
    int path;

    /* Make sure target is in the right range */
    if ((target < 1) || (target > 1001))
	explode_bomb();

    /* Determine the path to the given target */
    path = fun7(&n1, target);

    /* Compare the retrieved path to a random path */
    if (path != 0)
	explode_bomb();
  
    printf("Wow! You've defused the secret stage!\n");

    phase_defused();
#elif defined(SOLUTION)
    int path = 0;
    treeNode *node = &n1;
    
    node = (path    & 0x1) ? node->right : node->left;
    node = (path>>1 & 0x1) ? node->right : node->left;
    node = (path>>2 & 0x1) ? node->right : node->left;
    printf("%d\n", node->value);
#else
    invalid_phase("7");
#endif
}


