#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DECODAGE 1
#define CODAGE 2
#define CLE 3
typedef struct {
    FILE *a1;
    FILE *a2;
    FILE *a3;
} data;
void closefichier(data* in){
    fclose(in->a1);
    fclose(in->a2);
    fclose(in->a3);
}
void genere_cle(data* in){
    int q, code;
    srand(time(NULL));
    while((q = fgetc(in->a1)) != EOF){
        /* nombre aléatoire entre 0 et 255 */
        code = rand()%256;
        fputc(code, in->a2);
    }
}
int open_fichier(char *opt,char* fichier, char* fichier1, char* fichier2, data* in){
    
    in->a1 = fopen(fichier,"r");
    if( in->a1 == NULL){
        printf("Impossible d'ouvrire le premier ficher");
        return -2;
    }
    in->a2 = fopen(fichier1,"e");
    if( in->a2 == NULL){
        printf("Impossible d'ouvrire le deuxième ficher");
        return -2;
    }
    in->a3 = fopen(fichier2,"d");
    if( in->a3 == NULL){
        printf("Impossible d'ouvrire le troisième ficher");
        return -2;
    }
    
    if(strcmp(opt, "-cd")==0){
        return 1;
    }else if(strcmp(opt, "-dc")==0){
        return 0;
    }else if(strcmp(opt, "-cl")==0){
        return 2;
    }else{
        return -1;
    }
}
int main(int argc, char *argv[]) { /*Quand Fopen est exécuté il récupère les informations pour manipuler le fichier */
    
    int b;
    int b2;
    int calcul;
    int setting;
    data *datafile = malloc(sizeof(data)); /*Récupère le nom et l'option du fichier en -cd pour le codage et -dc pour le décodage*/
    if(argc != 5){
        printf("Use: ./vernam -setting f1 f2 f3\n");
        return 1;
    }
    setting = open_fichier(argv[1], argv[2], argv[3], argv[4], datafile); /* si l'option n'existe pas elle renvoie la liste des options*/
    if(setting == -1){
        printf("Voici les options :\n");
        printf("-cd crypte ficher\n");
        printf("-dc decrypte fichier\n");
        printf("-cl genere la cle\n");
        return 1;
    }
    /* cryptage et décryptage */
    while ((b = fgetc(datafile->a1)) != EOF){
        if(setting == CLE){
            genere_cle(datafile);
            return 0;
        }
        b2 = fgetc(datafile->a2);
        if (setting == CODAGE){
            calcul = (b+b2) % 256;
        }else if(setting == DECODAGE){
            calcul = b-b2 >= 0?b-b2:256-(b-b2);
        }
        fputc(calcul, datafile->a3);
    }
    
    
    closefichier(datafile);
    free(datafile);
    return 0;
}