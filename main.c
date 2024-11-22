/* This program uses a type of matrix and does the following:
 * Creates the matrix and gets input to fill it out,
 * Prints the matrix in a nice way,
 * Gets as input two indexes and checks if the first is an ancestor of the second,
 * Keeps doing this check until input ends.
 * @name Koren Levy
 * @id 216968727
 */

#include <stdio.h>
#include "header.h" /* Including the other files in the program */

void printMatrix(adjmat matrix); /* Function declaration */

int main(void)
{
    int i,j; /* Will be used for loops. */
    int node1, node2, result; /* Will be used for input and returned value from path. */
    adjmat matrix; /* A variable of an adjmat type. */

    /* Two loops used for getting input for the matrix. */
    for(i = 0; i < N; i++)
    {
        printf("Please enter the values 0 or 1 for the %d node's line of the matrix \n", i);
        for(j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]); /* Input for the 'i' line, 'j' column. */
        }
    }

    printMatrix(matrix); /* Printing the matrix using a function. */

    /* Getting two indexes and checking if the first is an ancestor of the second. */
    printf("Please enter two indexes of nodes \n");
    scanf("%d %d", &node1, &node2);
    result = path(matrix, node1, node2);
    printf("The indexes are: %d,%d and the result is: %d \n", node1, node2, result);

    /* Keep doing it until input ends. */
    while(TRUE)
    {
        /* Input ends when entered -1 and -1, or we reach EOF. */
        printf("Please enter two indexes of nodes, input will end when entered -1, -1 or EOF \n");
        if(scanf("%d %d", &node1, &node2) != 2 || (node1 == -1 && node2 == -1))
            break;
        result = path(matrix, node1, node2);
        printf("The indexes are: %d,%d and the result is: %d \n", node1, node2, result);
    }

    return 0;
}

void printMatrix(adjmat matrix)
{
    /* First we print a '|' as the side of the matrix in each line,
     then we print the variable in each position with a '|' between each one. */
    int i,j;
    for(i = 0; i < N; i++)
    {
        printf("|");
        for(j = 0; j < N; j++)
        {
            printf("%d|", matrix[i][j]);
        }
        printf("\n");
    }
}