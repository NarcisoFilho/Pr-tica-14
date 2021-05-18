
#include "narconio.h"

/// INTERAÇÃO COM O USUÁRIO ════════════════════════════════════

/// SISTEMA ------------------------------------------------------------------------------
/** \brief Pausa a execução
 *
 * \param int : O tempo em milisegundos
 * \return void
 *
 */

void pausaMS( int tempoMS ){
        long int tempoInicial = clock();
        while( clock() < tempoInicial + tempoMS );
}
//###########################################################



/** \brief Pausa a execução
 *
 * \param int : O tempo em segundo
 * \return void
 *
 */

void pausaS( float tempoS ){
        long int tempoInicial = clock();
        while( clock() < tempoInicial + tempoS * 1000 );
}
//###########################################################



/** \brief Pausa a execução até o usuário pressionar enter
 *
 * \param void
 * \return void
 *
 */
#include <windows.h>
void pausaE( void ){
//        while( !checaTecla( TECLA_ENTER ) );
        while( !(GetAsyncKeyState( VK_RETURN ) & 0x8000 ) );
}
//###########################################################



/** \brief Pausa a execução até o usuário pressionar enter, com limpeza prévia de buffer e micro pausa
 *
 * \param void
 * \return void
 *        Mantenha o programa em suspensão até o usuário pressionar enter. Realiza previamente uma
 *      limpeza de buffer e aplica uma pausa para evitar que o pressionamento do enter interfira em
 *      outro procedimento
 */
void pausaE_PRO( void ){
        pausaMS( 500 );
        limpaBuffer();
        pausaE();
        pausaMS( 50 );
}
//###########################################################



/** \brief Limpa o Buffer do teclado
 *
 * \param void
 * \return void
 *
 */
void limpaBuffer( void ){
        char c;

        if( kbhit() )
                while( ( c = getchar() ) != '\n'  &&  c != EOF );
}
//###########################################################



/** \brief Limpa o Buffer do teclado com garantia de não alterar cursor
 *
 * \param void
 * \return void
 *      Salva a posição do cursor e restaura após limpeza do buffer. Não recomendada se houver uso do
 *      do comando salvarCursor  no programa
 */
void limpaBufferPro( void ){
        salvarPosCursor();
        limpaBuffer();
        carregarPosCursor();
}
//###########################################################



/** \brief Encerra sistema e exibe mensagem de erro
 *
 * \param int : Código do erro ( consultar narconio.h )
 * \return void
 *
 */
void ErroFatal( int cod ){
        // colorir fundo azul@@#@#@#@#@
        defCorTxtFundo( AZUL );
        LMPTELA;
        cursorHome();
        for( int i = 700 ; i ; i-- )
                printf(" ");

        cursorHome();        printSublinhadoXY( "\aERRO FATAL!! ENCERRANDO SISTEMA >>" , 30 , 3 );
        pausaS( 0.5 );          // Pausa por meio segundo
        printf("\a");
        pausaS( 0.5 );          // Pausa por meio segundo
        printf("\a");

        /// Mensagem de erro
        switch( cod ){
                // Problemas de autorização para abertura de arquivo pelo OS
                case 100:
                        printColoridoXY("ERRO 100: Problemas de autoriza\207\306o de abertura de arquivos. " , 10 , 9 ,  BRANCO  );
                        printColoridoXY("Sugest\306o: Verifique, no seu SO, as permiss\344es de leitura e grava\207\306o do compilador " , 10 , 15  , BRANCO );
                        avancarCursorLins( 3 );
                        pausaS( 5 );
                        exit(100);

                // Problemas de alocação de memória
                case 101:
                        printColoridoXY("ERRO 101: Problemas na alocação de memória. " , 10 , 9 ,  BRANCO);
                        printColoridoXY("Sugest306o: Verifique as configura\207\344es de acesso \205 mem\162ria do compilador " , 10 , 15 , BRANCO );
                        avancarCursorLins( 3 );
                        pausaS( 5 );
                        exit(101);
        }
}
//###########################################################



/// TECLADO ------------------------------------------------------------------------------

/** \brief Checa o status de acionamento de uma tecla
 *
 * \param int : Código da Tecla
 * \return BOOL : Status de acionamento da tecla
 *
 */
BOOL checaTecla( int tecla ){
        /// Teclas Simples
        if ( kbhit() )
                if( getch() == tecla )
                        return true;

        return false;
}
//###########################################################



/** \brief Checa o status de acionamento de uma tecla especial
 *
 * \param int : Código da Tecla
 * \return BOOL : Status de acionamento da tecla
 *
 */
