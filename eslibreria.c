    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX_CATEGORIE 20
    typedef struct Libro
    {
        char Autore[30];
        char Titolo[40];
        char Categoria[40];
        int anno;
        float prezzo;
    } Libro;
    typedef struct Categoria
    {
        char nomeCategoria[40];
        Libro libri[40];
        int contatore;
    } Categoria;
    Categoria libreria[30];
    int categorieEsitenti = 0;
    int Menu()
    {
        int scelta;
        printf("\n-----------------------------------\n");
        printf("1) Inserisci libro\n");
        printf("2) Visualizza libri\n");
        printf("3) Visualizza categoria\n");
        printf("4) Cerca titolo\n");
        printf("0) Esci\n");
        printf("-----------------------------------\n");
        printf("Inserisci una scelta:\n");
        scanf("%d", &scelta);
        return scelta;
    }

    void Visualizza()
    {
        printf("========LIBRERIA======== \n");
        for (int i = 0; i < categorieEsitenti; i++)
        {
            printf("\n Categoria: %s \n \n", libreria[i].nomeCategoria);
            for (int j = 0; j < libreria[i].contatore; j++)
            {
                printf("\n Nome:%s   Autore:%s    Anno:%d    Categoria:%s    Prezzo:%2.f \n", libreria[i].libri[j].Titolo, libreria[i].libri[j].Autore, libreria[i].libri[j].anno, libreria[i].libri[j].Categoria, libreria[i].libri[j].prezzo);
            }
        }
    }
    int CercaCategoria(char incognita[])
    {

        for (int i = 0; i < categorieEsitenti; i++)
        {
            if (strcmp(libreria[i].nomeCategoria, incognita) == 0)
            {
                return i;
            }
        }
        return -1;
    }
    void VisualizzaCategoria(){
        char ricerca[40];
        printf("Inserisci il nome della categoria che vuoi vedere \n");
        scanf("%s",ricerca);
        int categoria=CercaCategoria(ricerca);
        if (categoria!=-1)
        {
            for (int i = 0; i < libreria[categoria].contatore; i++)
            {
                printf("\n Nome:%s   Autore:%s    Anno:%d    Categoria:%s    Prezzo:%f \n", libreria[categoria].libri[i].Titolo, libreria[categoria].libri[i].Autore, libreria[categoria].libri[i].anno, libreria[categoria].libri[i].Categoria,libreria[categoria].libri[i].prezzo);
            }
        }else{
            printf("Categoria inserita non esistente \n");
        }
        
    }
    void CercaTitolo(){
        char titolo[30];
        printf("inserire titolo\n");
        scanf("%s",titolo);
        for (int i = 0; i < categorieEsitenti; i++)
        {
            for (int j = 0; j < libreria[i].contatore; i++)
            {
                if (strcmp(libreria[i].libri[j].Titolo,titolo)==0)
                {
                    printf("\n Nome:%s   Autore:%s    Anno:%d    Categoria:%s    Prezzo:%f \n", libreria[i].libri[j].Titolo, libreria[i].libri[j].Autore, libreria[i].libri[j].anno, libreria[i].libri[j].Categoria, libreria[i].libri[j].prezzo);
                }
                
            }
            
        }
        
    }
    void LetturaLibri(const char *nomeFile)
    {
        Libro librilettura[50];
        int n = 0;
        FILE *fLibri = fopen("libri.csv", "r");
        if (fLibri == NULL)
        {
            printf("Errore apertura file!\n");
            exit(1);
        }
        while (!feof(fLibri))
        {
            Libro libro;
            fscanf(fLibri, "%s,%s,%d,%f,%s\n", libro.Titolo, libro.Autore, &libro.anno, &libro.prezzo, libro.Categoria);
            librilettura[n] = libro;
            n++;
        }
        fclose(fLibri);
        printf("\n \n");
        int controlloCat = 0;
        for (int i = 0; i < n; i++)
        {
            controlloCat = CercaCategoria(librilettura[i].Categoria);
            if (controlloCat != -1)
            {
                libreria[controlloCat].libri[libreria[controlloCat].contatore] = librilettura[i];
                libreria[controlloCat].contatore++;
            }
            else
            {
                strcpy(libreria[categorieEsitenti].nomeCategoria, librilettura[i].Categoria);
                libreria[categorieEsitenti].libri[libreria[categorieEsitenti].contatore] = librilettura[i];
                libreria[categorieEsitenti].contatore++;
                categorieEsitenti++;
            }
        }
    }
    void Inserisci()
    {
        Libro inserimento;
        printf("inserisci la categoria del libro \n");
        scanf("%s", inserimento.Categoria);
        printf("inserisci l'autore del libro \n");
        scanf("%s", inserimento.Autore);
        printf("inserisci il titolo del libro \n");
        scanf("%s", inserimento.Titolo);
        printf("inserisci l'anno del libro \n");
        scanf("%d", &inserimento.anno);
        printf("inserisci il prezzo del libro \n");
        scanf("%f", &inserimento.prezzo);
        int pos = CercaCategoria(inserimento.Categoria);
        if (pos != -1)
        {
            libreria[pos].libri[libreria[pos].contatore] = inserimento;
            libreria[pos].contatore++;
        }
        else
        {
            if (categorieEsitenti < MAX_CATEGORIE)
            {
                strcpy(libreria[categorieEsitenti].nomeCategoria, inserimento.Categoria);
                libreria[categorieEsitenti].libri[libreria[categorieEsitenti].contatore] = inserimento;
                libreria[categorieEsitenti].contatore++;
                categorieEsitenti++;
            }else
            {
                printf("Ci dispiace ma abbiamo raggiunto il numero massimo di categorie \n");
            }
        }
    }
    void Scelta(int scelta)
    {
        switch (scelta)
        {
        case 1:
            Inserisci();
            break;
        case 2:
            Visualizza();
            break;
        case 3:
            VisualizzaCategoria();
            break;
        case 4:
            break;
        }
    }

    int main(int argc, char *argv[])
    {
        const char *filename = "libri.csv";
        LetturaLibri( filename);
        int risultato;
        do
        {
            risultato = Menu();
            if (risultato != 0)
            {
                Scelta(risultato);
            }
            else
            {
                break;
            }

        } while (1);
        return 0;
    }