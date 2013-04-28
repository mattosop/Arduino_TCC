/*
\title projeto de sistema de programação para AD9833/34
\auctor Carlos Augusto M. Pereira
\date 25/04/2013
\brief após teste passar como função para o módulo de programação principal
\brief deve ser executado sempre que energizado o sistema.
*/
/*
\brief deve ser  incluida a biblioteca SPI para utilizar o barramento SPI
\param MSK frequencia de programação
\param Freq frequencia de saida
\param CLK clock do sistema
\param devem ser programadas as palavras de controle: FREQ_REG_MSB,FREQ_REG_lSB,PHASE_REG_MSB,PHASE_REG_lSB,CONTROL_REG,RESET_REG
\param rst tecla para habilitar a programação
*/
#include <SPI.h>
int tempo = 200;
float MSK, Freq, CLK;
int rst;
long float FREQ_REG_MSB,FREQ_REG_lSB,PHASE_REG_MSB,PHASE_REG_lSB,CONTROL_REG,RESET_REG;

void setup()
{
/*
\param SS e rst devem ser habilitados como saida e entrada respectivamente
\param SPI deve ser inicializado através de SPI.begin()
\param ordem de envio dos bits deve ser informada através de SPI.setBitOrder(LSBFIRST)
\param CONTROL_REG e RESET_REG são fixos e podem ser declarados no setup()
*/
  pinMode(SS,OUTPUT);
  pinMode(rst,IN);  
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  CONTOL_REG = 0X2100;
  RESET_REG = 0X2000;
}

/*
\subtitle função para calcular a frequencia de saida
\brief retorna o valor decimal a ser programado na saida
\param CLK e Freq são dados de entrada
*/
float FREQ_REG(float CLK,float Freq)
{
  float FR;
  FR = (freq*pow(2,28))/CLK;
  return FR;
}

/*
\subtitle Função para dividir em palavras de dois BYTES
\param NUMERO é a variavel de entrada
\param 2bytes é o vetor contendo os dois bytes
*/
int* divide2byte(long float NUMERO)
{
  float BYTE1, BYTE2;
  FR = (freq*pow(2,28))/CLK;
  if FR <16384)//confirma que os numeros sejam menores que o limite
  {
    BYTE2 = 0;
    BYTE1 = FR;
  }
  else
  /*
  /ocorreu estouro deve ser utilizado outros dois bytes
  */
  return 2byte;
}
/*
\subtitle Função para concatenar bytes
\brief Esta função permite alterar os bits 15 e 14 das palavras FRE_REG_MSB e FREQ_REG_LSB
\param 
*/
int * concatena(valor);
{
  int* vet, i, teste;
  for (i=0;i<2;i++)
  {
    vet[i] = concatena[i]
  }
  