BOOL checaTeclaEspecial( int tecla ){
        int codigo_tecla_recebido;
        int cod_1 = tecla / 100;
        int cod_2 = tecla % 100;

        /// Coletando 1° código da tecla pressionada, se houver
        if( !kbhit() ) return false;
        else {
                 codigo_tecla_recebido = getch();
                /// Teclas Especiais
                if ( codigo_tecla_recebido == cod_1){
//                        while( getch() == cod_1);
                        do{
                                codigo_tecla_recebido = getch();
                        }while( codigo_tecla_recebido == cod_1 );

                        /// Coletando segundo código
                        if( getch() == cod_2 )
                                return true;
                }
        }

        return false;
}
//###########################################################



/// TELA ═════════════════════════════════════════════════════

/// DESIGN --------------------------------------------------------------------------------


/** \brief Saída de caractere nas coordenadas ( x , y )
 *
 * \param char : Caractere
 * \param int : Coordenada x
 * \param int : Coordenada y
 * \return void
 *
 */

void putcXY( char caractere , int x , int y  ){
        printf("\x1b[%d;%dH" , y , x );
        printf("%c" , caractere );
}
//###########################################################



/** \brief Saída de caractere colorido
 *
 * \param char : Caractere
 * \param COR : Cor do caractere
 * \return void
 *
 */

void putcColorido( char caractere , COR cor ){
        printf("\x1b[3%dm%c" , cor , caractere );
        RESET_PADRAO;
}
//###########################################################



/** \brief Saída de caractere colorido nas coordenadas ( x , y )
 *
 * \param char : Caractere
 * \param int : Coordenada x
 * \param int : Coordenada y
 * \param COR : Cor do caractere
 * \return void
 *
 */

void putcColoridoXY( char caractere , int x , int y , COR cor ){
        printf("\x1b[%d;%dH" , y , x );
        printf("\x1b[3%dm%c" , cor , caractere );
        RESET_PADRAO;
}
//###########################################################



/** \brief Saída de texto nas coordenadas ( x , y )
 *
 * \param char* : Texto
 * \param int : Coordenada x
 * \param int : Coordenada y
 * \return void
 *
 */
void printXY( char* texto , int x , int y  ){
        printf("\x1b[%d;%dH" , y , x );
        printf("%s" , texto );
}
//###########################################################



/** \brief Saída de texto formatado colorido
 *
 * \param char* : Texto
 * \param COR : Cor do texto
 * \return void
 *
 */
void printfColorido( char* texto , COR cor ){

        // Em construção

}
//###########################################################


/** \brief Saída de texto colorido
 *
 * \param char* : Texto
 * \param COR : Cor do texto
 * \return void
 *
 */
void printColorido( char* texto , COR cor ){
        printf("\x1b[3%dm %s" , cor , texto );
        RESET_PADRAO;
}
//###########################################################


/** \brief Saída de texto colorido nas coordenadas ( x , y )
 *
 * \param char* : Texto
 * \param int : Coordenada x
 * \param int : Coordenada y
 * \param COR : Cor do texto
 * \return void
 *
 */
void printColoridoXY( char* texto , int x , int y , COR cor ){
        printf("\x1b[%d;%dH" , y , x );
        printf("\x1b[3%dm%s" , cor , texto );
        RESET_PADRAO;
}
//###########################################################



/** \brief Saída de texto sublinhado
 *
 * \param char* : Texto
 * \return void
 *
 */
void printSublinhado( char* texto ){
        printf("\x1b[4m");
        printf( "%s" , texto );
        RESET_PADRAO;
}
//###########################################################



/** \brief  Saída de texto sublinhado em posição (x , y )
 *
 * \param char* : Texto
 * \param int : Coordenada x
 * \param int : Coordenada y
 * \return void
 *
 */
void printSublinhadoXY( char* texto , int x , int y ){
        printf("\x1b[4m");
        cursorXY( x , y );
        printf( "%s" , texto );
        RESET_PADRAO;
}
//###########################################################



/** \brief  Saída de texto sublinhado e colorido em posição (x , y )
 *
 * \param char* : Texto
 * \param int : Coordenada x
 * \param int : Coordenada y
 * \param COR : Cor do texto
 * \return void
 *
 */
void printSubliColorXY( char* texto , int x , int y , COR cor ){
        defCorTxt( cor );
        printf("\x1b[4m");
        cursorXY( x , y );
        printf( "%s" , texto );
        RESET_PADRAO;
}
//###########################################################



/** \brief Define COR do texto de saída
 *
 * \param COR
 * \return void
 *
 */
void defCorTxt( COR cor ){
        printf("\x1b[3%dm" , cor);
}
//###########################################################



