#include <stdio.h>
#include <ctype.h>

void guess_rho_matrix( double* rho, double* pa,
                      double* aln_col, double* maxgapf,
                      double* trialrho )
{
    int i, j, a, b, p;
    p = (int) aln_col[0];
    
    for( i=0; i<(p*21); i++ )
    {
        for( j=0; j<(p*21); j++ )
        {
            rho[ i * (p * 21) + j ] = trialrho[0];
         }
    }
    
    for( i=0; i<p; i++ )
    {
        for( j=0; j<p; j++ )
        {
            for( a=0; a<21; a++ )
            {
                for( b=0; b<21; b++ )
                {
                    if( ( a != b && i == j ) || ( pa[ i * 21 + 20 ] > maxgapf[0] ) || ( pa[ j * 21 + 20 ] > maxgapf[0] ) )
                    {
                        rho[ ( i * 21 + a ) * ( p * 21 ) + j * 21 + b ] = 1e9;
                    }
                }
            }
        }
    }
}
