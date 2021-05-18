

#include "narconio.h"

/** \brief Abre arquivo de texto no modo Leitura
 *
 * \param char** : Ponteiro para ponteiro de caractere
 * \param char* : O Nome do Arquivo a ser aberto
 * \param int : Quantidade de LINHAS
 * \param int : Quantidade de COLUNAS
 * \return int : 1 em caso de sucesso , -1 em caso de falha
 *
 */

int abre_le_arquivo( char*** endMat , char* nome_arq , int lins , int cols ){
        FILE* arq;

        /// Abertura do Arquivo
        arq = fopen( nome_arq , "r" );
        /// Verificação de Abertura do Arquivo
        if( arq == NULL)
                return -1;      // ERRO DE ABERTURA
        else{
                /// Alocação da Matriz
                *endMat = (char**)malloc(  lins * sizeof( char* ) );  // Linhas
                for( int i = 0 ; i < lins ; i++ ) *( *endMat +  i ) = (char*)malloc(  cols * sizeof( char ) ); // Colunas

                /// Preenchimento de m
                for( int i = 0 ; i < lins ; i++ ){
                        pausaMS( 33 );
                        fgets( *( *endMat +  i ) , 200 , arq );
                        printColoridoXY( *( *endMat +  i ) , 30 , 7 + i , AMARELO );
                }
        }

        /// Fechamento do Arquivo e Retorno
        fclose( arq );
        return 1;       // SUCESSO NA OPERAÇÃO
}
//###########################################################



/** \brief Imprime uma Matriz de Caracteres na tela
 *
 * \param char** : Matriz a ser impressa
 * \param int : Quantidade de LINHAS
 * \param int : Quantidade de COLUNAS
 */

void imprime_matriz_tela( char** m , int lins , int cols ){
        salvarPosCursor();
        for( int i = 0  ; i < 10 ; i++ ){
                        carregarPosCursor();
                        avancarCursorLins( i + 1 );
                        printColorido( m[ i ] , AMARELO );
        }
}
//###########################################################



/** \brief Imprime uma Matriz de Caracteres na tela destacando algum caracter
 *
 * \param char** : Matriz a ser impressa
 * \param int : Quantidade de LINHAS
 * \param int : Quantidade de COLUNAS
 * \param char : Caractere a ser destacado
 * \param COR : Cor Padrão
 * \param COR : Cor do Destaque
 * \return void
 */

void imprime_matriz_tela_PRO( char** m , int lins , int cols , char caractere , COR cor_padr ,  COR cor_destaque ){
        COR cor;

        salvarPosCursor();
        for( int i = 0  ; i < 10 ; i++ )
                for( int j = 0  ; j < 10 ; j++ ){

                        if( !( j % 10 ) ){
                                carregarPosCursor();
                                avancarCursorLins( i + 1 );
                        }

                        if( m[ i ][ j ] == caractere) cor = cor_destaque;
                        else cor = cor_padr;

                        putcColorido( m[ i ][ j ] , cor );
                }
}
//###########################################################




/** \brief Abre arquivo de texto no modo Gravação
 *
 * \param char** : Ponteiro para ponteiro de caractere
 * \param char* : O Nome do Arquivo a ser sobreescrito ou criado
 * \param int : Quantidade de LINHAS
 * \param int : Quantidade de COLUNAS
 * \return int : 1 em caso de sucesso , -1 em caso de falha
 *
 */

int abre_grava_arquivo(char** m , char* nome_arq , int lins , int cols ){
        FILE* arq;

        /// Abertura do Arquivo
        arq = fopen( nome_arq , "w" );

        /// Verificação de Abertura do Arquivo
        if( arq == NULL)
                return -1;      // ERRO DE ABERTURA
        else{
                /// Preenchimento do arquivo
                for( int i = 0 ; i < lins ; i++ )
                        for( int j = 0 ; j < cols ; j++ ){
                                // Preenche arquivo a partir de m
                                fputc( m[ i ][ j ] , arq );

                                // Pula uma Linha no arquivo
                                if( ! ( j % cols ) )
                                        fputc( '\n' , arq );
                        }
        }

        /// Fechamento do Arquivo e Retorno
        fclose( arq );
        return 1;       // SUCESSO NA OPERAÇÃO


}
//###########################################################


/** \brief Troca caracteres em matriz
 *
 * \param char** : Matriz de Caracteres
 * \param int : Quantidade de LINHAS
 * \param int : Quantidade de COLUNAS
 * \param char : Caractere a ser substitído
 * \param char : Caractere substituto
 *
 */

void troca_caracter( char ***m , int lins , int cols , char c_original , char c_substituto ){
        for( int i = 0 ; i < lins ; i++ )
                for( int j = 0 ; j < cols ; j++ )
                        if( *( *( *m + i ) + j ) == c_original )
                                *( *( *m + i ) + j ) = c_substituto;
}
//###########################################################
