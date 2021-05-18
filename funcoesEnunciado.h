#ifndef __FUNCOESENUNCIADO_H_
#define __FUNCOESENUNCIADO_H_

        /// Funções exigidas no enunciado
        int abre_le_arquivo( char*** m , char* nome_arq , int lins , int cols );
        void imprime_matriz_tela( char** m , int lins , int cols );
        void imprime_matriz_tela_PRO( char** m , int lins , int cols , char caractere , COR cor_padr ,  COR cor_destaque );
        int abre_grava_arquivo(char** m , char* nome_arq , int lins , int cols );
        void troca_caracter( char*** m , int lins , int cols , char c_original , char c_substituto );


#endif // __FUNCOESENUNCIADO_H_
