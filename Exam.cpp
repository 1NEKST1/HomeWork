
#include <iostream>
#include <fstream>
#include <string>
#define random(min,max) min + rand() % (max - min + 1)\

using namespace std;
void eight(int*& arr, int a, int& size, int num) {
	int* buf = new int[size + 1];
	for (int i = 0;i < a;i++) {
		buf[i] = arr[i];
	}
	buf[a] = num;
	for (int i = a+1;i < size+1;i++) {
		buf[i] = arr[i-1];
	}
	size++;
	delete[] arr;
	arr = buf;
}
void showOneArr(int* arr, int size) {
	for (int i = 0;i < size;i++) {
		cout << arr[i] << ' ';
	}
}

void seven(int** arr, int**& buf, int Row, int Col) {
	for (int i = 0;i < Row;i++) {
		for (int j = 0;j < Col;j++) {
			buf[i][j] = arr[i][j];
		}
	}
}

void showTwoArr(int** arr, int Row, int Col) {
	for (int i = 0;i < Row;i++) {
		for (int j = 0;j < Col;j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}


}

void reverse(int*& arr, int size) {
	int* buf = new int[size];
	for (int i = 0, j = size-1;i < size;i++, j--) {
		buf[i] = arr[j];
	}
	delete[] arr;
	arr = buf;
}

void deleteCol(int**& arr, int Row, int& Col, int a) {
	int** buf = new int* [Row];
	for (int i = 0;i < Row;i++) {
		buf[i] = new int[Col-1];
	}
	Col--;
	for (int i = 0;i < Row;i++) {
		for (int j = 0;j < a;j++) {
			buf[i][j] = arr[i][j];
		}
	}
	for (int i = 0;i < Row;i++) {
		for (int j = a;j < Col;j++) {
			buf[i][j] = arr[i][j+1];
		}
	}
	delete[] arr;
	arr = buf;
}
void deleteRow(int**& arr, int& Row, int Col, int a) {
	Row--;
	int** buf = new int* [Row];
	for (int i = 0;i < Row;i++) {
		buf[i] = new int[Col];
	}
	for (int i = 0;i < a;i++) {
		for (int j = 0;j < Col;j++) {
			buf[i][j] = arr[i][j];
		}
	}
	for (int i = a;i < Row;i++) {
		for (int j = 0;j < Col;j++) {
			buf[i][j] = arr[i+1][j];
		}
	}
	delete[] arr;
	arr = buf;
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	// 1
	//int a, b, c, d, e;
	//cout << "Введите число: ";
	//cin >> a;
	//cout << "Введите число: ";
	//cin >> b;
	//cout << "Введите число: ";
	//cin >> c;
	//cout << "Введите число: ";
	//cin >> d;
	//cout << "Введите число: ";
	//cin >> e;
	//int arr[5]{ a,b,c,d,e };
	//int max = arr[0];
	//int min = arr[0];
	//for (int i = 1;i < 5;i++) {
	//	if (max < arr[i]) max = arr[i];
	//	
	//}
	//for (int i = 1;i < 5;i++) {
	//	if (min > arr[i]) min = arr[i];

	//}
	//cout << "max = " << max << ' ' << "min = " << min;
	
	

	// 2
	//for (int i = 1; i < 51;i++) {
	//	if (i % 2 != 0) cout << i << ' ';
	//}
	

	// 3
	//int h;
	//cout << "Введите высоту: ";
	//cin >> h;
	//int s = 1;
	//for (int j = 0;j < h;j++) {
	//	for (int i = 0;i < s;i++) {
	//		cout << '*' << ' ';
	//		
	//	}
	//	s++;
	//	cout << endl;
	//}


	
	

	// 4
/*	int a;
	cout << "Введите число: ";
	cin >> a;
	int b = 0;
	for (int i = a -1;i > 1;i--) {
		if (a % i == 0) b++;
	}
	if (b > 0) cout << "Число не является простым";
	else cout << "Число является простым"*/;

	// 6
	//int Row = 4;
	//int Col = 4;
	//int** arr = new int*[Row];
	//for (int i = 0;i < Row;i++) {
	//	arr[i] = new int[Col];
	//}
	//for (int i = 0;i < Col;i++) {
	//	for (int j = 0;j < Col;j++) {
	//		arr[i][j] = random(1, 9);
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//int max = 0;
	//int sum = 0;
	//for (int i = 0;i < Col;i++) {
	//	max += arr[0][i];
	//}
	//for (int i = 1;i < Col;i++) {
	//	for (int j = 0;j < Col;j++) {
	//		sum += arr[i][j];
	//	}
	//	if (sum > max) {
	//		max = sum;
	//	}
	//	sum = 0;
	//}
	//cout << max;


	// 8
	//int size = 4;
	//int* arr = new int[size] {0, 1, 2, 3};
	//int a, num;
	//cout << "На какое место ставим число?: ";
	//cin >> a;
	//if (a > size) cout << "error";
	//else {
	//	cout << "Введите число?: ";
	//	cin >> num;
	//	eight(arr, a, size, num);
	//	showOneArr(arr, size);
	//}

	// 7
	//int Row = 4;
	//int Col = 4;
	//int** arr = new int*[Row];
	//for (int i = 0;i < Row;i++) {
	//	arr[i] = new int[Col];
	//}
	//for (int i = 0;i < Col;i++) {
	//	for (int j = 0;j < Col;j++) {
	//		arr[i][j] = random(1, 9);
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//int** buf = new int*[Row];
	//for (int i = 0;i < Row;i++) {
	//	buf[i] = new int[Col];
	//}
	//seven(arr, buf, Row, Col);
	//cout << endl;
	//showTwoArr(buf, Row, Col);


	// 9
	//int size = 5;
	//int* arr = new int[size]{ 0,1,2,3,4 };
	//reverse(arr, size);
	//showOneArr(arr, size);

	// 10
	//int Row = 4;
	//int Col = 4;
	//int** arr = new int*[Row];
	//for (int i = 0;i < Row;i++) {
	//	arr[i] = new int[Col];
	//}
	//for (int i = 0;i < Col;i++) {
	//	for (int j = 0;j < Col;j++) {
	//		arr[i][j] = random(1, 9);
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << "Какой столбец удалить?:";
	//int num;
	//cin >> num;

	//deleteCol(arr, Row, Col, num);
	//showTwoArr(arr, Row, Col);


    // 11
	//int Row = 4;
	//int Col = 4;
	//int** arr = new int*[Row];
	//for (int i = 0;i < Row;i++) {
	//	arr[i] = new int[Col];
	//}
	//for (int i = 0;i < Col;i++) {
	//	for (int j = 0;j < Col;j++) {
	//		arr[i][j] = random(1, 9);
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//int min = 0;
	//int sum = 0;
	//int r = 0;
	//for (int i = 0;i < Col;i++) {
	//	min += arr[0][i];
	//}
	//for (int i = 1;i < Col;i++) {
	//	for (int j = 0;j < Col;j++) {
	//		sum += arr[i][j];
	//	}
	//	if (sum < min) {
	//		min = sum;
	//		r = i;
	//	}
	//	sum = 0;
	//}
	//cout << min << ' ' << r << endl;
	//deleteRow(arr, Row, Col, r);
	//showTwoArr(arr, Row, Col);
	
	// 12
	string str = "Hello what how what";
	cout << strIndex(str, "what");



}
