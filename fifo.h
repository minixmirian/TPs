#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

int pagerep_fifo(int p,int qpage); // p�gina a ser substitu�da
void pagefault_fifo(int p, int qpage); // Falta de p�gina
int findpage_fifo(int p, int qpage); // Procura elemento no vetor


#endif // FIFO_H_INCLUDED
