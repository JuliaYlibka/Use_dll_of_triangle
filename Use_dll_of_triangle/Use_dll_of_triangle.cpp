// Use_dll_of_triangle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	HMODULE hDll;
	float(*P)(float,float,float);
	float (*S)(float,float,float);
	float side1;
	float side2;
	float side3;

	hDll = LoadLibrary("C:\\Users\\217041\\source\\repos\\Dll_P_S_of_tringle\\x64\\Debug\\Dll_P_S_of_tringle.dll");
	if (!hDll)
	{
		cerr << "Load library failed." << endl;
		return GetLastError();
	}
	cout << "Enter the length of the first side";
	cin >> side1;
	cout << "Enter the length of the second side";
	cin >> side2;
	cout << "Enter the length of the third side";
	cin >> side3;

	P = (float(*)(float, float, float)) GetProcAddress(hDll, MAKEINTRESOURCE(1));
	S = (float(*)(float, float, float)) GetProcAddress(hDll, MAKEINTRESOURCE(2));
	if (!P || !S)
	{
		cerr << "GEt procedure address failled." << endl;
		return GetLastError();
	}

	cout << "Get a data of triangle with sides " << side1 <<", "<< side2 <<", "<<  side3 << endl;
	cout << "P = " << P(side1,side2,side3) << endl;
	cout << "S = " << S(side1, side2, side3) << endl;
	if (!FreeLibrary(hDll))
	{
		cerr << "Free library failed." << endl;
		return GetLastError();
	}
	cout << "Press any key to exit";
	return 0;
}