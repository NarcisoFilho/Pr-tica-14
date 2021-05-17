/***-  UFRGS ═══════════════════════════════════╗
        *  INF01202 - Algorítmos e Programação
        *  Aluno: Manoel Narciso Reis Soares Filho
        *  Cartão: 00326621
        *  Data: 14/05/2021
        *  ════════════════════════════════════════╝
        *
        *    PRÁTICA 14 -------------------------------------------------
        *               Programa que abre arquivo de texto, sendo capaz
        *       de extrair ou modificar conteúdo.
        *       Itens do Menu:
        *
        *
        */

/// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "narconio.h"
#include "opcoesMenu.h"
#include "menuPadrao.h"
#include "ativar_ansi_windows.h"
#include "windows.h"

 /// PROTÓTIPOS
DADOS_MENU inicializarMenuPratica14( void );

/** \brief PRINCIPAL
 *
 * \param *char :  Nome do Arquivo
 * \param *char :  Caractere a ser substituído
 * \param *char :  Caractere substituto
 * \return int : 1 em caso de suscesso , -1 em caso de falha
 *
 */

int main(){
        int (*funcsMenu[ 5 ] )( METADADOS_ARQ* , char*** ) = { op1 , op2 , op3 , op4 , op5 };
        METADADOS_ARQ dadosArq;
        DADOS_MENU menu = inicializarMenuPratica14();
        char** matriz = NULL;

        ativarANSIConsole();

        do{
                atualizar_menu( &menu );
                desenhar_menu( &menu );
//                if( checaTecla( TECLA_ENTER ) )
                if( GetAsyncKeyState( VK_RETURN )  &  0x8000 ){
                        LMPTELA;
                        menu.sair_loop = funcsMenu[ menu.selec ]( &dadosArq , &matriz );
                        LMPTELA;
                        menu.selec = 0;
                }

                pausaMS( 30 );
        }while( !menu.sair_loop);

        return 0;
}
//###########################################################



/** \brief Cria o menu da prática 14
 *
 * \param void
 * \return DADOS_MENU
 *
 */

DADOS_MENU inicializarMenuPratica14( void ){
        DADOS_MENU menu;

        /// Título --------------------------------------------------------------------------
        menu.titulo = "Editor de Arquivos Texto";
        menu.titulo_subl = true;
        menu.cor_titulo = AZUL;

        /// Configurações ---------------------------------------------------------------
        menu.qtd_items = 5;
        menu.selec = 0;
        menu.sair_loop = 0;
        menu.cor_comum = BRANCO;
        menu.cor_select = VERDE;

        /// Texto Items do Menu --------------------------------------------------------
        char items_menu[  ][ 100 ] = {
                "Abrir Arquivo",
                "Exibir Dados",
                "Localizar e Substituir",
                "Salvar Modifica\207\345es",
                "Sair"
        };

        /// Alocação de items_menu
        menu.items_menu = (char**)malloc( menu.qtd_items * sizeof( char* ) );
        if( menu.items_menu == NULL ) ErroFatal( FALHA_ALOCACAO_MEM );           // Verificação
        for( int i = 0 ; i < menu.qtd_items ; i++ ){
                menu.items_menu[ i ] = (char*)malloc( 100 * sizeof( char ) );
                if( menu.items_menu[ i ] == NULL ) ErroFatal( FALHA_ALOCACAO_MEM );   // Verificação
        }

        /// Atribuição de items_menu
        for( int i = 0 ; i < menu.qtd_items ; i++ )
                for( int j = 0 ; j < strlen( items_menu[ i ] ) ; j++ )
                        menu.items_menu[ i ][ j ] = items_menu[ i ][ j ] ;



        return menu;
}




