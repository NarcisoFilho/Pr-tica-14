
#include "menuPadrao.h"
#include <windows.h>


/** \brief Atualiza a sele��o pelo teclado ou mouse
 *
 * \param int* : Endere�o da vari�vel inteira correspondente � sele��o
 *
 */

void atualizar_menu( DADOS_MENU* menu ){
        /// Pelo Teclado -----------------------------------
                atualizaSelSetas( &menu->selec , 0 , menu->qtd_items - 1 );
}
//###########################################################



/** \brief Desenha o menu
 *
 * \param DADOS_MENU* : Dados do menu
 *
 */

void desenhar_menu( DADOS_MENU* menu ){
        COR cor;
        int centroY = centraMatrizYTela ( 2 * menu->qtd_items , menu->tela ) + menu->tela.altu / 9;

        esconderCursorTec();

        printSubliColorXY( menu->sub_titulo , centraTxtXTela( menu->sub_titulo , menu->tela ) , centroY - 4 , menu->cor_sub_titulo );
        for( int i = 0 ; i < menu->qtd_items ; i++ ){
                if( i == menu->selec ) cor = menu->cor_select;
                else cor = menu->cor_comum;

                printColoridoXY( menu->items_menu[ i ] , centraTxtXTela( menu->items_menu[ i ] , menu->tela ) , centroY + 4 * i , cor );
        }
}
//###########################################################



/** \brief Atualiza vari�vel de sele��o pelas teclas setas
 *
 * \param int* : Endere�o da vari�vel de sele��o
 * \param int : Limite INFERIOR do valor da vari�vel de sele��o
 * \param int : Limite SUPERIOR do valor da vari�vel de sele��o
 * \return void
 *
 */
 void atualizaSelSetas( int* sel , int limInf , int limSup  ){
//        if( checaTeclaEspecial( TECLA_SETA_BAIXO ) )
        if( GetAsyncKeyState( VK_DOWN )  &  0x8000 )
                if( *sel < limSup )
                        *sel += 1;

//        if( checaTeclaEspecial( TECLA_SETA_CIMA ) )
        if( GetAsyncKeyState( VK_UP )  &  0x8000 )
            if( *sel > limInf )
                        *sel -= 1;
}
