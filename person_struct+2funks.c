#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_PERSONA 3

struct person {
    char emri [20];
    char mbiemri [20];
    int mosha;
} person[MAX_PERSONA];

int personi_vjeter (struct person p[]){
    int i;
    int max = 0;
    for(i=0; i<MAX_PERSONA; i++){
        if(p[i].mosha > max){
            max = p[i].mosha;
        }
    }
    return max;
}

void emriPerpara(struct person p[]){
    int i;
    for(i=0; i<MAX_PERSONA-1; i++){
        if((strcmp(p[i].emri, p[i+1].emri)) == 1){
            printf("\nEmri %s eshte mbrapa emrit %s", p[i].emri, p[i+1].emri);
        }else if((strcmp(p[i].emri, p[i+1].emri)) == 0){
            printf("\nEmrat %s dhe %s jane njesoj",p[i].emri, p[i+1].emri);
        }else if((strcmp(p[i].emri, p[i+1].emri)) == -1){
            printf("\nEmri %s eshte me perpara se emri %s", p[i].emri, p[i+1].emri);
        }
    }
}

void rendit(struct person p[]){
    int i, j;
    for(i=0; i<MAX_PERSONA-1; i++){
        for(j=i+1; j<MAX_PERSONA; j++){
            if((strcmp(p[i].emri, p[j].emri)) == 1){
                struct person temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
            else if((strcmp(p[i].emri, p[j].emri)) == 0){
                if((strcmp(p[i].mbiemri, p[j].mbiemri)) == 1){
                    struct person temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
            }
            }
}
    }}


struct person printoDhena(struct person person){
    printf("\nEmri: %s", strlwr(person.emri));
    printf("\nMbiemri: %s", strupr(person.mbiemri));
    //printf("\nEmri.Mbiemri: %s", strcpy(p.emri, p.mbiemri));
    printf("\nMosha: %d", person.mosha);
    return person;
}
int shkronja1e_emrit(struct person p[], char shkronje){
int i;
int count=0;
    for(i=0; i<MAX_PERSONA; i++){
        if(tolower(p[i].emri[0])== tolower(shkronje)){
            count++;
        }
    }
    printf("\nNumri i personave qe u fillon emri me '%c' eshte: %d ", shkronje, count);
}

struct person mbiemri_me_i_gjate(struct person p[]){
int i;
int gjatesia=0;
struct person mb_i_gjate=p[0];
for(i=0; i<MAX_PERSONA; i++){
    if(strlen(p[i].mbiemri)>gjatesia){
    gjatesia=strlen(p[i].mbiemri);
    mb_i_gjate=p[i];
    }
}
printf("\nPersoni me mbiemrin me te gjate eshte:");
printf("\nEmri: %s", mb_i_gjate.emri);
printf("\nMbiemri: %s", mb_i_gjate.mbiemri);
printf("\nMosha: %d", mb_i_gjate.mosha);
return mb_i_gjate;
}
int main(){
    int i;
    char shk;
    printf("\nZgjidh nje shkronje me te cilen emri duhet te filloje:");
    scanf("%c", &shk);
    for(i=0; i<MAX_PERSONA; i++){
        printf("Jep emrin e personit: ");
        scanf("%s", &person[i].emri);
        //printf("Jep emrin e personit: ");
        //gets(person[i].emri);
        printf("Jep mbiemrin e personit: ");
        scanf("%s", &person[i].mbiemri);
        printf("Jep moshen e personit: ");
        scanf("%d", &person[i].mosha);
    }

    printf("\nMosha me e madhe: %d", personi_vjeter(person));
    emriPerpara(person);

    shkronja1e_emrit(person, shk);
    struct person max_mbiemri= mbiemri_me_i_gjate(person);
//Thirret funksion qe sjell printimin e te dhenave te personit me mbiemer me te gjate.
    for(i=0; i<MAX_PERSONA; i++){
        printoDhena(person[i]);
    }

return 0;
}
