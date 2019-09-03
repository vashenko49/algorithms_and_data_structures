#pragma once
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class ASD_sort
{
public:
	ASD_sort();
#pragma  region Системное
	void EnterMussRand(int* muss, int n);
	void Print(int * muss, int n);
#pragma endregion 

#pragma  region  Лабораторна робота5 Сортування масивів
	void Sortirovka_vstavkoyu(int* muss, int n); //1
	void Sortirovka_vyborom(int* muss, int n); //3
	void Sortirovka_podschyotom(int* muss, int n); //4
	void Sortirovka_bulbashkoj(int* muss, int n); //5
	void Sortirovka_Shella(int* muss, int n); //7
	void Sortirovka_shejkerna(int* muss, int n); //6
#pragma endregion 

#pragma  region  Лабораторна робота6 Сортування масивів

	void Bystraya_sortirovka(int* muss, int first, int last); //4
	void siftDown(int *numbers, int root, int bottom);
	void Piramidalnaya_sortirovka(int* muss, int n);//2
	int getMax(int arr[], int n);
	void countSort(int arr[], int n, int exp);
	void Porazryadnaya_sortirovka(int *muss, int n);//3
#pragma endregion 

#pragma region Лабораторна робота8 Сортування послідовностей
//1
#pragma region Merge 
	void merge(int arr[], int l, int m, int r); // сливание 2 чатей
	void mergeSort(int arr[], int l, int r); // деление массив
#pragma  endregion
//2
#pragma region NaturalMerge 
	void Merge(int Array[], int workArray[], int begin1, int end1, int begin2, int end2);// сливание
	void CopyArray(int firstArray[], int iBegin, int iEnd, int secondArray[]); // копирование оставшихся
	void NaturalMergeSort(int Array[], int arraySize);
#pragma  endregion
//3
#pragma region MultiMerge
	void merge(int v[], size_t mid, size_t len);
	void mersort(int v[], size_t len);
	void mersort3(int v[], size_t len);
#pragma  endregion

#pragma  endregion

#pragma region Лабораторна робота9 Пошук даних
//1
	void Algoritm_poslIdovnogo_poshuku(int *muss, int size, int find);
//2
	int Algoritm_dvIykovogo_poshuku(int *arr, int left, int right, int key);
//3
	int Algoritm_pryamogo_poshuku_v_ryadku(const char *s, const char *c);
//4
#pragma region Алгоритм Кнута-Морріса-Пратта
	void preKMP(string pat, int M, int *d);
	void KMP(string pat, string txt);
#pragma  endregion 
//5
#pragma region Алгоритм Кнута-Морріса-Пратта
	int boyer_moore(const char *string, const char *substring);
#pragma  endregion 


#pragma  endregion 

	~ASD_sort();
};

inline ASD_sort::ASD_sort()
{
}
//Реализация
#pragma  region Системное

inline void ASD_sort::EnterMussRand(int * muss, int n)
{
	for (int i = 1; i <= n; i++)
	{
		
	}
}
inline void ASD_sort::Print(int * muss, int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << muss[i] << " ";
	}
}
#pragma endregion 

#pragma  region  Лабораторна робота5 Сортування масивів

inline void ASD_sort::Sortirovka_vstavkoyu(int * muss, int n)
{
	for(int i =1;i<n;i++)
	{
		for(int j =i;j>0;j--)
		{
			if(muss[j-1]>muss[j])
			{
				int temp = muss[j - 1];
				muss[j - 1] = muss[j];
				muss[j] = temp;
			}
		}
	}
}

inline void ASD_sort::Sortirovka_vyborom(int * muss, int n)
{
	for(int i =0;i<n-1;i++)
	{
		int min = i;
		for(int j=i+1;j<n;j++)
		{
			if(muss[j]<muss[min])
			{
				min = j;
			}
		}
		int temp = muss[i];
		muss[i] = muss[min];
		muss[min] = temp;
	}
}

