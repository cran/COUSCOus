#include <stdio.h>
#include <ctype.h>

void calculate_pair_site_frequencies( double* pab, double* pa,
                                       double* alnnum, double* alnnum_row,
                                       double* alnnum_col, double* pseudocount,
                                       double* weight, double* wtsum )
{
    int i, j, k, a, b, n, p, index, index_rev;
    double pseudoc;
    n = (int) alnnum_row[0];
    p = (int) alnnum_col[0];
    pseudoc = pseudocount[0];

    for( i = 0; i < p; i++ )
    {
        for( j = i + 1; j < p; j++ )
        {
            for( a = 0; a < 21; a++ )
            {
                for( b = 0; b < 21; b++ )
                {
                    /*index = b * 21 * p * p +
                            a * p * p +
                            j * p +
                            i;*/
                    index = i * p * 21 * 21 + j * 21 * 21 + a * 21 + b;
                    pab[index] = pseudoc / 21.0;
                }
            }
            
            for( k = 0; k < n; k++ )
            {
                a = alnnum[ k * p + i ];
                b = alnnum[ k * p + j ];
                if( a < 21 && b < 21 )
                {
                    index = b * 21 * p * p +
                            a * p * p +
                            j * p +
                            i;
                    index = i * p * 21 * 21 + j * 21 * 21 + a * 21 + b;
                    pab[index] += weight[k];
                }
            }
            
            for( a = 0; a < 21; a++ )
            {
                for( b = 0; b < 21; b++ )
                {
                    index = i * p * 21 * 21 + j * 21 * 21 + a * 21 + b;
                    pab[index] /= pseudoc * 21.0 + wtsum[0];

                    index_rev = j * p * 21 * 21 + i * 21 * 21 + b * 21 + a;
                    pab[index_rev] = pab[index];
                }
            }
        }
    }
    
    for( i = 0; i < p; i++ )
    {
        for( a = 0; a < 21; a++ )
        {
            for( b = 0; b < 21; b++ )
            {
                index = i * p * 21 * 21 + i * 21 * 21 + a * 21 + b;
                if( a == b )
                {
                    pab[index] = pa[ i * 21 + a ];
                } else
                {
                    pab[index] = 0.0;
                }
            }
        }
    }
}
