#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

using namespace std;

void inputData (int&,int&,int&,int&,int&,int&);
bool ifMatrixSquare (int, int);
int determinant(int**, int);
void matrixStatistics(int**,int,int,char);
void matrixOneOrTwo(char&);
void printTransposed(int**, int, int);
void printMatrix(int**,int**,int,int,int,int);
void multiplyMatrix(int**,int**,int,int,int);

int main()
{
    int rows1=0,rows2=0,colm1=0,colm2=0,matmin=0,matmax=0;
    char menuoption, mat1or2;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

    while (true){

    inputData(rows1,rows2,colm1,colm2,matmin,matmax);

    system("cls");

	int **matrix1(0);
	int **matrix2(0);

    matrix1 = new int *[rows1];
    matrix2 = new int *[rows2];

   srand(time(NULL));

    for(int  i = 0; i <rows1; i++){
        matrix1[i] = new int[colm1];
        for(int j = 0; j <colm1; j++){
            matrix1[i][j] = rand()%(matmax-matmin+1) + matmin;;
        }
    }

    for(int i = 0; i <rows2; i++){
        matrix2[i] = new int[colm2];
        for(int j = 0; j <colm2; j++){
            matrix2[i][j] = rand()%(matmax-matmin+1) + matmin;;
        }
    }

    for (bool menu=true; menu==true;){

    cout<<"C++ - Basic operations on Matrices.\nMade by Jerzy Nowak 2020\tVersion 1.0\n"<<endl;
    cout<<endl;

    printMatrix(matrix1,matrix2,rows1,rows2,colm1,colm2);
    cout<< endl;
    cout<< endl;

    cout<< "MENU \n" <<endl;
    cout<< "1: Transpose Matrix" <<endl;
    cout<< "2: Multiply Matrices" <<endl;
    cout<< "3: Find Determinant of a Matrix" <<endl;
    cout<< "4: Show Matrix Statistics" <<endl;
    cout<< "5: Reset" <<endl;
    cout<< "0: Exit" <<endl;
    cout<< endl;

    menuoption = getch();

    switch(menuoption){

    case '1':

        matrixOneOrTwo(mat1or2);
        cout<<endl;
        cout<<"Transpose of a Matrix "<<mat1or2<<":"<<endl;
        cout<< endl;
        if (mat1or2=='1'){
        printTransposed(matrix1, rows1, colm1);
        }
        else if (mat1or2=='2'){
        printTransposed(matrix2, rows2, colm2);
        }
        cout<<endl;
        cout<< "Press any key to return to menu!";
        getch();
        break;

    case '2':

        cout<<"Multiply product:"<<endl;
        cout<< endl;
        multiplyMatrix(matrix1,matrix2,rows1,rows2,colm2);
        cout<<endl;
        cout<< "Press any key to return to menu!";
        getch();
        break;


    case '3':

        matrixOneOrTwo(mat1or2);
        if ((mat1or2=='1')&&(ifMatrixSquare(rows1,colm1)==true)){
        cout<<"\nDeterminant of Matrix 1 is "<<determinant(matrix1, rows1)<<endl;
        }
        else if ((mat1or2=='2')&&(ifMatrixSquare(rows2,colm2)==true)){
        cout<<"\nDeterminant of Matrix 2 is "<<determinant(matrix2, rows2)<<endl;
        }
        cout<<endl;
        cout<< "Press any key to return to menu!";
        getch();
        break;

    case '4':

        matrixOneOrTwo(mat1or2);
        if (mat1or2=='1'){
        matrixStatistics(matrix1, rows1, colm1, mat1or2);
        }
        else if (mat1or2=='2'){
        matrixStatistics(matrix2, rows2, colm2, mat1or2);
        }
        cout<< "Press any key to return to menu!";
        getch();
        break;

    case '5':
        menu=false;
        break;

    case '0':
        delete []matrix1;
        delete []matrix2;
        exit(0);
        break;

    default:
        cout<< "No such option, press any key to return to menu!"<<endl;
        getch();
        break;
    }

    system("cls");
}

    delete []matrix1;
    delete []matrix2;

}

    return 0;
}

