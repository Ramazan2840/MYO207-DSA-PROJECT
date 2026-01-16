// RAMAZAN ÇİÇEK
// 2420161064
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=AJaS7nb9vo

#include <stdio.h>


void takas(int *ap, int *bp) {
    int gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}


int indis_min_hesapla(int dizi[], int BOYUT, int bas_ind) {
    int i;
    int min_eleman = dizi[bas_ind];
    int min_ind = bas_ind;
    
    for (i = bas_ind + 1; i < BOYUT; i++) {
        if (dizi[i] < min_eleman) {
            min_eleman = dizi[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void secmeli_sirala(int dizi[], int BOYUT) {
    int i; 
    int ind_min; 
    
    for (i = 0; i < BOYUT - 1; i++) { 
        ind_min = indis_min_hesapla(dizi, BOYUT, i);
        takas(dizi + i, dizi + ind_min);
    }
}


int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
    int orta_ind = (ilk_ind + son_ind) / 2;
    
    
    if (ilk_ind > son_ind) {
        return -1;
    }

   
    if (search == dizi[orta_ind]) {
        return orta_ind;
    }
    
    else if (search > dizi[orta_ind]) {
        return ikili_arama(dizi, BOYUT, search, orta_ind + 1, son_ind);
    }
    
    else {
        return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind - 1);
    }
}


void dizi_yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int main() {
   
    int A[] = {64, 25, 12, 22, 11, 90, 45, 33, 7, 18};
    
    
    int N = sizeof(A) / sizeof(A[0]);
    int aranan, sonuc;

    printf("--- MYO207-DSA-PROJECT ---\n");
    
    printf("Siralanmamis Dizi:\n");
    dizi_yazdir(A, N);

   
    secmeli_sirala(A, N);

    printf("Sirali Dizi:\n");
    dizi_yazdir(A, N);

  
    printf("\nAranacak Sayi: ");
    scanf("%d", &aranan);

   
    sonuc = ikili_arama(A, N, aranan, 0, N - 1);

    if (sonuc != -1) {
        printf("Aranan sayi (%d) bulundu. Indis: %d\n", aranan, sonuc);
    } else {
        printf("Aranan sayi (%d) bulunamadi.\n", aranan);
    }

    return 0;
}