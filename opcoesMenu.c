

#include "narconio.h"
#include "opcoesMenu.h"
#include "funcoesEnunciado.h"



/** \brief  Abre arquivo de texto no modo Leitura
 *
 * \param METADADOS_ARQ* : Os meta dados do arquivo
 * \param char** : Matriz de carateres para preenchimento
 * \return int : Instrução para encerrar programa ( 1 - encerrar , 0 - nada )
 *
 */

int op1( METADADOS_ARQ* dadosArq , char*** matriz ){
        static int qtd_erros = 0;
        static char nome_tentativa_anterior[ 100 ];
        char nome_arq[ 100 ];


        /// Entrada pelo usuário do nome do arquivo
        printf("Indique o nome do aquivo: ");
        limpaBuffer();
        fgets( nome_arq , 100 , stdin );
        nome_arq[ strlen( nome_arq ) - 1 ] = '\0';
        // Alocação e Atribuição
        dadosArq->nome = (char*)malloc( strlen( nome_arq ) * sizeof( char ) );
        strcpy( dadosArq->nome , nome_arq );

        /// Abertura  e  Verificação de êxito na abertura do arquivo
        if( abre_le_arquivo( matriz , dadosArq->nome , 10 , 10 ) == -1 ){
                // Erro na abertura do arquivo
                printColorido("\a ERRO NA ABERTURA DO ARQUIVO!" , VERMELHO);
                pausaS( 1.5 );          // Pausa por 1 segundo e meio
                qtd_erros++;
        }else{
                // Sucesso na abertura do arquivo
                printColorido("Arquivo Aberto Com Sucesso!" , VERDE);
                pausaS( 1.5 );          // Pausa por 1 segundo e meio
                qtd_erros = 0;          // Zera contagem de falhas
        }

        /// Reiniciar contador de erros
        if( strcmp( dadosArq->nome , nome_tentativa_anterior) )
                qtd_erros = 0;

        /// Execesso de tentativas de abertura do mesmo arquivo
        if( qtd_erros == 4 )
                ErroFatal( FALHA_AUTORIZACAO_ABERTURA_ARQ );


        limpaBuffer();
        return 0;
}
//###########################################################




/** \brief  Imprime matriz na tela
 *
 * \param METADADOS_ARQ* :
 * \param char** : Matriz de carateres para impressão
 * \return int : Instrução para encerrar programa ( 1 - encerrar , 0 - nada )
 *
 */

int op2( METADADOS_ARQ* dadosArq , char*** matriz ){
//        printColoridoXY("Conteudo do Arquivo: " , AZUL , 2 , 2 );
//        printColorido( dadosArq->nome , CIANO );
//
//        cursorXY( 10 , 4 );
//        imprime_matriz_tela( &dadosArq->nome , 10 , 10 );
//        printColoridoXY( "VOLTAR" , AZUL , 30 , 16 );
//        pausaE_LBP();
        return 0;
}
//###########################################################



/** \brief  Localiza e substitui caractere no arquivo
 *
 * \param METADADOS_ARQ* :
 * \param char** : Matriz de carateres para impressão
 * \return int : Instrução para encerrar programa ( 1 - encerrar , 0 - nada )
 *
 */

int op3( METADADOS_ARQ* dadosArq , char*** matriz ){
//        char alvo , substituto;
//        char copia[ 20 ][ 20 ];
//
//        /// Copiando Original
//        for( int i = 0 ; i < 10 ; i++ )
//                strcpy( copia[ i ] , *matriz[ i ] );
//
//        ///
//        printSubliColorXY("Localizar e Substituir" , 25 , 2 , AZUL );
//
//        /// Caractere alvo
//        printColoridoXY("Caractere a ser substitu\241do: " , 3 , 4 , BRANCO );
//        defCorTxt( VERDE );
//        alvo = getchar();
//
//        /// Caractere substituto
//        printColoridoXY("Substituto: " , 3 , 5 , BRANCO );
//        defCorTxt( VERDE );
//        substituto = getchar();
//
//        /// SUBSTITUIÇÃO
//        printColoridoXY("TRABALHANDO NISSO >>>" , 7 , 8 , VERDE );
//        for( int i = 0 ; i < 10 ; i++ )
//                for( int j = 0 ; j < 10 ; j++ )
//                        if( *matriz[ i ][ j ] == alvo )
//                                *matriz[ i ][ j ] = substituto;
//        pausaS( 1.3 );
//        limpaLinha( 8 );
//
//        /// Resultados
//        printSublinhadoXY("Original" , 6  , 8 );
//        cursorXY( 4 , 8 );//        imprime_matriz_tela( (char**)copia , 10 , 10 );
//
//
//        printSublinhadoXY("Alterada" , 25  , 8 );
//        cursorXY( 23 , 8 );
//        imprime_matriz_tela( *matriz , 10 , 10 );
//
        return 0;
}
//###########################################################



/** \brief  Imprime matriz na tela
 *
 * \param METADADOS_ARQ* :
 * \param char** : Matriz de carateres para impressão
 * \return int : Instrução para encerrar programa ( 1 - encerrar , 0 - nada )
 *
 */

int op4( METADADOS_ARQ* dadosArq , char*** matriz ){
        printf("op4");
        pausaMS( 500 );

        return 0;
}
//###########################################################




/** \brief  Imprime matriz na tela
 *
 * \param METADADOS_ARQ* :
 * \param char** : Matriz de carateres para impressão
 * \return int : Instrução para encerrar programa ( 1 - encerrar , 0 - nada )
 *
 */

int op5( METADADOS_ARQ* dadosArq , char*** matriz ){
        printf("op5");

        return 1;
}
