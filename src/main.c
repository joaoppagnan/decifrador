/* Lab 6 - Decifrador da cifra de Vigenere - Joao P. O. Pagnan - 199727 */

/* definicao das biblitecas que iremos utilizar */
#include <stdio.h>
#include <stdlib.h>

/* definicao do tamanho do buffer de entrada */
#define TAM_BUFFER 60

/* definicao das variaveis globais do buffer de entrada e saida */
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

/* senha do decifrador */
const char senha[] = "SENHASECRETA";

/* funcao que decifra um caractere com base na senha */
char decifrar(char a, char b){
  char a0, b0, c0, d0;
  if ((a >= 'A') && (a <= 'Z')){ /* verifica se a entrada faz parte do alfabeto */
    a0 = a - 'A'; /* nos decrementamos a letra A para descobrir a posicao da letra no alfabeto */
    b0 = b - 'A';
    if ((a0 - b0) >= 0 ){ /* se a soma nao for negativa, nao precisa fazer o ajuste */
      c0 = 'A' + (a0 - b0)%(26); /* a operacao de decifracao */
    }
    else { /* aqui, nos vemos que a letra de entrada menos a letra da senha da um caractere fora do alfabeto, para corrigir isso nos pegamos o caractere seguinte ao Z e decrementamos o resultado obtido */
      c0 = 'Z' + 1 - (abs(a0 - b0))%(26);
    }
    return c0; /* retorna o caractere decifrado */
  }
  else return a;
}

/* funcao principal do codigo */
int main(){
  int j = 0;
  int i = 0;

  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);

  /* loop para decifrar cada caractere */
  for (i = 0; (i < TAM_BUFFER) && (buffer_entrada[i] != '\0') && (buffer_entrada[i] != '\n'); i++){
    buffer_saida[i] = decifrar(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j] == '\0'){
      j = 0;
    };
  }
  buffer_saida[i] = '\0';

  /* com a mensagem decifrada, iremos coloca-la na tela */
  printf("%s\n", buffer_saida);
  return 0;
}