inline void ASD_sort::Sortirovka_podschyotom(int * muss, int n)
{
#pragma region действия связанные с особенностями с++
	int max = muss[0];

	for (int i = 1; i < n; i++)
	{
		if (muss[i] > max)
		{
			max = muss[i];
		}
	}
	int *temp = new int[max + 1];
	for (int i = 0; i<max + 1; i++)
	{
		temp[i] = 0;

	}
#pragma endregion 

	for (int i =0;i<n;i++)
	{
		temp[muss[i]]++;
	}
	for (int i=0, k = 0;i<max+1;i++)
	{
		if (temp[i] != 0)
		{
			for (int j = temp[i]; j > 0; j--, k++)
			{
				muss[k] = i;
			}
		}
	}
	
}

inline void ASD_sort::Sortirovka_bulbashkoj(int * muss, int n)
{
	for(int i =0; i <n;i++)
	{
		for(int j = i; j<n-1;j++)
		{
			if(muss[j]>muss[j+1])
			{
				int temp = muss[j];
				muss[j] = muss[j + 1];
				muss[j + 1] = temp;
			}
		}
	}
}

inline void ASD_sort::Sortirovka_Shella(int * muss, int n)
{
	for(int d = n/2;d>0;d/=2)
	{
		for(int i =0; i<(n-d);i++)
		{
			for(int j=i; (j>=0)&&(muss[j]>muss[j+d]);j-=d)
			{
				int temp = muss[j];
				muss[j] = muss[j + d];
				muss[j + d] = temp;
			}
		}
	}
}

inline void ASD_sort::Sortirovka_shejkerna(int * muss, int n)
{
	int left = 0;
	int right = n - 1;
	while (left<right)
	{
		for(int i = left; i <right;i++)
		{
			if (muss[i]>muss[i + 1])
			{
				int temp = muss[i];
				muss[i] = muss[i + 1];
				muss[i + 1] = temp;
			}
		}
		right--;
		for(int i = right; i>left;i--)
		{
			if(muss[i-1]>muss[i])
			{
				int temp = muss[i];
				muss[i] = muss[i - 1];
				muss[i - 1] = temp;
			}
		}
		left++;
	}
}
#pragma endregion 

#pragma  region  Лабораторна робота6 Сортування масивів

inline void ASD_sort::Bystraya_sortirovka(int * muss, int first, int last)
{

	if (first < last)
	{
		int left = first, right = last, middle = muss[(left + right) / 2];
		do
		{
			while (muss[left] < middle) left++;
			while (muss[right] > middle) right--;
			if (left <= right)
			{
				int tmp = muss[left];
				muss[left] = muss[right];
				muss[right] = tmp;
				left++;
				right--;
			}


		} while (left <= right);
		Bystraya_sortirovka(muss, first, right);
		Bystraya_sortirovka(muss, left, last);
	}
}

#pragma  region Пирамидальная сортировка
inline void ASD_sort::siftDown(int * numbers, int root, int bottom)
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
				  // Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // если мы в последнем ряду, 
			maxChild = root * 2;    // запоминаем левый потомок
									// иначе запоминаем больший потомок из двух
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root]; // меняем их местами
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}



inline void ASD_sort::Piramidalnaya_sortirovka(int * muss, int n)
{
	// Формируем нижний ряд пирамиды
	for (int i = (n / 2) - 1; i >= 0; i--)
		siftDown(muss, i, n);
	// Просеиваем через пирамиду остальные элементы
	for (int i = n - 1; i >= 1; i--)
	{
		int temp = muss[0];
		muss[0] = muss[i];
		muss[i] = temp;
		siftDown(muss, 0, i - 1);
	}
}

inline int ASD_sort::getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

#pragma endregion 

