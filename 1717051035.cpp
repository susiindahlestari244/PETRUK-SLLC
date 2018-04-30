#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main () {
	int n=3;
	int A[n][n]={{2,4,8},
				 {0,0,3},
				 {9,6,2}};
	
	cout<<"Matriks A :\n";
	for (int b=0;b<3;b++){
		for (int k=0;k<3;k++){
			cout<<A[b][k]<<" ";
		}cout<<endl;
	}
	
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
		cout<<"Minor Matriks A :["<<i<<"]["<<j<<"]:\n";
		for (int k=0;k<3;k++){
			for (int l=0;l<3;l++){
				if (k!=i && l!=j)
				cout<<A[k][l]<<" ";
			}cout<<endl;
		}
		}cout<<endl;
	}

	int min[3][3];
	min[0][0]= A[1][1]*A[2][2]-A[2][1]*A[1][2];
	min[0][1]= A[1][0]*A[2][2]-A[2][0]*A[1][2];
	min[0][2]= A[1][0]*A[2][1]-A[1][1]*A[2][0];
	min[1][0]= A[0][1]*A[2][2]-A[0][2]*A[2][1];
	min[1][1]= A[0][0]*A[2][2]-A[0][2]*A[2][0];
	min[1][2]= A[0][0]*A[2][1]-A[0][1]*A[2][0];
	min[2][0]= A[0][1]*A[1][2]-A[1][1]*A[0][2];
	min[2][1]= A[0][0]*A[1][2]-A[0][2]*A[1][0];
	min[2][2]= A[0][0]*A[1][1]-A[0][1]*A[1][0];
	
	
	float det;
	det = (A[0][0]*min[0][0])-(A[0][1]*min[0][1])+(A[0][2]*min[0][2]);
	cout<<"Determinan :"<<det<<endl;
	
	int r,s;
	cout<<"\nMinor :\n";
	for (r=0;r<3;r++){
		for (s=0;s<3;s++){
			cout<<setw(3)<<min[r][s]<<" ";
		}cout<<endl;
	}

	int mp=0;
	cout<<"kofaktor :\n";
	for (int q=0;q<3;q++){
		for (int p=0;p<3;p++){
		min[q][p]=min[q][p]*pow(-1,mp);
		cout<<setw(3)<<min[q][p];
		mp++;
			
		}cout<<endl;
	}

	int a,d;
	cout<<"Adjoin :\n";
	for (a=0;a<3;a++){
		for (d=0;d<3;d++){
			min[a][d]=min[d][a];
		cout<<setw(3)<<min[a][d];
		}cout<<endl;
	}

	int c,v;
	cout<<"Invers :\n";
	float inv[3][3];
	for (c=0;c<3;c++){
		for (v=0;v<3;v++){
			inv[c][v]=min[c][v]/det;
			cout<<setw(6)<<setprecision(2)<<inv[c][v];
		}cout<<endl;
	}
	
	}
