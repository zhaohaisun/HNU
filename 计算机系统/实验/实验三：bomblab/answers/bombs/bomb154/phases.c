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
int bomb_id = 154;

/* 
 * phase1b.c - The user's input must match the specified string 
 */
void phase_1(char *input)
{
#if defined(PROBLEM)
    if (strings_not_equal(input, "I turned the moon into something I call a Death Star.") != 0)
	explode_bomb();
#elif defined(SOLUTION)
    printf("I turned the moon into something I call a Death Star.\n");
#else
    invalid_phase("1b");
#endif
}

/* 
 * phase2b.c - To defeat this stage the user must enter the geometric
 * sequence starting at 1, with a factor of 2 between each number
 */
void phase_2(char *input)
{
#if defined(PROBLEM)
    int i;
    int numbers[6];
    
    read_six_numbers(input, numbers);
    
    if (numbers[0] != 1)
	explode_bomb();

    for(i = 1; i < 6; i++) {
	if (numbers[i] != numbers[i-1] * 2)
	    explode_bomb();
    }
#elif defined(SOLUTION)
    printf("1 2 4 8 16 32\n");
#else
    invalid_phase("2b");
#endif
}
/* 
 * phase3a.c - A long switch statement that the compiler should implement
 * with a jump table. The user has to enter both an index into the table 
 * and a value stored there.
 */
void phase_3(char *input)
{
#if defined(PROBLEM)
    int index, val, x = 0;
    int numScanned = 0;

    numScanned = sscanf(input, "%d %d", &index, &val);

    if (numScanned < 2)
	explode_bomb();

    switch(index) {
    case 0:
	x = 280;
	break;
    case 1:
	x = 278;
	break;
    case 2:
	x = 662;
	break;
    case 3:
	x = 139;
	break;
    case 4:
	x = 915;
	break;
    case 5:
	x = 578;
	break;
    case 6:
	x = 262;
	break;
    case 7:
	x = 776;
	break;
    default:
	explode_bomb();
    }

    if (x != val)
	explode_bomb();
#elif defined(SOLUTION)
    printf("4 915\n");
#else
    invalid_phase("3a");
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

    n = 6;
    result = func4(n, base);

    if (result != val) {
	explode_bomb();
    }
#elif defined(SOLUTION)
    printf("%d %d %s\n", func4(6, 3), 3, SECRET_PHRASE);
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
    if (strings_not_equal(theWord, "sabres") != 0)
	explode_bomb();
#elif defined(SOLUTION)
    if (!strcmp("sabres", "devils"))
	printf("25l4o7\n");
    else if (!strcmp("sabres", "flyers"))
	printf("9on567\n");
    else if (!strcmp("sabres", "flames"))
	printf("9o1057\n");
    else if (!strcmp("sabres", "bruins"))
	printf("m63487\n");
    else if (!strcmp("sabres", "sabres"))
	printf("71m657\n");
    else if (!strcmp("sabres", "oilers"))
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
 * phase6a.c - The user has to enter the node numbers (from 1 to 6) in 
 * the order that they will occur when the list is sorted in ascending
 * order.
 */
listNode node6 = {206, 6, NULL};
listNode node5 = {940, 5, &node6};
listNode node4 = {407, 4, &node5};
listNode node3 = {692, 3, &node4};
listNode node2 = {871, 2, &node3};
listNode node1 = {990, 1, &node2};

#if defined(SOLUTION)
/* Sort list in ascending order */
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

	while ((r != NULL) && (r->value < p->value)) {
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

    /* Now see if the list is sorted in ascending order*/
    p = start;
    for (i = 0; i < 5; i++) {
	if (p->value > p->next->value)
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
    invalid_phase("6a");
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
    if (path != 2)
	explode_bomb();
  
    printf("Wow! You've defused the secret stage!\n");

    phase_defused();
#elif defined(SOLUTION)
    int path = 2;
    treeNode *node = &n1;
    
    node = (path    & 0x1) ? node->right : node->left;
    node = (path>>1 & 0x1) ? node->right : node->left;
    node = (path>>2 & 0x1) ? node->right : node->left;
    printf("%d\n", node->value);
#else
    invalid_phase("7");
#endif
}