/** \brief Define COR do fundo do texto
 *
 * \param COR
 * \return void
 *
 */
void defCorTxtFundo( COR cor ){
        printf("\x1b[4%dm" , cor);
}
//###########################################################



/** \brief Define ESTILO de saída do texto
 *
 * \param int : ESTILO
 * \return void
 *
 */
void defEstiloTxt( int estilo_do_texto ){
        printf("\x1b[%dm" , estilo_do_texto );
}
//###########################################################


/** \brief Limpa toda a Tela
 *
 * \param void
 * \return void
 *
 */

void limpaTela( void ){
        printf("\x1b[2J");
}

/** \brief Limpa um Linha
 *
 * \param int : Número da linha
 * \return void
 *
 */
void limpaLinha( int linha ){
        cursorXY( 0 , linha );
        printf("\x1b[2K");
}



/// CURSOR ----------------------------------------------------------

/** \brief Posiciona o cursor na coluna x e na linha y
 *
 * \param int : x
 * \param int : y
 * \return void *
 */
void cursorXY( int x , int y ){
        printf("\x1b[%d;%dH" , y , x);
}
//###########################################################



/** \brief Posiciona o cursor no PONTO ponto
 *
 * \param PONTO : ponto
 * \param
 * \return
 *
 */

void cursorP( PONTO ponto ){
        printf("\x1b[" "%d" ";" "%d" "H" , ponto.y , ponto.x );
}
//###########################################################



/** \brief Posiciona o cursor no ponto incial ( 0 , 0 )
 *
 * \param void
 * \return void
 *
 */

void cursorHome( void ){
        printf("\x1b[H");
}
//###########################################################



/** \brief Posiciona o cursor em uma linha
 *
 * \param int : linha
 * \return void
 *
 */

void cursorLinha( int linha ){
        // Em construção
}
//###########################################################



/** \brief Salva Posicão do cursor
 *
 * \param void
 * \return void
 *
 */

void salvarPosCursor( void ){
        printf("\x1b[s");
}
//###########################################################



/** \brief Posiciona o cursor na posição salva anteriormente com o comando salvarPosCursor
 *
 * \param void
 * \return void
 *
 */

void carregarPosCursor( void ){
        printf("\x1b[u");
}
//###########################################################



/** \brief Avança o cursor um número de linhas sem alterar coluna
 *
 * \param int : Quantidade de linhas para avançar( ou recuar se negativo )
 * \return void
 *
 */

void avancarCursorLins( int qtd_lins ){
        if( qtd_lins > 0 )
                printf("\x1b[%dB" , qtd_lins);
        else
                printf("\x1b[%dA" , -qtd_lins);
}
//###########################################################



/** \brief Avança o cursor um número de colunas sem alterar linha
 *
 * \param int : Quantidade de colunas para avançar( ou recuar se negativo )
 * \return void
 *
 */

void avancarCursorCols( int qtd_cols ){
        if( qtd_cols > 0 )
                printf("\x1b[%dC" , qtd_cols);
        else
                printf("\x1b[%dD" , -qtd_cols);
}
//###########################################################



/** \brief Torna o cursor do teclado invisivel
 *
 * \param void
 * \return void
 *
 */

void esconderCursorTec( void ){
        printf("\x1b[?25l");
}
//###########################################################



/** \brief Torna o cursor do teclado visivel
 *
 * \param
 * \param
 * \return
 *
 */

void exibirCursorTec( void ){
        printf("\x1b[?25h");
}
//###########################################################



/** \brief Obtém as coordenadas do cursor do teclado
 *
 * \param void
 * \return PONTO : Posição do cursor do teclado
 */
PONTO obterCursorTec( void ){
//        printf("\x1b[6n");
        // Em construção
        return (PONTO){ 0 , 0};
}
//###########################################################



/// STRINGS ═════════════════════════════════════════════════════
/// MEDIÇÃO --------------------------------------------------------------------------------



/** \brief Retorna coordenada de inserção de string para centralização horizontal
 *
 * \param char* : Texto a ser centralizad
 * \param RETANG : Tela de referência
 * \return int : Número da coluna de inserção do texto para ficar centralizado
 *
 */

int centraTxtXTela( char* texto , RETANG tela ){
        return ( tela.larg - strlen( texto ) ) / 2;
}
//###########################################################



/** \brief Retorna coordenada de inserção de conjunto de strings para centralização vertical
 *
 * \param int :
 * \param RETANG : Tela de referência
 * \return int : Número da linha de inserção da matriz para ficar centralizado
 *
 */

int centraMatrizYTela( int qtd_elementos , RETANG tela ){
        return ( tela.altu - qtd_elementos ) / 2;
}
//###########################################################


