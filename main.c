// Ramazan ÇİÇEK

// 2420161064

// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=AJaS7nb9vo

#include <stdio.h>

void bubbleSort(int dizi[], int n) {
    int i, j, gecici;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (dizi[j] > dizi[j + 1]) {
                gecici = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = gecici;
            }
        }
    }
}

int binarySearch(int dizi[], int n, int arananSayi) {
    int bas = 0;
    int son = n - 1;
    int orta;

    while (bas <= son) {
        orta = (bas + son) / 2;

        if (dizi[orta] == arananSayi) {
            return orta;
        } else if (dizi[orta] < arananSayi) {
            bas = orta + 1;
        } else {
            son = orta - 1;
        }
    }

    return -1;
}

int main() {
    int dizi[100];
    int elemanSayisi;
    int i;
    int arananSayi;
    int sonuc;

    printf("Dizi eleman sayisini giriniz: ");
    scanf("%d", &elemanSayisi);

    printf("Dizi elemanlarini giriniz:\n");
    for (i = 0; i < elemanSayisi; i++) {
        scanf("%d", &dizi[i]);
    }

    bubbleSort(dizi, elemanSayisi);

    printf("Sirali dizi:\n");
    for (i = 0; i < elemanSayisi; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    printf("Aranacak sayiyi giriniz: ");
    scanf("%d", &arananSayi);

    sonuc = binarySearch(dizi, elemanSayisi, arananSayi);

    if (sonuc != -1) {
        printf("Aranan sayi dizide bulundu. Indeks: %d\n", sonuc);
    } else {
        printf("Aranan sayi dizide bulunamadi.\n");
    }

    return 0;
}
