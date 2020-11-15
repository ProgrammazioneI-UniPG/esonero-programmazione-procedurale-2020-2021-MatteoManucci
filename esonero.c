#include <stdio.h>   // --Librerie Aggiunte
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (void) {

time_t t;
char mastertext[128];    // (M)
char ritorno[128];       // (M) dopo lo xor
char manual[128];        // (k)
char random[128];        // (k) randomico
char testoCifrato[128];  // (C)
char dio[128];
char scelta;
char decodifica;
char c;
int xor;

printf("Inserire La Stringa Principale [Max 128 Caratteri]: \n");
fgets(mastertext, 128, stdin);

printf("\nStringa Principale: %s \n", mastertext);

printf("Lunghezza della Stringa Principale = %lu \nPremere INVIO per Continuare", strlen(mastertext));

// --Getchar per Ripulire la Stringa strlen(mastertext)
while((c= getchar()) != '\n' && c != EOF);

// --Scelta Inserimento Chiave di Codifica
printf("\nScegliere il Metodo di Inserimento della Chiave di Codifica \n[1-Manualmente, 2-Automaticamente]: ");
scanf("%s", &scelta);

// --49 - 50 corrispondono a 1 - 2 in char
while (scelta != 49 && scelta !=50) {
  printf("\nLe Scelte Sono Solo Due [1-Manualmente, 2-Automaticamente], \nQuale Preferisci: ");
  scanf("%s", &scelta);
}
// --Getchar per Ripulire la Stringa strlen(manual)
while((c= getchar()) != '\n' && c != EOF);

// --If per Rendere Le Scelte Possibili Solamente 1 e 2
if (scelta == 49) {

  printf("\nInserire La Chiave di Codifica: \n");
  fgets(manual, 128, stdin);

//-- Comparazione per evitare che la Chiave di codifica venga più corta della Stringa Principale
  while (strlen(manual) < strlen(mastertext)){

    printf("\nLa Chiave di Codifica è Troppo Corta, Inserire una Chiave di Codifica Valida: \n");
    fgets(manual, 128, stdin);
  }

  printf("\nChiave di Codifica: %s \n", manual);
  printf("Lunghezza della Chiave di Codifica = %lu \n", strlen(manual));

  for ( int xor = 0 ; xor < strlen(mastertext) ; xor++ ){
      testoCifrato[xor] = mastertext[xor] ^ manual[xor];
      ritorno[xor] = testoCifrato[xor] ^ manual[xor];
      }
  printf("\nLa Stringa Codificata E': %s\n ", testoCifrato);

  printf("\n\nPremere INVIO per Continuare");
  while((c= getchar()) != '\n' && c != EOF);


// --Scelta Inserimento Chiave di Codifica
  printf("\nDesidera Ritornare alla Stringa Principale ?\n[0-Si, 1-No]: ");
  scanf("%s", &decodifica);

      // --48 - 49 corrispondono a 0 - 1 in char
  while (decodifica != 48 && decodifica !=49) {
  printf("\nLe Scelte Sono Solo Due [0-Si, 1-No], \nQuale Preferisci: ");
  scanf("%s", &decodifica);
 }
  if (decodifica == 48){
    printf("\nLa Stringa Principale E': \n%s", ritorno);
   } else if (decodifica == 49){
    printf("\nArrivederci!\n");
 }
}
else if (scelta == 50 ) {

// --Creazione Randomica di Caratteri
  srand((unsigned) time(&t));
  for ( xor = 0 ; xor < strlen(mastertext) ; xor++ ){
  random[xor] = rand() % 96 +32;  // -Rimozione Caratteri Speciali
  }
  printf("\nLa Chiave di Codifica Generata Automaticamente E': %s", random);
  printf("\n");

  for ( int xor = 0 ; xor < strlen(mastertext) ; xor++ ){
      testoCifrato[xor] = mastertext[xor] ^ random[xor];
      ritorno[xor] = testoCifrato[xor] ^ random[xor];
      }
  printf("\nLa Stringa Codificata E': %s ", testoCifrato);

  printf("\n\nPremere INVIO per Continuare");
  while((c= getchar()) != '\n' && c != EOF);

// --Scelta Inserimento Chiave di Codifica
  printf("\nDesidera Ritornare alla Stringa Principale ?\n[0-Si, 1-No]: ");
  scanf("%s", &decodifica);

      // --48 - 49 corrispondono a 0 - 1 in char
  while (decodifica != 48 && decodifica !=49) {
  printf("\nLe Scelte Sono Solo Due [0-Si, 1-No], \nQuale Preferisci: ");
  scanf("%s", &decodifica);
 }
  if (decodifica == 48){
    printf("\nLa Stringa Principale E': \n%s", ritorno);
   } else if (decodifica == 49){
    printf("\nArrivederci!\n");
 }
}


//Fine
}
