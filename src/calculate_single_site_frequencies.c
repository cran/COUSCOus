#include <stdio.h>
#include <ctype.h>

void calculate_single_site_frequencies( double* pa, double* alnnum,
                                       double* alnnum_row, double* alnnum_col,
                                       double* pseudocount, double* weight,
                                       double* wtsum )
{
    int i, a, k, n, p, pseudoc;
    n = (int) alnnum_row[0];
    p = (int) alnnum_col[0];
    pseudoc = (int) pseudocount[0];
    
    for( i = 0; i < p; i++ )
    {
        for( a = 0; a < 21; a++ )
        {
            pa[ i * 21 + a ] = pseudoc;
        }
        for( k = 0; k < n; k++ )
        {
            a = alnnum[ k * p + i ];
//            printf("a=%d\n",a);
            if( a < 21 )
            {
                pa[ i * 21 + a ] += weight[ k ];
            }
        }
        for( a = 0; a < 21; a++ )
        {
            pa[ i * 21 + a ] /= pseudoc * 21.0 + wtsum[0];
        }
    }
}
