#include <stdio.h>
#include <ctype.h>

void form_covarience_matrix( double* S, double* pab,
                            double* pa, double* aln_col )
{
    int i, j, a, b, p, index;
    p = (int) aln_col[0];
    
    for( i=0; i<p; i++ )
    {
        for( j=0; j<p; j++ )
        {
            for( a=0; a<21; a++ )
            {
                for( b=0; b<21; b++ )
                {
                    if( i != j || a == b )
                    {
                        index = i * p * 21 * 21 + j * 21 * 21 + a * 21 + b;
                        S[ ( i * 21 + a ) * ( p * 21 ) + j * 21 + b ] = pab[ index ] - pa[ i * 21 + a ] * pa[ j * 21 + b ];
                    }
                }
            }
        }
    }
}
