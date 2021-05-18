

#include "narconio.h"
#include "menuPadrao.h"
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
        static char nome_tentativa_anterior[ 100 ] = { 0 };
        char nome_arq[ 100 ];
        int tam;
        int flag_formato = 0;

        /// Entrada pelo usuário do nome do arquivo
        printColoridoXY("Indique o nome do aquivo: " , 5 , 3 , BRANCO );

        exibirCursorTec();              // Exibir Cursor

        limpaBufferPro();

        defCorTxt( CIANO );
        fgets( nome_arq , 100 , stdin );
        tam = strlen( nome_arq );
        nome_arq[ tam - 1 ] = '\0';
        RESET_PADRAO;
        esconderCursorTec();            // Reesconder o cursor

        /// Adição do .txt
        tam = strlen( nome_arq );
        if( nome_arq[ tam - 1 ] == 't' )
                if( nome_arq[ tam - 2 ] == 'x' )
                        if( nome_arq[ tam - 3 ] == 't' )
                                if( nome_arq[ tam - 4 ] == '.' )
                                        flag_formato = 1;
        if( !flag_formato ){
                nome_arq[ tam ] = '.';
                nome_arq[ tam + 1 ] = 't';
                nome_arq[ tam + 2 ] = 'x';
                nome_arq[ tam + 3 ] = 't';
                nome_arq[ tam + 4 ] = '\0';
        }



        /// Abertura  e  Verificação de êxito na abertura do arquivo
        if( abre_le_arquivo( matriz , nome_arq , dadosArq->lins , dadosArq->cols ) == -1 ){
                /// Erro na abertura do arquivo
                printColorido("\a ERRO NA ABERTURA DO ARQUIVO!" , VERMELHO );
                pausaS( 1.5 );          // Pausa por 1 segundo e meio
                qtd_erros++;
        }else{
                /// Sucesso na abertura do arquivo
                // Alocação e Atribuição
                dadosArq->nome = (char*)malloc( strlen( nome_arq ) * sizeof( char ) );
                strcpy( dadosArq->nome , nome_arq );

                // Aviso
                printColorido("Arquivo Aberto Com Sucesso!" ,  VERDE);
                pausaS( 0.5 );          // Pausa por meio segundo
                pausaE();          // Pausa até usuário teclar enter
                qtd_erros = 0;          // Zera contagem de falhas
        }

        /// Reiniciar contador de erros
        if( strcmp( nome_arq , nome_tentativa_anterior) )
                qtd_erros = 0;
        strcpy( nome_tentativa_anterior , nome_arq );

        /// Excesso de tentativas de abertura do mesmo arquivo
        if( qtd_erros >= 3 )
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

        /// Verificação de existência de arquivo carregado
        if( dadosArq->nome == NULL ){
                avisoNenhumArquivoCarregado();
                return 0;
        }

        /// Arquivo aberto
        printColoridoXY("Conteudo do Arquivo: " , 2 , 2 , AZUL );
        printColorido( dadosArq->nome , CIANO );

        cursorXY( 10 , 4 );
        imprime_matriz_tela( *matriz , 10 , 10 );
        printColoridoXY( "VOLTAR" , 30 , 16 , AZUL );

        pausaE_PRO();


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
        char alvo , substituto;
        char **copia;

        /// Verificação de existência de arquivo carregado
        if( dadosArq->nome == NULL ){
                avisoNenhumArquivoCarregado();
                return 0;
        }


        /// Alocando Copia
        copia = (char**)malloc( dadosArq->lins * sizeof( char* ) );
        if( copia == NULL ) ErroFatal( FALHA_ALOCACAO_MEM );           // Verificação
        for( int i = 0 ; i < 10 ; i++ ){
                copia[ i ] = (char*)malloc( dadosArq->cols * sizeof( char ) );
                if( copia[ i ] == NULL ) ErroFatal( FALHA_ALOCACAO_MEM );   // Verificação
        }

        /// Copiando Original
        for( int i = 0 ; i < 10 ; i++ )
                strcpy( *( copia + i ) , *( *matriz + i )  );

        ///
        limpaBuffer();
        printSubliColorXY("Localizar e Substituir" , 25 , 2 , AZUL );

        /// Caractere alvo
        printColoridoXY("Caractere a ser substitu\241do: " , 3 , 4 , BRANCO );
        defCorTxt( CIANO );
//        limpaBufferPro();
        scanf(" %c" , &alvo );

        /// Caractere substituto
        printColoridoXY("Substituto: " , 3 , 5 , BRANCO );
        defCorTxt( CIANO );
        scanf( " %c" , &substituto );

        /// SUBSTITUIÇÃO
        printColoridoXY("TRABALHANDO NISSO >>>" , 7 , 8 , VERDE );
        troca_caracter( matriz , dadosArq->lins , dadosArq->cols , alvo , substituto );
        pausaS( 1.3 );
        limpaLinha( 8 );

        /// Resultados
        printSublinhadoXY("Original" , 6  , 8 );
        cursorXY( 4 , 8 );        imprime_matriz_tela_PRO( copia , dadosArq->lins , dadosArq->cols , alvo , AMARELO , VERMELHO );


        printSublinhadoXY("Alterada" , 25  , 8 );
        cursorXY( 23 , 8 );
        imprime_matriz_tela_PRO( *matriz , dadosArq->lins , dadosArq->cols , substituto , AMARELO , VERDE );

        /// Liberando Copia
        free( copia );

        pausaE_PRO();
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

        /// Verificação de existência de arquivo carregado
        if( dadosArq->nome == NULL ){
                avisoNenhumArquivoCarregado();
                return 0;
        }

        /// Abertura  e  Verificação de êxito na abertura do arquivo
        if( ( dadosArq->ptrFile = fopen( dadosArq->nome , "w+" ) ) == NULL ){
                /// Erro na abertura do arquivo
                printColorido("\a ERRO NO SALVAMENTO!" , VERMELHO);
                pausaS( 1.5 );          // Pausa por 1 segundo e meio
                return 0;
        }else{
                /// Sucesso na abertura do arquivo
                // Gravação
                for( int i = 0 ; i < dadosArq->lins ; i++)
                        fputs( *( *matriz + i ) , dadosArq->ptrFile );
        }


        printColoridoXY("Arquivo Salvo com Sucesso!" , 10 , 10 , VERDE );

        /// FECHAMENTO DO ARQUIVO
        fclose( dadosArq->ptrFile );

        pausaMS( 500 );
        pausaE_PRO();
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
        return 1;
}



/** \brief Avisa que nenhum arquivo foi carregado
 *
 * \param void
 * \return void
 *
 */

void avisoNenhumArquivoCarregado( void ){
       LMPTELA;
       printColoridoXY("\aNenhum Arquivo Carregado!" , 25 , 10 , VERMELHO );
       printColoridoXY("Carregue algum arquivo..." , 25 , 12 , BRANCO );
       pausaS( 1.5 );   // Pausa de 1,5 segundos
}

