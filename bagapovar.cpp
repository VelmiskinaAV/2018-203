#include "bagapovar.h"

/**
 * Введение в дисциплину
 */

 void bagapovar::lab1()
{
std::cout<<"Hello world";
}


/**
* Метод Гаусса с выбором главного элемента
*/
void bagapovar::lab2()
{
double t;

for (int k = 0; k < N; k++) { //Ищем самый большой элемент стоящий на к'атом месте по всем строкам, по умолчанию он k'ый
	int maxel=k;
		for(int i=k+1;i<N;i++)
			if(abs(A[i][k]) > abs(A[maxel][k]))
				maxel=i;
//Нашли, теперь надо поменять k'ую строчку и строчку с максимальным элементом местами
	for(int i=0;i<N;i++)
	std::swap(A[k][i],A[maxel][i]);
	std::swap(b[k],b[maxel]);

//Прямой ход
t = A[k][k];
//Делим все элементы k'ой строки на a[k][k] элемент, потому что он диагональный и мы хотим на нём получить значение 1
//для удобства дальнейших вычислений
for (int j = 0; j < N; j++)
	A[k][j] = A[k][j] / t;
b[k] =b[k]/t;

for (int i = k + 1; i < N; i++) {
	t = A[i][k];
//Вычитаем из всех строк лежащих ниже k'ой к'ую строку помноженную на k'ый элемент строки,
// из которой вычитаем, что даёт нам ноль в этом элементе после вычитания и матрица постепенно приобретает треугольный вид

	for (int j = 0; j < N; j++) {
		A[i][j] =A[i][j]- A[k][j] * t;
	}
b[i] =b[i]- b[k] * t;
}
}

//Матрица треугольного вида готова, теперь можем последовательно, снизу вверх вычислять искомые значения элементов матрицы x
//Осуществляем обратный ход
for (int k = N - 1; k > 0; k--)
{
for (int i = k - 1; i >= 0; i--)
{
t = A[i][k];

for (int j = 0; j < N; j++)
A[i][j] =A[i][j]- A[k][j] * t;
b[i] =b[i] - b[k] * t;
}
}

for(int i=0; i<N; i++)
x[i]=b[i];
}



/**
 * Метод прогонки
 */
void bagapovar::lab3()
{//Это частный случай для метода Гаусса, используется, когда матрица трёхдиагональная
double *up, *mid, *low; // верхняя, главная, нижняя диагонали 
up = new double[N]; 
mid = new double[N]; 
low = new double[N]; 
double k; 

low[0] = 0; 
up[N-1] = 0; 

for (int i = 0; i < N; i++)//Заполняем "диагональные" массивы 
{ 
	if (i - 1 >= 0 && i - 1 < N) 
	up[i] = A[i-1][i]; //верхняя 
	mid[i] = A[i][i]; //главная 
	if (i + 1 >= 0 && i + 1 < N) 
	low[i] = A[i+1][i]; //нижняя 
} 
//Прямая прогонка 
for (int i = 1; i < N; i++) //Вычисляем коэффициенты прогонки 
{ 
	k = low[i]/mid[i-1]; 
	mid[i] = mid[i] - k*up[i-1]; 
	b[i] = b[i] - k*b[i-1]; 
} 

//Обратная прогонка 
x[N-1] = b[N-1]/mid[N-1]; //Вычисляется решение 

for (int i = N - 2; i >= 0; i--) //Решение для следующих частей 
	x[i]=(b[i]-up[i]*x[i+1])/mid[i]; 

delete[] up, mid, low; 
} 



/**
 * Метод простых итераций
 */
void bagapovar::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void bagapovar::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void bagapovar::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void bagapovar::lab7()
{

}


void bagapovar::lab8()
{

}


void bagapovar::lab9()
{

}


std::string bagapovar::get_name()
{
  return "Bagapov A.R.";
}