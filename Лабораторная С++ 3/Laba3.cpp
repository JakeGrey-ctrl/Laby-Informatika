#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n;
    cout << "Введите размер массива: ";
    cin >> n; //ввод длины массива
    while (cin.fail() || n <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный ввод! Попробуйте ещё раз ввести длину массива: ";
        cin >> n;
    }
    float *array1 = new float[n];
    float sum = 0;
    cout << "Исходный массив: ";
    for (unsigned int i = 0; i < n; i++)
    {
        float value = (float)rand() / RAND_MAX * 200 - 100;
        array1[i] = value;
        cout << value << " ";
    }
    //конец формирования массива, далее подсчёт суммы с неч. номерами
    for (unsigned int i = 0; i < n; i += 2)
    {
        sum += array1[i];
    }
    cout << "\nСумма элементов на нечётных позициях: " << sum;
    //Поиск первого и последнего отрицательного
    unsigned int first_negat_ind;
    unsigned int last_negat_ind;
    bool found_first = false;
    bool found_last = false;
    for (unsigned int i = 0; i < n; i++)
    {
        if (!(found_first) && array1[i] < 0)
        {
            first_negat_ind = i;
            found_first = true;
        }
        if (!(found_last) && array1[n - i - 1] < 0)
        {
            last_negat_ind = n - i - 1;
            found_last = true;
        }
        if (found_first && found_last) break;
    }
    /*В случае ниже можно не рассматривать в условии found_last, т. к. подразумевается, что если найдено первое,
    то найдено последнее соответственно*/
    if (found_first) //далее разбивка на 3 случая
    {
        if (first_negat_ind == last_negat_ind) cout << "\nСумма между первым и последним отрицательным элементами равна 0\n";
        else
        {
            sum = 0;
            for (unsigned int i = first_negat_ind + 1; i < last_negat_ind; i++) sum += array1[i];
            cout << "\nСумма между первым и последним отрицательным элементами равна " << sum << endl;
        }
    }
    else cout << "\nВ массиве нет отрицательных элементов\n";
    float *array2 = new float[n];
    unsigned int j = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        if (abs(array1[i]) > 25)
        {
            array2[j] = array1[i];
            j++;
        }
    }
    //Удаляем исходный массив
    delete[] array1;
    array1 = nullptr;
    //Вывод массива. В данном случае j выступает как длина массива array2
    cout << "Изменённый массив: ";
    for (unsigned int i = 0; i < j; i++)
    {
        cout << array2[i] << " ";
    }
}