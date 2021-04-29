/*
    spicoli piersilvio
    esercizio 2
*/

#include <stdio.h>
#define DIM 100

//var. locali
int flag = 0; //0 = false
char *punt_char;

//prototipi
void check(int);

int main()
{
    //var. locali
    char parola[DIM];
    char c;
    int lung;

    while(flag == 0)
    {
        punt_char = parola;
        lung = 0;

        printf("\ncontrollare se la parola e palindroma o meno: ");

        /* fintantochè i caratteri immessi in input
           siano diversi dallo spazio e il ritorno a capo,
           assegno all'area di memoria il valore del carattere immesso con getchar()
           icrementando di ogni posizione il puntatore all'array della parola */

        while(((c = getchar()) != ' ' && c != '\n'))
        {
            *(punt_char + lung) = c; //aggiungo al puntatore il carattere corrente e incremento la lunghezza per passare alla cella del pt. succ
            lung += 1;
        }

        check(lung);
    }

    return 0;
}

void check(int dim)
{
    //var locali
    int palindroma = 1;
    int i, j;

    if(dim == 0) //se la lunghezza della stringa è 0, il prog. termina!
    {
            flag = 1;
            printf("\n\tFine Programma\n");
    }
    else
    {
        *(punt_char + dim) = '\0'; //assegno il carattere di fine stringa al puntatore dell'array parola per memorizzarla
        //printf("\n\tLa parola ha lunghezza %d caratteri\n", lung);

        if(dim == 1)
        {
            printf("\tCarattere Isolato\n");
        }
        else
        {
            i = 0; //da sinistra
            j = dim - 1; //da destra

            while(i < j)
            {
                palindroma = 1;  //supponiamo che la parola sia palindroma

                /*
                verifico se gli elementi alle posizioni sommate agli estremi (i e j) sono uguali
                allora incremento l'estremo di sinistra e decremento l'estremo di destra
                in modo da passare alle celle successive per controlarle*/
                /* altrimenti, la parola non è palindroma */

                if( *(punt_char + i) == *(punt_char + j) )
                {
                    i += 1;
                    j -= 1;
                }
                else
                {
                    printf(" \n\tLa parola non e' palindroma\n");
                    palindroma = 0;
                    break;
                }

            }


            if(palindroma == 1)
            {
                puts(" \n\tLa parola e' palindroma\n");
            }
        }
    }
}