void multiplyMatrix(int**a,int**b,int r1,int c1r2,int c2){

    int c[r1][c2];

    for (int x = 0; x < r1; x++){
        for (int y = 0; y < c2; y++){
            c[x][y]=0;
            for (int z = 0; z < c1r2; z++){
                c[x][y] += a[x][z] * b[z][y];
            }
        }
    }

    for (int x = 0; x < r1; x++){
        for (int y = 0; y <c2; y++)
            printf("%4d", c[x][y]);
        printf("\n");
    }
}

void printMatrix(int**a,int**b,int r1,int r2,int c1,int c2){

    int height;
    if (r1>r2)
        height = r1;
    else
        height = r2;

    for (int x=0; x < height; x++){

        for(int y=0; y<c1; y++){
            if(x<r1)
            printf("%4d", a[x][y]);
            else
            printf("%4s", " ");
        }
        cout<<"\t\t";

        for(int y=0; y<c2; y++){
            if(x<r2)
            printf("%4d", b[x][y]);
            else
            printf("%4s", " ");
        }
        printf("\n");
    }
}

void printTransposed(int **a, int rows, int colm){
    for (int x = 0; x < colm; x++){
        for (int y = 0; y < rows; y++)
            printf("%4d", a[y][x]);
        printf("\n");
    }
}

void matrixOneOrTwo(char &mat1or2){
    cout<< "Matrix 1 or 2? ";
    do {
        mat1or2 = getch();
    } while ((mat1or2!='1') && (mat1or2!='2'));
}

void matrixStatistics(int **a, int rows, int colm, char mat1or2){

    int sum=0;
    int mmin= a[0][0];
    int mmax= a[0][0];

    for(int x=0; x<rows; x++){
        for(int y=0; y<colm; y++){
            sum += a[x][y];
            if(mmax<a[x][y])
                mmax = a[x][y];
            if(mmin>a[x][y])
                mmin = a[x][y];
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<"Statistics for Matrix "<<mat1or2<<":"<<endl;
    cout<<"Sum of values: "<<sum<<endl;
    cout<<"Avarage value: "<<(double)sum/(rows*colm)<<endl;
    cout<<"Max value: "<<mmax<<endl;
    cout<<"Min value: "<<mmin<<endl;
    cout<<endl;
}

void inputData (int &r1,int &r2,int &c1,int &c2,int &mmin, int &mmax){
    cout << "Submit number of rows for Matrix 1 (positive integrer)" << endl;
    cin >> r1;

    cout << "Submit number of columns for Matrix 1 (positive integrer)" << endl;
    cin >> c1;

    do{
        cout << "Submit number of rows for Matrix 2 (positive integrer, same as number of columns for Matrix 1)" << endl;
        cin >> r2;
        } while(r2!=c1);

    cout << "Submit number of columns for Matrix 2 (positive integrer)" << endl;
    cin >> c2;

    cout << "Submit min value for matrix elements (integrer)" << endl;
    cin >> mmin;

    do{
        cout << "Submit max value for matrix elements (integrer)" << endl;
        cin >> mmax;
    } while(mmax<mmin);
}

bool ifMatrixSquare(int row,int col){

    if (row == col){
        cout<<endl;
        return true;}
    else
        cout<<"Determinant can be found only for square matrix!"<<endl;
        return false;
}

int determinant(int **a,int matsize) {
    int det = 0;
    int** submatrix = new int*[matsize];
    for (int i = 0; i < matsize; ++i)
        submatrix[i] = new int[matsize];

    if (matsize == 1)
        return a[0][0];
    else if (matsize == 2)
        return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
    else {
        for (int x = 0; x < matsize; x++) {
            int subi = 0;
            for (int i = 1; i < matsize; i++) {
                int subj = 0;
                for (int j = 0; j < matsize; j++) {
                    if (j == x)
                    continue;
                    submatrix[subi][subj] = a[i][j];
                    subj++;
                }
            subi++;
            }
        det = det + (pow(-1, x) * a[0][x] * determinant(submatrix, matsize - 1));
        }
    }

    for (int i = 0; i < matsize; ++i)
    delete [] submatrix[i];
    delete [] submatrix;

    return det;
    }
