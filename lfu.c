#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//LFU (Last Frequently Use)

int full_lfu=0;//Verifica se todos os frames est�o preenchidos
int longestop_lfu(int qpage){//entrada pagina referenciada, qntd de p�ginas, acessos
	int min,repp,i,ctr[qpage];
	min = 0;
  for(i=0; i< qpage; i++) // a p�gina com menos frequencia eh selecionada para sair
		if(ctr[min]>ctr[i])
			min=i;
			repp = min;
			return repp;
}

int pagerep_lfu(int p,int qpage) { // page - replaced (rep�e p�gina)
  int temp = 0,repp = 0; // p�gina q derev� ser substituida

	repp = longestop_lfu(qpage); // p�gina q ir� sair selecionada. Fun��o para auxiliar na reposi��o.
  int *frame;
  frame = malloc(qpage*(sizeof(int)));
  int *ctr;
  ctr = malloc(qpage*(sizeof(int)));

  temp = frame[repp];
  frame[repp] = p;
  ctr[repp] = 1;//Uma nova p�gina ser� trazida,contador � definido como 1

  return temp;   //retorna p�gina q ser� retirada
  free(frame);
  free(ctr);
}

void pagefault_lfu(int p, int qpage) {
	qpage= 0;
  int *frame, ctr[qpage];

  frame = malloc(qpage*(sizeof(int)));
  if(full_lfu != qpage){
    ctr[full_lfu]++;
		frame[full_lfu++] = p;//At� que todos os frames estejam cheios, n�o h� pedido de substitui��o de p�gina
  }else{ pagerep_lfu(p,qpage);}
}

int findpage_lfu(int p, int qpage) { //Pesquisar e retornar o flag que indica se a p�gina j� est� presente no frame ou n�o
  int frame[qpage], ctr[qpage];
  int i,flag=0;

  if(full_lfu!=0) {
    for(i=0; i<full_lfu; i++)
      if(p == frame[i]) {
        flag=1;
        ctr[i]++; // sempre que � feita uma refer�ncia ao contador � incrementado
        break;
      }
  }
  return flag;
}

int loc_espacial(int p,int qpage){
	if (findpage_lfu(p,qpage))
		return 0;
	else if (findpage_lfu(p,qpage) != 1)
		return -1;
	else
		return longestop_lfu(qpage);
}
