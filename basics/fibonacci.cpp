#include <iostream>
#include <vector>
using namespace std;
double nOp = 0;
double naiveFib(double n)
{
	nOp++;
	if(n <= 2)
		return 1;
	return naiveFib(n-1) + naiveFib(n-2);
}


double fibTopDownRec(int n, double *vet)
{
	nOp++;
	if(vet[n-1] == 0)
		vet[n-1] = fibTopDownRec(n-1, vet) + fibTopDownRec(n-2, vet);
	return vet[n-1];
}

double fibTopDown (int n)
{
	nOp++;
	vector<double> vet;
	vet.resize(n);
	vet[1] = vet[0] = 1;
	//nesse caso precisamos passar o vet.data pois queremos o conceito de ponteiros
	return fibTopDownRec(n,vet.data());	
}
double fibBottomUp(int n)
{
	vector<double> vet;
	vet.resize(n);
	vet[1] = vet[0] = 1;
	for(int i = 2; i < n; i += 1)
	{	
		nOp++;
		vet[i] = vet[i-1] + vet[i-2];
	}
	return vet[n-1];	
}
int main()
{
	double ret = fibTopDown(45);
	printf("TopDown: %.0lf\tops: %.0lf\n", ret, nOp);
	nOp=0;
	ret = fibBottomUp(45);
	printf("BottomUp: %.0lf\tops: %.0lf\n", ret, nOp);
	nOp=0;
	ret = naiveFib(45);
	printf("Ingenuo: %.0lf\tops: %.0lf\n", ret,nOp);
	return 0;
}
