
#include <stdio.h>
#include <conio.h>

int main(){
        int k , c;
        for( ; ; ){
                printf("%d\r" , _kbhit() );
                if( _kbhit() ) _getch();
//                for( k = 10000 ; k ; k-- );
//                while( ( c = getchar() ) != '\n'  && c != EOF );

        }



}
