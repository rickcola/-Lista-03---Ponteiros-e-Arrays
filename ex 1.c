// ============================================================
// A diferenca entre os dois codigos esta em O QUE cada instrucao modifica:
//
// Codigo 1: *ptr = *ptr + 1
//   - Altera o VALOR armazenado no endereco apontado.
//   - ptr permanece fixo na posicao 0.
//   - Resultado: o valor na posicao 0 e incrementado 5 vezes, chegando a 15.
//
// Codigo 2: ptr = ptr + 1
//   - Altera o PROPRIO PONTEIRO, fazendo-o avancar pela memoria.
//   - Nenhum valor do array e modificado.
//   - Resultado: ptr termina apontando para o indice 5, cujo valor nunca
//     foi alterado, permanecendo 0 (pois calloc inicializa tudo com zero).
// ============================================================

// Código 1
int  main()
{
   int *ptr, i;
   ptr = (int *) calloc(10, sizeof(int));
   *ptr = 10;
   for(i=0;i<5;i++){
      *ptr=*ptr+1;
   }
   printf("\nptr: %d", *ptr);
   return 0;
}

//Código 2
Código 2
int  main()
{
 int *ptr, i;
 ptr = (int *) calloc(10, sizeof(int));
 *ptr = 10;
 for(i=0;i<5;i++){
    ptr=ptr+1;
 }
 printf("\nptr: %d", *ptr);
 return 0;
}


