#include <stdio.h>
#include <ctype.h>

void aa2num(char** aa, double* aa_len, double* aanum)
{
    const static double aacvs[] =
    {
        999, 0, 3, 4, 3, 6, 13, 7, 8, 9, 21, 11, 10, 12, 2,
        21, 14, 5, 1, 15, 16, 21, 19, 17, 21, 18, 6
    };
    
    int i;
    for( i = 0; i < aa_len[0]; i++ )
    {
        aanum[i] = isalpha( *aa[i]) ? aacvs[*aa[i] & 31] : 20;
    }
}
