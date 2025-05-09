#include <stdio.h>
#include <stdlib.h>

//function prototypes
int fileControl();
void fileCreate();
void fileRead();
void fileWrite();
void fileRemove();

char filename[20] = "output.txt";

int main()
{
    int choise;

    printf("Dosya ismini giriniz: ");
    scanf("%s", filename);

    while (1)
    {
        printf("\n---DOSYA YONETIMI---\n");
        printf("1. Dosya kontrol et\n");
        printf("2. Dosya olustur\n");
        printf("3. Dosyaya yaz\n");
        printf("4. Dosyadan oku\n");
        printf("5. Dosyayi sil\n");
        printf("6. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choise);

        switch (choise)
        {
            case 1:
                fileControl();
                break;
            case 2:
                fileCreate();
                break;
            case 3:
                fileWrite();
                break;
            case 4:
                fileRead();
                break;
            case 5:
                fileRemove();
                break;
            case 6:
                exit(0);
            default:
                printf("Gecersiz secim!\n");
        }
    }
}

int fileControl()
{
    FILE *file;
    file = fopen(filename, "r");
    if (file)
    {
        printf("Dosya mevcut.\n");
        fclose(file);
        return 1;
    }
    else
    {
        printf("Dosya mevcut degil.\n");
        return 0;
    }
}

void fileCreate()
{
    FILE *file;
    file = fopen(filename, "w");
    if (file)
    {
        printf("Dosya olusturuldu.\n");
        fclose(file);
    }
    else
    {
        printf("Dosya olusturulurken hata meydana geldi.\n");
    }
}

void fileRead()
{
    FILE *file;
    file = fopen(filename, "r");
    if (file)
    {
        char line[100];
        printf("Dosya icerigi:\n");
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
        }
        fclose(file);
    }
    else
    {
        printf("Dosya mevcut degil.\n");
    }
}

void fileWrite()
{
    FILE *file;
    file = fopen(filename, "a");
    if (file)
    {
        char text[100];
        printf("Yazmak istediginiz metni girin: ");
        scanf(" %[^\n]", text);
        fprintf(file, "%s\n", text);
        fclose(file);
        printf("Dosyaya yazildi.\n");
    }
    else
    {
        printf("Dosya acilamadi.\n");
    }
}

void fileRemove()
{
    if (remove(filename) == 0)
    {
        printf("Dosya silindi.\n");
    }
    else
    {
        printf("Dosya silinemedi.\n");
    }
}
