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

#define NLINS 10
#define NCOLS 10

/// PROTÓTIPOS PRINCIPAIS
DADOS_MENU inicializarMenuPratica14( void );
void localizarSubstituirTxtLinhaComando( METADADOS_ARQ* , char*** , int , char** );
void fim( DADOS_MENU );


/** \brief FUNÇÃO PRINCIPAL
 *
 * \param *char :  Nome do Arquivo
 * \param *char :  Caractere a ser substituído
 * \param *char :  Caractere substituto
 * \param *char :  Numero de linhas
 * \param *char :  Numero de colunas
 * \return    int : 0 em caso de sucesso , -1 em caso de falha
 *
 *      → Caso iniciado sem argumentos apresenta interface gráfica ao usuário com opções do menu;
 *
 *      → Caso iniciado pela linha de comando realiza a substituição de caracteres de um arquivo de texto:
 *                      ▄ 1° Argumento: NOME do arquivo a ser aberto
 *                      ▄ 2° Argumento: Quantidade de LINHAS a se considerar
 *                      ▄ 3° Argumento: Quantidade de COLUNAS a se considerar
 *                      ▄ 4° Argumento: CARACTERE a ser substituído
 *                      ▄ 5° Argumento: NOVO CARACTERE
 */

int main( int argc , char* argv[] ){
        int (*funcsMenu[ 5 ] )( METADADOS_ARQ* , char*** ) = { op1 , op2 , op3 , op4 , op5 };
        METADADOS_ARQ dadosArq = { NULL };
        DADOS_MENU menu = inicializarMenuPratica14();
        char** matriz = NULL;

        ativarANSIConsole();

        /// Substituir caractere pelo Interpretador de Comandos
        if( argc > 1 )
                localizarSubstituirTxtLinhaComando(  &dadosArq , &matriz , argc , argv );

        /// Modo Gráfico
        dadosArq.lins = 10;
        dadosArq.cols = 10;
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

                pausaMS( 40 );
        }while( !menu.sair_loop);


        fim( menu );
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
        char buffer_texto[ 50 ];

        /// Título --------------------------------------------------------------------------
        menu.titulo = "\0";
        menu.titulo_subl = false;
        menu.cor_titulo = PRETO;

        /// SUB-Título --------------------------------------------------------------------------
        strcpy( buffer_texto , "Editor de Arquivos TXT");
        menu.cor_sub_titulo = VIOLETA;

        // Alocação
        menu.sub_titulo = (char*)malloc( strlen( buffer_texto ) * sizeof( char ) );
        if( menu.sub_titulo == NULL ) ErroFatal( FALHA_ALOCACAO_MEM );           // Verificação
        strcpy( menu.sub_titulo , buffer_texto );

        /// Configurações ---------------------------------------------------------------
        menu.qtd_items = 5;
        menu.selec = 0;
        menu.sair_loop = 0;
        menu.cor_comum = BRANCO;
        menu.cor_select = VERDE;
        menu.tela.larg = 115;
        menu.tela.altu = 28;

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
                menu.items_menu[ i ] = (char*)malloc( 50 * sizeof( char ) );
                if( menu.items_menu[ i ] == NULL ) ErroFatal( FALHA_ALOCACAO_MEM );   // Verificação
        }

        /// Atribuição de items_menu
        for( int i = 0 ; i < menu.qtd_items ; i++ )
                strcpy( menu.items_menu[ i ] , items_menu[ i ] ) ;

        /// RETORNO
        return menu;
}

void fim( DADOS_MENU menu ){
        char msg[ 100 ] = "        At\202 logo! \1        ";

        defCorTxtFundo( VERDE );
        printColoridoXY(msg , centraTxtXTela(msg , menu.tela ) , centraMatrizYTela( 1 , menu.tela ) , BRANCO );

        pausaS( 1.5 );
}



/** \brief Permite a substituição de caracteres num arquivo de texto pelo interpredador de comandos do SO
 *
 * \param int : argc - Quantidade de argumentos inseridos
 * \param char* : Argumentos em strings
 * \return void : ( Já encerra o programa )
 *
 */
#include "funcoesEnunciado.h"
void localizarSubstituirTxtLinhaComando( METADADOS_ARQ* dadosArq , char*** matriz, int argc , char** argv ){
        int qtd_lins = atoi( argv[ 2 ] );
        int qtd_cols = atoi( argv[ 3 ] );
        char caractere_original = argv[ 4 ][ 0 ];
        char caractere_substituto = argv[ 5 ][ 0 ];

        if( abre_le_arquivo( matriz , argv[ 1 ] /*nome do arquivo*/ , qtd_lins , qtd_cols ) == -1){
                printColorido("ERRO DE ABERTURA DO ARQUIVO!" , VERMELHO );
                exit( -1 );     // Falha de abertura
        }

        troca_caracter( matriz ,  qtd_lins , qtd_cols , caractere_original , caractere_substituto );

        op4( dadosArq , matriz );

        exit( 0 );
}
