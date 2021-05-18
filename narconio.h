/***-  narconio.h ════════════════════════════════╗
        *  @author Manoel Narciso Reis Soares Filho
        *  @date 14/05/2021
        *  @version 1.0
        *  ════════════════════════════════════════╝
        *       Fornece:
        *               -Funções de entrada interativas
        *               -Funções de design da tela
        *
        *       Sistema Operacional: Teoricamente Windows , Linux , MacOS
        *
        */

#ifndef __NARCONIO_H_
#define __NARCONIO_H_

        #include <stdio.h>
        #include <stdlib.h>
        #include <conio.h>
        #include <time.h>
        #include <string.h>
        #include "estruturas.h"

    /// INTERAÇÃO COM O USUÁRIO ════════════════════════════════════
        /// SISTEMA ------------------------------------------------------------------------------
        void pausaMS( int tempoMS );                 // Pausa a execução. Tempo em millisegundos
        void pausaS( float tempoS );                  // Pausa a execução. Tempo em segundos
        void pausaE( void );                              // Pausa a execução até o usuário pressionar enter
        void pausaE_PRO( void );                     //Pausa a execução até o usuário pressionar enter, com limpeza prévia de buffer e pausa
        void limpaBuffer( void );                        // Limpa o buffer do teclado
        void limpaBufferPro( void );                        // Limpa o buffer do teclado com garantia de não alteração do cursor
        void ErroFatal( int cod );                        // Encerra sistema e exibe mensagem de erro

        // CODIGOS DE ERROS
        #define FALHA_AUTORIZACAO_ABERTURA_ARQ 100
        #define FALHA_ALOCACAO_MEM 101

        /// TECLADO ------------------------------------------------------------------------------
        BOOL checaTecla( int tecla );                   // Verifica se tecla está sendo pressionada
        BOOL checaTeclaEspecial( int tecla );        // Verifica se tecla especial está sendo pressionada

        // TECLAS SIMPLES
        #define TECLA_ENTER '\n'
        #define TECLA_BACKSPACE '\b'
        #define TECLA_ESC 27

        // TECLAS ESPECIAIS
        #define TECLA_SETA_DIREITA  22477
        #define TECLA_SETA_ESQUERDA 22475
        #define TECLA_SETA_BAIXO 22480
        #define TECLA_SETA_CIMA 22472

        /// MOUSE ---------------------------------------------------------------------------------

    /// TELA ═════════════════════════════════════════════════════
        /// DESIGN --------------------------------------------------------------------------------
        void defCorTxt( COR cor );                                 // Define cor de saída do texto
        void defCorTxtFundo( COR cor );                        // Define cor de saída do fundo do texto
        void defEstiloTxt( int estilo_de_texto );               // Define o estilo de saída do texto

        void putcXY( char caractere , int x , int y  );                                  // Saída de caractere nas coordenadas ( x , y )
        void putcColorido( char caractere , COR cor );                                  // Saída de caractere colorido
        void putcColoridoXY( char caractere , int x , int y , COR cor );           // Saída de caractere colorido nas coordenadas ( x , y )

        void printXY( char* texto , int x , int y  );                                 // Saída de texto nas coordenadas ( x , y )
        void printColorido( char* texto , COR cor );                                    // Saída de texto colorido
        void printColoridoXY( char* texto , int x , int y , COR cor );          // Saída de texto colorido na posição ( x , y )
        void printSublinhado( char* texto );                                            // Saída de texto sublinhado
        void printSublinhadoXY( char* texto , int x , int y );                      // Saída de texto sublinhado em posição ( x , y )
        void printSubliColorXY( char* texto , int x , int y , COR cor );        // Saída de texto sublinhado  e colorido em posição ( x , y )


        void limpaTela( void );                                                                 // Limpa toda a tela
        void limpaLinha( int linha );                                                           // Limpa uma linha

        // CORES
        #define PRETO 0
        #define VERMELHO 1
        #define VERDE 2
        #define AMARELO 3
        #define AZUL 4
        #define VIOLETA 5
        #define CIANO 6
        #define BRANCO 7

        // ESTILOS DE TEXTO
        #define PADRAO 0
        #define NEGRITO 1
        #define ITALICO 3
        #define SUBLINHADO 4
        #define COR_NEGATIVA 7
        #define INVISIVEL 8
        #define RISCADO 9

        // MACROS
        #define RESET_PADRAO printf("\x1b[0m")         // Reinicia estilo e cor para o padrão do terminal
        #define LMPTELA printf("\x1b[2J")                    // Limpa Tela e reinicia posição do cursor para o inicio

        /// CURSOR ----------------------------------------------------------
        void cursorXY( int x , int y );                         // Posiciona o cursor nas coordenadas ( x , y )
        void cursorP( PONTO ponto );                        // Posiciona o cursor no ponto
        void cursorHome( void );                              // Posiciona o cursor no ponto incial ( 0 , 0 )
        void avancarCursorLins( int qtd_lins );           // Avança o cursor um número de linhas sem alterar coluna
        void avancarCursorCols( int qtd_cols );         // Avança o cursor um número de colunas sem alterar linha


        void salvarPosCursor( void );                        // Salva Posicão do cursor
        void carregarPosCursor( void );                    // Posiciona o cursor na posição salva anteriormente com o comando salvarPosCursor

        void esconderCursorTec( void );                    // Torna o cursor do teclado INVISÍVEL
        void exibirCursorTec( void );                         // Torna o cursor do teclado VISÍVEL
        PONTO obterCursorTec( void );                     // Retorna posição do cursor do teclado




    /// STRINGS  ═════════════════════════════════════════════════════
        /// MEDIÇÃO --------------------------------------------------------------------------------

        int centraTxtXTela( char* texto , RETANG tela );                    // Retorna coordenada de inserção de string para centralização horizontal
        int centraMatrizYTela( int qtd_elementos , RETANG tela );         // Retorna coordenada de inserção de conjunto de arrays para centralização vertical

#endif // __NARCONIO_H_