inline void ASD_sort::countSort(int arr[], int n, int exp)
{
	int *output =new int[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

inline void ASD_sort::Porazryadnaya_sortirovka(int * muss, int n)
{
	int m = getMax(muss, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(muss, n, exp);
}




#pragma endregion 

#pragma region Лабораторна робота8 Сортування послідовностей
//1
#pragma region Merge
inline void ASD_sort::merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	int *L, *R;
	L = new int[n1]; // подмассивы
	R = new int[n2];

	// переносим в массивы
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// сливаем все вместе arr[l....r];
	i = 0; // начальный индекс 1 подмассива
	j = 0; // начальный индекс 2 подмассива
	k = l; // начальный индекс слитого подмассива
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}						// Cравнивает елементы 2 подмассивов и сливает их
		else
		{
			arr[k] = R[j];		// копирует оставшиеся елементы R[] если остались
			j++;
		}
		k++;
	}

	// копируем оставшиеся елементы с массива L[]  если остались
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// копируем оставшиеся елементы с массива R[]  если остались
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
inline void ASD_sort::mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2; // (l+r)/2 чтобы избежать оверфлоу


		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
#pragma  endregion
//2
#pragma region NaturalMerge 
inline void ASD_sort::Merge(int Array[], int workArray[], int begin1, int end1, int begin2, int end2)
{
	int counter1 = begin1, counter2 = begin2;
	for (int counter3 = begin1; counter3 <= end2; counter3++) {
		if ((counter1 <= end1) && ((counter2 > end2) || Array[counter1] <= Array[counter2])) {
			workArray[counter3] = Array[counter1]; // в новый массив
			counter1++;
		}
		else {
			workArray[counter3] = Array[counter2]; // в новый массив
			counter2++;
		}
	}
}
inline void ASD_sort::CopyArray(int firstArray[], int iBegin, int iEnd, int secondArray[])
{
	for (int counter = iBegin; counter <= iEnd; counter++) {
		firstArray[counter] = secondArray[counter];
	}
}
inline void ASD_sort::NaturalMergeSort(int Array[], int arraySize)
{
	if (arraySize < 2)
		return;

	int *workArray;
	workArray = new int[arraySize];
	int isSortedFlag = 0;
	while (isSortedFlag == 0) {
		int begin1 = 0,			// почат и конец 2 подмассивов
			end1 = 0,
			begin2 = 0,
			end2 = 0;

		while (end1 < (arraySize - 1)) { // упорядрочиваем 1 подмасиив
			if (Array[end1] <= Array[end1 + 1]) {
				end1++;
			}

			else {
				for (begin2 = end2 = (end1 + 1); end2 < (arraySize - 1); end2++) { // упорядочиваем 2 подмассив
					if (Array[end2] <= Array[end2 + 1]) {
						continue;
					}

					else {
						break;
					}
				}
				Merge(Array, workArray, begin1, end1, begin2, end2);
				CopyArray(Array, begin1, end2, workArray);
				begin1 = end1 = (end2 + 1);
			}
		}
		if ((begin2 == 0) && (end2 == 0)) { // как только все перекопировали
			isSortedFlag = 1; // отсортировано
		}
	}
}
#pragma  endregion 
//3

#pragma region MultiMerge
inline void ASD_sort::merge(int v[], size_t mid, size_t len)
{
	if (len < 2)
		return;

	size_t i = 0, j = mid, k = 0;
	int *tmp; // нвый массив
	tmp = new int[len];

	while (i < mid && j < len) // сливаем 

		if (v[i] < v[j])
		{
			tmp[k++] = v[i++];
		}
		else
		{
			tmp[k++] = v[j++];
		}

	memcpy(tmp + k, v + i, (mid - i) * sizeof *v); // копируем то что осталось
	memcpy(v, tmp, (k + (mid - i)) * sizeof *v);
}
inline void ASD_sort::mersort(int v[], size_t len)
{
	if (len < 2)
		return;

	size_t mid = len / 2;
	mersort(v, mid);
	mersort(v + mid, len - mid);
	merge(v, mid, len);
}
inline void ASD_sort::mersort3(int v[], size_t len)
{
	if (len < 3)
	{
		mersort(v, len);
		return;
	}

	size_t m1 = len / 3;
	size_t m2 = (2 * len) / 3;
	// делим на 3 части рекурсивно
	mersort3(v, m1);
	mersort3(v + m1, m2 - m1);
	mersort3(v + m2, len - m2);
	//сливаем
	merge(v, m1, m2);
	merge(v, m2, len);

}

#pragma  endregion 
#pragma  endregion 

#pragma region Лабораторна робота9 Пошук даних
//1
#pragma region Алгоритм послідовного пошуку
inline void ASD_sort::Algoritm_poslIdovnogo_poshuku(int * muss, int size, int find)
{
	int temp = -1;
	for(int i =0; i<size;i++)
	{
		if(muss[i]==find)
		{
			temp = i;
		}
	}

	if(temp == -1)
	{
		std::cout << "Елемент не найдет"<< std::endl;
	}
	else
	{
		std::cout << " Елемент " << find << "найдет, в ячейке " << temp << std::endl;
	}
}
#pragma  endregion 
//2
#pragma region Алгоритм двійкового пошуку
inline int ASD_sort::Algoritm_dvIykovogo_poshuku(int * arr, int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])      
			right = midd - 1;     
		else if (key > arr[midd]) 
			left = midd + 1;   
		else                       
			return midd;         

		if (left > right)         
			return -1;
	}
}


