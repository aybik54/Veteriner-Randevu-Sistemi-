#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void randevumenu();
void randevulariyukle();
void randevukaydet();

char hayvanlar[50][20];
char rahatsizliklar[50][30];
int randevusayisi = 0;

int main()
{
    FILE *dosya;
    int secim;
    char kullanici[20], sifre[20];
    char dUser[20], dSifre[20];
    int girisbasarili = 0;

    randevulariyukle();

    printf("Veteriner Randevu Sistemine Hos Geldiniz\n");
    printf("1-Uye Ol(Uye degilseniz )\n");
    printf("2-Giris Yap\n");
    printf("Secim: ");
    scanf("%d",&secim);

    if(secim==1)
    {
        dosya=fopen("kullanicilar.txt","a");
        if (!dosya){ 
		printf("Dosya acilamadi!\n"); return 0;
		 }

        printf("Kullanici adi: ");
        scanf("%s", kullanici);
        printf("Sifre: ");
        scanf("%s", sifre);

        fprintf(dosya,"%s %s\n",kullanici,sifre);
        fclose(dosya);

        printf("Uyelik olusturuldu. Lutfen giris yapiniz.\n");
    }
    printf("Kullanici adi: ");
    scanf("%s",kullanici);
    printf("Sifre: ");
    scanf("%s",sifre);

    dosya = fopen("kullanicilar.txt", "r");
    if (!dosya) { printf("Kullanici dosyasi bulunamadi!\n");return 0; }

    while(fscanf(dosya,"%s %s",dUser,dSifre)!=EOF)
    {
        if(strcmp(kullanici,dUser)==0&&strcmp(sifre,dSifre)==0)
        {
            girisbasarili=1;
            break;
        }
    }
    fclose(dosya);

    if (girisbasarili)
    {
        printf("Giris basarili!\n");
        randevumenu();
    }
    else
    {
        printf("Hatali giris!\n");
    }
    return 0;
}
        void randevumenu()
{
    int secim, i;

    do
    {
        printf("\n--- RANDEVU MENUSU ---\n");
        printf("1-Randevu Al\n");
        printf("2-Randevulari Listele\n");
        printf("3-Cikis\n");
        printf("Secim: ");
        scanf(" %d",&secim);

        if(secim==1)
{
    printf("Hayvan turu: ");
    scanf(" %[^\n]",hayvanlar[randevusayisi]); 

    printf("Rahatsizlik: ");
    scanf(" %[^\n]",rahatsizliklar[randevusayisi]);

    randevukaydet();
    randevusayisi++;

    printf("\nRandevu basariyla kaydedildi.\n");
}
        else if (secim==2)
        {
            printf("\n--- RANDEVU LISTESI ---\n");
            if (randevusayisi == 0)
            {
                printf("Randevu bulunamadi.\n");
            }
            for(i=0;i<randevusayisi;i++)
            {
                printf("%d)%s-%s\n",
                       i + 1,
                       hayvanlar[i],
                       rahatsizliklar[i]);
            }
            printf("Devam etmek icin ENTER'a basin...");
            getchar();
            getchar();
        }

    } while (secim != 3);

    printf("Cikis yapildi.\n");
}
 
        void randevukaydet()
{
    FILE *dosya=fopen("randevular.txt", "a");
    if(!dosya)return;

    fprintf(dosya, "%s %s\n",
            hayvanlar[randevusayisi],
            rahatsizliklar[randevusayisi]);
    fclose(dosya);
}
        void randevulariyukle()
{
    FILE*dosya=fopen("randevular.txt", "r");
    if(!dosya)return;

    while(fscanf(dosya,"%s %s",
                  hayvanlar[randevusayisi],
                  rahatsizliklar[randevusayisi])!=EOF)
    {
        randevusayisi++;
    }
    fclose(dosya);
}

