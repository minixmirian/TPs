#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fifo.h"
//FIFO (Fist-In-First-Out)

int full_fifo=0;//Verifica se todos os frames est�o preenchidos
int pagerep_fifo(int p,int qpage){ // page - replaced (rep�e p�gina)
  int temp,repp = 0; // p�gina q derev� ser substituida
	qpage = 0;
	int *frame;
	frame = malloc(qpage*(sizeof(int)));

  temp = frame[repp];
  frame[repp] = p;
  repp++;//O ponteiro se move para o pr�ximo frame desde o frame atual se tornou o mais novo
  if(repp == qpage)
    repp=0;
  return temp;   //retorna p�gina q ser� retirada
  free(frame);
}

void pagefault_fifo(int p, int qpage){
	int frame[qpage];
	if(full_fifo != qpage)
    frame[full_fifo++] = p;//At� que todos os frames estejam cheios, n�o h� pedido de substitui��o de p�gina
  else
		pagerep_fifo(p,qpage);
}

int findpage_fifo(int p, int qpage){//Pesquisar e retornar o flag que indica se a p�gina j� est� presente no frame ou n�o
	int frame[qpage];
	int i,flag;
  flag=0;
  if(full_fifo!=0){
    for(i=0; i<full_fifo; i++)
      if(p == frame[i]){
      	flag=1;
        break;
      }
  }
  return flag;
}
