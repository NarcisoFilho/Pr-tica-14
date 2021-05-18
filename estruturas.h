#ifndef __ESTRUTURAS_H_
#define __ESTRUTURAS_H_

        /// ESTRUTURAS SIMPLES ══════════════════════════════════════════════
        typedef int BOOL;
        #define true 1
        #define false 0

        typedef int COR;

        typedef struct{
                int x;
                int y;
        }PONTO;

        typedef struct{
                int x;
                int y;
                int larg;
                int altu;
        }RETANG;

        /// ESTRUTURAS COMPLEXAS ════════════════════════════════════════════
        typedef struct {
                FILE* ptrFile;
                char* nome;
                char* pasta;
                void* tipo;

                int lins;
                int cols;
        }METADADOS_ARQ;

        typedef struct {
                char* titulo;
                char* sub_titulo;
                char** items_menu;
                int qtd_items;
                int selec;
                int sair_loop;

                COR cor_comum;
                COR cor_select;
                COR cor_titulo;
                COR cor_sub_titulo;

                BOOL titulo_subl;
                RETANG tela;
        }DADOS_MENU;



#endif // __ESTRUTURAS_H_
