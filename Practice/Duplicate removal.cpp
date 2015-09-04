#include <iostream>
#include <string.h>
using namespace std;

void  removeDuplicate ( char  s [])
{
    int  len  =  strlen ( s );
    if ( len  <  2 )  return ;
    bool  c [ 256 ];
    memset ( c ,  0 ,  sizeof ( c ));
    int  P  =  0 ;
    for ( int  i = 0 ;  i  <  len ;  ++ i )
    {
        if ( ! c [ s [ i ]])
        {
            s [ P ++ ]  =  s [ i ];
            c [ s [ i ]]  =  true ;
        }
    }
    s [ P ]  =  '\0' ;
}

bool isUnique3( string  s )
{
    int  Check  =  0 ,j =0, var = 0;
    int  len  =  s . length ();
    for ( int  i = 0 ;  s[i]!='\0' ;)
    {
        len  =  s . length ();
        int  v  =  ( int ) ( s [ i ] - ' a ' );
        if ( Check  & ( 1  <<  v ))
        {
            for(j=i;j<len;j++)
            {
                s[j] = s[j+1];
                var++;
            }
            s[j] = '\0';
            //return  false ;
        }
        else
            i++;
        Check  = Check | ( 1  <<  v );
    }
    cout<<"\n"<<s;
    cout<<endl<<var;
    return  true ;

}


int main()
{
    char s[100];
    bool a;
    cin>>s;
    removeDuplicate(s);
    cout<<s;
    //a = isUnique3(s);
    //cout<<"\n"<<(1 << 33);
}
