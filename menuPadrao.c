
#include "menuPadrao.h"
#include <windows.h>


/** \brief Atualiza a seleção pelo teclado ou mouse
 *
 * \param int* : Endereço da variável inteira correspondente à seleção
 *
 */

void atualizar_menu( DADOS_MENU* menu ){
        /// Pelo Teclado -----------------------------------
        static int delay;

        if( !delay ){
        //        if( checaTeclaEspecial( TECLA_SETA_BAIXO ) )
                if( GetAsyncKeyState( VK_DOWN )  &&  0x8000 )
                        if( menu->selec < menu->qtd_items - 1 )
                                menu->selec++ , delay = 1;

        //        if( checaTeclaEspecial( TECLA_SETA_CIMA ) )
                if( GetAsyncKeyState( VK_UP )  &&  0x8000 )
                    if( menu->selec > 0 )
                                menu->selec-- , delay = 1;
        }else
                delay--;

//        limpaBuffer();
}
//###########################################################



/** \brief Desenha o menu
 *
 * \param DADOS_MENU* : Dados do menu
 *
 */

void desenhar_menu( DADOS_MENU* menu ){
        esconderCursorTec();

        for( int i = 0 ; i < menu->qtd_items ; i++ )
                if( i != menu->selec )
                        printColoridoXY( menu->items_menu[ i ] , AZUL , 10 , 3 + i );

        printColoridoXY( menu->items_menu[ menu->selec ] , VERDE , 10 , 3 + menu->selec );
}
//###########################################################
