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
#include <ad9833.c>
#include <ad9833.h>
int tempo = 200;
float MSK, Freq, CLK;
int rst;
float FREQ_REG_MSB,FREQ_REG_lSB,PHASE_REG_MSB,PHASE_REG_lSB,CONTROL_REG,RESET_REG;

void setup()
{
/*
\param SS e rst devem ser habilitados como saida e entrada respectivamente
\param SPI deve ser inicializado através de SPI.begin()
\param ordem de envio dos bits deve ser informada através de SPI.setBitOrder(LSBFIRST)
\param CONTROL_REG e RESET_REG são fixos e podem ser declarados no setup()
*/
  pinMode(SS,OUTPUT);
  pinMode(rst,INPUT);  
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  CONTROL_REG = 0X2100;
  RESET_REG = 0X2000;

  CLk = 18400000;

  Freq= 100000;
}

/*
\subtitle função para calcular a frequencia de saida
\brief retorna o valor decimal a ser programado na saida
\param CLK e Freq são dados de entrada
*/
float FREQ_REG(float CLK,float Freq)
{
  float FR;
  FR = (Freq*pow(2,28))/CLK;
  return FR;
}


 void loop()
{
/*
\param devem ser enviados dados para o DDS na seguinte ordem:
\CONTROL_REG
\FREQ_REGLSB
\FREQ_REGMSB
\PHASE_REG
\RESET_REG
*/


 
}
 
