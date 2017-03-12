#include <stdio.h>
#include <math.h>
/*Sam Stone
This is a sample program that evaluates possible sensor values
and returns the relative position of the line
*/
int EdThres = 34;
int ExThres = 10;
int diffThres = 10;

int absDiff(int n1, int n2){
	return abs(n1-n2);
}
char * direction(int r,int l,int c){
	static char q ='x';
	q='x';

	//The magnitudes of differences
	int Mlvc = absDiff(r,c);
	int Mlvr = absDiff(l,c);
	int Mcvr = absDiff(r,l);

	//the signed differences
	int lvc = c-l;
	int lvr = r-l; // + ~> r>l | - ~> l>r
	int cvr = c-r;

	//Expected Values (Average)
	int Ex = (r+c+l)/3;
	int Ed = (Mlvr+Mlvc+Mcvr)/3;

	//Variences
	int Vx = (r*r+c*c+l*l)/3 -Ex*Ex;
	int Vd = (Mlvr*Mlvr+Mlvc*Mlvc+Mcvr*Mcvr)/3-Ed*Ed;
	Vx = sqrt(Vx);
	Vd = sqrt(Vd);

	printf("MLvC:%d MLvR:%d MCvR:%d\n", lvc, lvr, cvr);
	printf("Ex:%d Ed:%d Vx:%d Vd:%d\n", Ex, Ed, Vx, Vd);
	//different conditions
	//values are close
	if(Ed < EdThres){
		//No Line Detected
		if(Ex < ExThres){
			q = 'n';
			return &q;
		}
		//At the startline
		else {
			q = 's';
			return &q;
		}
	}
	else {

	}

		return &q;

}
int main(){
	int r,c,l,n;
	char * result;
	scanf("%d\n", &n); //collects the number of lines
	int i;
	for(i=0; i<n; i++){
		scanf("%d %d %d\n", &l, &c, &r);
		printf("Inputs:%d %d %d\n", l, c, r);
		printf("Dir:%s\n",direction(r,l,c));
		printf("\n");
	}
	return 0;
}