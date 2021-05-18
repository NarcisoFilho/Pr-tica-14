/** @brief  MENU PADRÃO
 * @author Narciso Filho
 * @date 14-05-2021
 *
 *      Funções para o desenho de um menu interativo simples e multi-uso.
 *      obs.: Utiliza biblioteca narconio.h
 */


#ifndef __MENUPADRAO_H_
#define __MENUPADRAO_H_

        #include "narconio.h"

        void desenhar_menu( DADOS_MENU* menu );
        void atualizar_menu( DADOS_MENU* menu );
        void atualizaSelSetas( int* sel , int limInf , int limSup  );

#endif // __MENUPADRAO_H_
