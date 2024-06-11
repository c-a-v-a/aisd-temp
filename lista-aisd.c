#include <stdio.h>
#include <stdlib.h>

typedef struct el_listy
{
        int klucz;
        struct el_listy *nast;
}LISTA,*LISTAWSK;

int przegladanie(p)
LISTA *p;
{
      int licznik=0;
 while (p != NULL)
 {
       p=p->nast;
       
       if(p!=NULL)
       {
                  licznik++;
                  printf("klucz=%d licznik=%d\n",p->klucz,licznik);
       }          
 }     
 return licznik;
}

void dodaj_za(p,k)
LISTA *p;
int k;
{
      LISTA *pom;
      pom=(LISTAWSK)malloc(sizeof(LISTA));
      pom->klucz=k;
      pom->nast=p->nast;
      p->nast=pom;
} 

void dodaj_przed(p,k)
LISTA *p;
int k;
{
    LISTA *pom;
    pom=(LISTAWSK)malloc(sizeof(LISTA));
    pom->klucz=p->klucz;
    pom->nast=p->nast;
    p->klucz=k;
    p->nast=pom;
}

void usun_nast(p)
LISTA *p;
{
      LISTA *pom;
      if(p->nast!=NULL)
      {
         pom=p->nast;
         p->nast=pom->nast;
      }
      else
      printf("nie ma nastepnego\n"); 
} 

void usun(glowa,p)
LISTA *p, *glowa;

{
    LISTA *pom;
    pom=p->nast;
    if(pom==NULL)
    {
     pom=glowa;
     p=pom->nast;
     while (p->nast != NULL)
      {
         p=p->nast; pom=pom->nast;
      }     
     pom->nast=NULL;
          
    }
    else
    {
      /*
       p->klucz=pom->klucz;
       p->nast=pom->nast;
      */
      *p=*pom; 
    }
}

LISTA *szukaj(p,k)
LISTA *p;
int k;
{
 
 while (p != NULL)
 {
        
        if(p->nast==NULL) return NULL;
        else
        {
             p=p->nast; //printf("---%d\n",p->klucz);
        if(p->klucz==k)return p;
        }
 }  
 return NULL;   
}


int liczrek(p)
LISTA *p;
{
 //printf("%d\n",p->klucz);
 if (p->nast==NULL) return 0;
 else
     {
     return 1+liczrek(p->nast);
     }
 
      
}


void przeglrewrek(p)
LISTA *p;
{
 
   if (p != NULL) 
   {
      przeglrewrek(p->nast);
      printf("%d  \n",p->klucz); 
   }     
 }
 void przeglrek(p)
LISTA *p;
{
 
   if (p != NULL) 
   {
      printf("%d  \n",p->klucz);
      przeglrek(p->nast); 
   }     
 }
 
 
 int maxrek(p)
 LISTA *p;
 {
       int max;
       if(p==NULL)
          return 0;
       if (p->nast== NULL)
           return p->klucz;
       
       max=maxrek(p->nast);
       if (p->klucz> max)
          return p->klucz;
       else 
          return max; 
  }


 
 LISTAWSK odwroc(p)
 LISTA *p;
 {
 LISTAWSK w3, w2=p, w1=NULL;
 while(w2!=NULL)
       {  w3 = w2->nast; w2->nast=w1; w1=w2; w2=w3;}   
 return w1;     
 }
 
 void zamien(int x, int y, LISTA* glowa) {
     //znajdz element o kluczu x w posortowanej malejaco liscie i zamien go na y z zachowaniem kolejnosci
     LISTA* el;
     LISTA* pom = glowa;

     while (pom->nast) {
         if (pom->nast->klucz <= y) {
             el->nast = pom->nast;
             pom->nast = el;
             return;
         }

         pom = pom->nast;
     }

     pom->nast = el;
     el->nast = NULL;
}
  
 
 int usunx(LISTA *p, int x)
 //usun element o kluczu x z listy posortowanej rosn¹co
 {
     LISTA* pom;

     while (p->nast) {
         if (p->nast->klucz == x) {
             pom = p->nast;
             p->nast = pom->nast;
             free(pom);
             return x;
         }

         if (p->nast->klucz > x) break;

         p = p->nast;
     }

     return -1;
}    
 
 
 int usun2x(LISTA *p, int x)
 //usun element o kluczu x z listy posortowanej malejaco
 {
     LISTA* pom;

     while (p->nast) {
         if (p->nast->klucz == x) {
             pom = p->nast;
             p->nast = pom->nast;
             free(pom);
             return x;
         }

         if (p->nast->klucz < x) break;

         p = p->nast;
     }

     return -1;
 }
 
 
 void dodaj_sort(int x, LISTA * g){
 	//dodaj elemet o kluczu x do listy posortowanej rosn¹co z zachowaniem kolejnosci
     LISTA* pom = (LISTAWSK)malloc(sizeof(LISTA));
     pom->klucz = x;

     while (g->nast) {
         if (g->nast->klucz >= x) {
             pom->nast = g->nast;
             g->nast = pom;
             return;
         }
         g = g->nast;
     }

     g->nast = pom;
     pom->nast = NULL;
 }
 
int main(int argc, char *argv[])
{
  int k, k2;
  LISTA *glowa,*ost,*znal; 
  LISTA *pom;
  glowa=NULL;
  pom=(LISTA *)malloc(sizeof(LISTA));
  pom->klucz=0;
  pom->nast=NULL;
  glowa=pom;
  printf("podaj klucz kolejnego elementu listy 0 - koniec:\n");
  scanf("%d",&k);
  ost=glowa;
  while (k)
   {
    dodaj_za(ost, k);
    ost=ost->nast;
    printf("podaj klucz kolejnego elementu listy 0 - koniec listy:\n");
    scanf("%d",&k);
  }
  printf("przegladanie listy:  - %d\n", przegladanie(glowa));
  printf("dlugosc listy=%d\n",liczrek(glowa));

  printf("Do dodania: ");
  scanf("%d", &k);
  dodaj_sort(k, glowa);
  przegladanie(glowa);

  printf("Do usuniecia (usunx): ");
  scanf("%d", &k);
  usunx(glowa, k);
  przegladanie(glowa);

  printf("Odwracamy\n");
  glowa->nast=odwroc(glowa->nast);
  przegladanie(glowa);

  printf("Do zamiany (x y):");
  scanf("%d %d", &k, &k2);
  zamien(k, k2, glowa);
  przegladanie(glowa);

  printf("Do usuniecia (usun2x): ");
  scanf("%d", &k);
  usun2x(glowa, k);
  przegladanie(glowa);

    return 0;
}
