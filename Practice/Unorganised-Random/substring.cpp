#include <iostream>
#include <String>
using  namespace  std ;

bool  issubstring ( string  S1 ,  string  S2 ) {
    if ( (S1.find ( S2 )) != string :: npos )  return  true ;
    else  return  false ;
}
bool  isRotation ( string  S1 ,  string  S2 ) {
    if ( (S1 . length ())  !=  S2 . length ()  ||  S1 . length () <= 0 )
        return  false ;
    return  issubstring ( S1 + S1 ,  S2 );
}

int  main () {
    string  S1  =  "apple" ;
    string  S2  =  "pleap" ;
    cout << isRotation ( S1 ,  S2 ) << endl ;
    // cout << endl << String :: npos;
    return  0 ;
}
