#include <stdio.h>
#include <ctype.h>

void calculate_sequence_weights(double *alnnum, double* alnnum_row,
                                double* alnnum_col, double* meanfracid,
                                double* idtresh, double* wtcount,
                                double* weight, double* wtsum )
{
    int i, j, k, n, p, sum, ntresh;
    n = (int) alnnum_row[0];
    p = (int) alnnum_col[0];
    double fracid;
    for( i = 0; i < n; i++ )
    {
        for( j = i + 1; j < n; j++ )
        {
            sum = 0;
            for( k = 0; k < p; k++ )
            {
                if( alnnum[ i * p + k ] == alnnum[ j * p + k ] )
                {
                    sum++;
                }
            }
            fracid = ( double ) sum / p;
            meanfracid[0] += fracid;
        }
    }
    meanfracid[0] /= 0.5 * n * ( n - 1.0 );
    if( 0.5 < ( 0.38 * 0.32 / meanfracid[0] ) )
    {
        idtresh[0] = 0.5;
    } else
    {
        idtresh[0] = ( 0.38 * 0.32 / meanfracid[0] );
    }
    for( i = 0; i < n; i++ )
    {
        for( j = i + 1; j < n; j++ )
        {
            ntresh = p * idtresh[0];
            for( k = 0; ntresh > 0 && k < p; k++ )
            {
                if( alnnum[ i * p + k ] != alnnum[ j * p + k ] )
                {
                    ntresh--;
                }
            }
            if( ntresh > 0 )
            {
                wtcount[i]++;
                wtcount[j]++;
            }
        }
    }
    for( i = 0; i < n; i++ )
    {
        weight[i] = 1.0 / ( 1 + wtcount[i] );
        wtsum[0] += weight[i];
    }
}
