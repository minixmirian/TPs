#ifndef MFU_H_INCLUDED
#define MFU_H_INCLUDED


int longestop_mfu(int qpage);/*Fun��o para descobrir a p�gina mais recentemente utilizados atrav�s de seus valores de contagem*/
int pagerep_mfu(int p, int qpage);
void pagefault_mfu(int p, int qpage);
int findpage_mfu(int p, int qpage);

#endif // MFU_H_INCLUDED
