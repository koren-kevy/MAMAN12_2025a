/* This function defines a matrix of a fixed size,
 * Checks if a node has a path to another node by.
 * We do it by getting the second node's father, if it's the first node we return true,
 * else we check who his is father if it's the first node we return true.
 * We do it until we reach the first node, or we got to the root.
 */

#define N 4 /* Used for the size of the matrix. */
#define TRUE 1 /* Used as a true value. */
#define FALSE 0 /* Used as a false value. */

typedef int adjmat[N][N]; /* defining a type for a matrix. */

int path(adjmat matrix, int u, int v)
{
    /* If the indexes are outside the matrix we return false.
    If the two indexes are equal we return true. */
    int i;
    if(u >= N || v >= N) { return FALSE; }
    if(u == v) { return TRUE; }

    /* If we found the right father we return true, else we call path with the father and look again. */
    for(i = 0; i < N; i++)
    {
        if(matrix[i][v] == 1)
        {
            if(i == u || path(matrix, u, i))
                return TRUE;
        }
    }
    return FALSE;
}