#pragma  endregion 
//3
#pragma region Алгоритм прямого пошуку в рядку
inline int ASD_sort::Algoritm_pryamogo_poshuku_v_ryadku(const char *s, const char *c)
{
	int n = 1;
		int i, j;		
		int lenC, lenS;	

		for (lenC = 0; c[lenC]; lenC++);
		for (lenS = 0; s[lenS]; lenS++);

		for (i = 0; i <= lenS - lenC; i++) 
		{
			for (j = 0; s[i + j] == c[j]; j++); 
			if (j - lenC == 1 && i == lenS - lenC && !(n - 1)) return i;
			if (j == lenC)
				if (n - 1) n--;
				else return i;
		}
		return -1;
}
#pragma  endregion 
//4
#pragma region Алгоритм Кнута-Морріса-Пратта
inline void ASD_sort::preKMP(string pat, int M, int *d)
{
	int len = 0;
	d[0] = 0; 

	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			d[i] = len;
			i++;
		}
		else
		{

			if (len != 0)
			{
				len = d[len - 1];
			}
			else // if (len == 0)
			{
				d[i] = 0;
				i++;
			}
		}
	}
}
inline void ASD_sort::KMP(string pat, string txt)
{
	int M = pat.length();
	int N = txt.length();

	int *d;
	d = new int[M];

	preKMP(pat, M, d);

	int i = 0;  
	int j = 0; 
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{

			cout << "Found at index of : " << i - j << endl;
			j = d[j - 1];
		}

		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = d[j - 1];
			else
				i = i + 1;
		}
	}
}
#pragma  endregion 
//5
#pragma region Алгоритм Боуера-Мура
inline int ASD_sort::boyer_moore(const char *string, const  char *substring)
{
	int  strin = 0;
	int substrin = 0;
	int answer = -1;

	while (string[strin] != NULL) {
		strin++;
	}
	while (substring[substrin] != NULL) {
		substrin++;
	}
	if (strin == 0)
		cout<<"Некорректная строка"<<endl;
	else if (substrin == 0)
		cout << "Некорректная подстрока" << endl;
	else {
		int  i, Pos;
		int  BMT[256];
		for (i = 0; i < 256; i++)
			BMT[i] = substrin;
		for (i = substrin - 1; i >= 0; i--)
			if (BMT[(short)(substring[i])] == substrin)
				BMT[(short)(substring[i])] = substrin - i - 1;
		Pos = substrin - 1;
		while (Pos < strin)
			if (substring[substrin - 1] != string[Pos])
				Pos = Pos + BMT[(short)(string[Pos])];
			else
				for (i = substrin - 2; i >= 0; i--) {
					if (substring[i] != string[Pos - substrin + i + 1]) {
						Pos += BMT[(short)(string[Pos - substrin + i + 1])] - 1;
						break;
					}
					else
						if (i == 0)
							return Pos - substrin + 1;
				}
	}
	return answer;
}
#pragma  endregion 
#pragma  endregion 

inline ASD_sort::~ASD_sort()
{
}

