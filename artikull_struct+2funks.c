#include <stdio.h>
#define GJAT_EMER 25
#define MAX_ARTIKULL 100

struct artikull {
    int numri;
    char emri [GJAT_EMER +1];
    int gjendja;
} inventari[MAX_ARTIKULL];

//int inventari[MAX_ARTIKULL];

int nr_artikull = 0;
int gjej_artikull (int numer);
void shto (void);
void kerko (void);
void update (void);
void printo (void);
int lexo_rresht (char str [], int n);
/* main: i kerkon perdoruesit te jape nje kod veprimi, dhe pastaj
therret funksionin perkates te kryeje veprimin e kerkuar.
Kjo gje perseritet deri sa perdoruesi te jape 'q'. Nese
perdoruesi jep nje kod te gabuar printohet nje mesazh gabimi*/
int main ()
{
    char kodi;

    for (;;) {

        printf("\nZgjidh nje veprim:\n");
        printf("s - Shto artikull\n");
        printf("k - Kerko artikull\n");
        printf("u - Update gjendjen e artikullit\n");
        printf("p - Printo inventarin\n");
        printf("q - Dil nga programi\n");
        printf("g - Gjej numrin e artikujve me gjendje te ndryshme nga 0\n");
        printf("f - Artikull me kod numer njeshifror\n");
        printf("Fut kodin e veprimit: ");
//Printo nje menu per perdoruesin

        scanf(" %c", &kodi);
        while (getchar() != '\n') /* kalon deri te fundi i rreshtit */
        ;
        switch (kodi) {
            case 's': shto();
            break;
            case 'k': kerko();
            break;
            case 'u': update();
            break;
            case 'p': printo();
            break;
            case 'g': numer_gjendje(inventari);
            break;
            case 'f': nr_njeshifror(inventari,nr_artikull);
            break;
            case 'q': return 0; //exit
            default: printf("Kod i gabuar\n");
        }
        printf("\n");
    }
}
/* Funksioni gjej_artikull kerkon ne matricen inventari artikull me
variablin numri sa vlera qe merr si argument. Kthen indeksin e
matrices nese gjen nje artikull me nje numer te tille, ne te
kundert kthen -1
*/
int gjej_artikull(int numri)
{
    int i;
    for (i = 0; i < nr_artikull; i++)
        if (inventari[i].numri == numri)
            return i;
    return -1;
}
/* Funksioni shto, i kerkon perdoruesit informacion per nje artikull te
ri dhe me pas e shton artikullin ne databaze. Kthen nje mesazh gabimi
nese artikulli egzistonte qe me pare ose nese databaza eshte plot */
void shto(void)
{
    int artikull_nr;
    if (nr_artikull == MAX_ARTIKULL)
    {
        printf("Databaza eshte plot; nuk mund te shtohet artikull.\n");
        return;
    }
    printf("Fut numrin e artikullit: ");
    scanf("%d", &artikull_nr);
    if (gjej_artikull(artikull_nr) >= 0)
    {
        printf("Artikulli egziston.\n");
        return;
    }

    inventari[nr_artikull].numri = artikull_nr;
    printf("Jep emrin e artikullit: ");
    scanf("%s", &inventari[nr_artikull].emri);
    printf("Jep gjendjen e artikullit: ");
    scanf("%d", &inventari[nr_artikull].gjendja);
    nr_artikull++;
}
/* Funksioni kerko i kerkon perdoruesit te jap nje numer artikulli,
pastaj kerkon ne databaze, nese artikulli me kete numer egziston kthen
emrin dhe gjendjen e artikullit, ne te kundert printon nje mesazh
gabimi. */
void kerko(void)
{
    int i, numer;
    printf("Jep numrin e artikullit: ");
    scanf("%d", &numer);
    i = gjej_artikull(numer);
    if (i >= 0)
    {
        printf("Emri i artikullit: %s\n", inventari[i].emri);
        printf("Gjendja e artikullit: %d\n", inventari[i].gjendja);
    } else
        printf("Artikulli nuk u gjet.\n");
}
/* Funksioni update i kerkon perdoruesit te jape nje numer artikulli.
Kthen nje mesazh gabimi nese artikulli nuk egziston; ne te kundert
i kerkon perdoruesit te jape ndryshimin ne gjendje te artikullit
dhe i ben update. */
void update(void)
{
    int i, numer, ndryshimi;
    printf("Jep numrin e artikullit: ");
    scanf("%d", &numer);
    i = gjej_artikull(numer);
    if (i >= 0)
    {
        printf("Jep ndryshimin ne gjendje te artikullit: ");
        scanf("%d", &ndryshimi);
        inventari[i].gjendja += ndryshimi;
    } else
        printf("Artikulli nuk u gjet.\n");
}
/* Funksioni printo, printon gjithe artikujt ne databaze, duke dhene
numrin, emrin dhe gjendjen e artikullit. Artikujt printohen me ate
renditje qe jane futur ne databaze. */
void printo(void)
{
    int i;
    printf("Numri i Artikullit Emri i Artikullit "
    "Gjendja e Artikullit\n");
    for (i = 0; i < nr_artikull; i++)
        printf("%7d %25s %25d\n", inventari[i].numri, inventari[i].emri, inventari[i].gjendja);
}
int numer_gjendje(struct artikull inventari[]){
int count=0;
int i;
    for (i = 0; i < nr_artikull; i++){
        if (inventari[i].gjendja !=0 ){
            count++;
        }
}
printf("Numri i artikujve me gjendje te ndryshme nga 0 eshte:%d", count);
return count;
}
void nr_njeshifror(struct artikull inventari[], int nr_artikull){
int i;
struct artikull artikull_njeshifror;
for (i = 0; i < nr_artikull; i++){
        if (inventari[i].numri>=0 && inventari[i].numri<=9 ){
            printf("\nArtikulli ka kod me vetëm nje numer dhe emri i tij eshte:\n");
            printf("%7d %25s %25d\n", inventari[i].numri, inventari[i].emri, inventari[i].gjendja);
            artikull_njeshifror = inventari[i];
        }
}
}
