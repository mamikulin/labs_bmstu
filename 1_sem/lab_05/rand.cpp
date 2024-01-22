#include "hppcommon.hpp"


using namespace std;

int iRandom( int a, int b ){
    return (a + ( b - a +1) * rand())%100 ;
}

//double dRandom( int a, int b ){
//
//  return a + ( b - a) * rand() / (double)100;
//}

int* rand_int(int len){
    
    
    const int n = len;
    int i;
    int* return_rand = new int[n];
    
    srand( (unsigned int) time( NULL ) );
    rand( );
    for( i = 0; i < n; i++ ){
        return_rand[i] = iRandom( 1, 9 );
    }
    
    return return_rand;
}
