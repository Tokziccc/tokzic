#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct smart_speaker {
    char manufacturer[20]; // производитель
    int power; // мощность
    char assistant[50]; // умный помощник
};
typedef struct smart_speaker ss_t;

// Программа для работы интерфейса и объединнения всех функций
int main() {
    setlocale(LC_ALL, "RUS");
    ss_t* massiv = NULL; // Создаем начальный массив
    ss_t* massiv2 = NULL; // Создаем массив для записи данных из файла
    int vibor = 999, vibor1 = 0; // Создаем переменные, использующиеся в выборе вариантов
    int size1 = 0, size2 = 0; // Создаем переменные для размеров массивов
    char fname1[30] = "", fname2[30] = ""; // Создаем переменные для названий файлов

    // получение исходного массива для работы
    printf("1 - Создать массив\n---------------------------\n2 - Получить массив из файла\n");
    vibor1 = get_valid_input(1, 2);
    switch (vibor1) {
    case 1:
        printf("Введите размер массива(от 1 до 100):\n");
        size1 = get_valid_input(1, 100); // Ограничиваем размер файла
        massiv = (ss_t*)malloc(size1 * sizeof(ss_t));
        fill_array(massiv, size1);
        print_array(massiv, size1);
        break;
    case 2:
        printf("Введите размер массива который необходимо вывести(до 100):\n");
        size2 = get_valid_input(1, 100); 
        printf("Введите название файла из которого нужно вывести информацию(например: file.txt):\n");
        scanf("%s", fname2);
        if (!file_have(fname2)) {
            printf("Файл с таким именем не существует. Пожалуйста, введите корректное имя файла.\n");
            break;
        }
        massiv2 = (ss_t*)malloc(size2 * sizeof(ss_t));
        size2 = output_file(fname2, massiv2, size2);
        massiv = massiv2;
        size1 = size2;
        print_array(massiv, size1);
        break;
    default:
        break;
    }

    // Цикл, содержащий варианты выбора меню
    while (vibor != 0) {
        printf("Меню:\n1)Создание новой записи\n2)Поиск записи\n3)Запись в файл\n4)Чтение из файла\n5)Сортировка записи\n6)Вывести текущий массив\n0)Выход\n");
        vibor = get_valid_input(0, 6);
        switch (vibor) {
        case 1:
            // Создание записи
            printf("Введите размер массива(от 1 до 100):\n");
            size1 = get_valid_input(1, 100);
            massiv = (ss_t*)malloc(size1 * sizeof(ss_t));
            fill_array(massiv, size1);
            print_array(massiv, size1);
            break;
        case 2:
            // Поиск по массиву
            find_element(massiv, size1);
            break;
        case 3:
            // Записать имеющийся массив в файл
            printf("Введите название файла:\n");
            scanf("%s", fname1);
            input_file(fname1, massiv, size1);
            print_array(massiv, size1);
            break;
        case 4:
            // Считать файл
            printf("Введите размер массива который необходимо вывести(до 100):\n");
            size2 = get_valid_input(1, 100); 
            printf("Введите название файла из которого нужно вывести информацию:\n");
            scanf("%s", fname2);
            if (!file_have(fname2)) {
                printf("Файл с таким именем не существует. Пожалуйста, введите корректное имя файла.\n");
                break;
            }
            massiv2 = (ss_t*)malloc(size2 * sizeof(ss_t));
            size2 = output_file(fname2, massiv2, size2);
            massiv = massiv2;
            size1 = size2;
            print_array(massiv, size1);
            break;
        case 5:
            // Сортировка
            sort_massiv(massiv, size1);
            break;
        case 6:
            // Вывод массива
            print_array(massiv, size1);
            break;
        default:
            break;
        }
    }

    // Освобождение памяти
    free(massiv);
    free(massiv2);
    return 0;
}

// Определение функций
// Вывод массива
int print_array(ss_t* massiv, int size) {
    for (int i = 0; i < size; i++) {
        printf("Производитель: %s, Мощность(Вт): %i, Умный помощник: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
    }
    return size;
}

// Сохранение массива в файл
int input_file(char* fname, ss_t* massiv, int size) {
    FILE* out = fopen(fname, "wt"); // Ввод названия файла, в который будет записсан массив
    if (!out) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        fprintf(out, "Производитель: %s Мощность(Вт): %i Умный помощник: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
    }
    fclose(out);
    return size;
}

// Заполнение массива
int fill_array(ss_t* massiv, int size) {
    printf("Варианты для заполнения полей\n1) Производитель - любое название\n2)Мощность - целое число\n3)Умный помощник - любое название\n");

    for (int i = 0; i < size; i++) {
        int valid_input = 0; // Проверка до какого момента вводить данные

        while (!valid_input) {
            printf("Введите данные о колонке в порядке: производитель, мощность, умный помощник\n");
            int result = scanf("%14s %i %14s", massiv[i].manufacturer, &massiv[i].power, massiv[i].assistant);

            if (result == 3) {
                valid_input = 1;
                printf("Производитель: %s, Мощность(Вт): %i, Умный помощник: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
            }
            else {
                printf("Некорректные данные.\n");
                while (getchar() != '\n'); // Очистка буфера ввода
            }
        }   
    }
    return size;
}

// Считывание файла
int output_file(char* fname, ss_t* massiv, int size) {
    FILE* in = fopen(fname, "rt"); // Открытие файла, осуществляется через ввод названия
    if (!in) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    int count = 0; // Счетчик кол-ва считанных структур
    while (count < size && fscanf(in, "Производитель: %14s Мощность: %i Умный помощник: %14s\n", massiv[count].manufacturer, &massiv[count].power, massiv[count].assistant) == 3) {
        count++;
    }
    if (count < size) {
        printf("В файле не достаточно данных.\n");
    }
    fclose(in);
    return count;
}

// Функция поиска
int find_element(ss_t* massiv, int size) {
    char s[20], s1[50]; // Для введения данных
    int n1, n2; // n1 - нужное поле, n2 - кол-в полей

    printf("Введите количество полей для поиска:\n");
    n2 = get_valid_input(1, 2);
    if (n2 == 1) {
        printf("Введите поле для поиска (1-умный помощник, 2-производитель):\n");
        n1 = get_valid_input(1, 2);

        if (n1 == 1) {
            printf("Введите умного помощника:\n");
            scanf("%14s", s);

            for (int i = 0; i < size; i++) {
                if (strcmp(massiv[i].assistant, s) == 0)
                    printf("Производитель: %s, Мощность(Вт): %i, Умный помощник: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
            }
        }
        else if (n1 == 2) {
            printf("Введите производителя:\n");
            scanf("%14s", s);

            for (int i = 0; i < size; i++) {
                if (strcmp(massiv[i].manufacturer, s) == 0)
                    printf("Производитель: %s, Мощность(Вт): %i, Умный помощник: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
            }
        }
    }
    else if (n2 == 2) {
        printf("Выбран поиск по обоим полям\n");
        printf("Введите искомого умного помощника:\n");
        scanf("%14s", s);
        printf("Введите искомого производителя:\n");
        scanf("%14s", s1);
        for (int i = 0; i < size; i++) {
            if ((strcmp(massiv[i].assistant, s) == 0) && (strcmp(massiv[i].manufacturer, s1) == 0))
                printf("Производитель: %s, Мощность(Вт): %i, Умный помощник: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
        }
    }
    return size;
}

// Функция сортировки
int sort_massiv(ss_t* massiv, int size) {
    int p, p1; // p - критерий сортировки, p1 - тип сортировки
    printf("Введите критерий для сортировки (1-производитель, 2-мощность):\n");
    p = get_valid_input(1, 2);
    printf("Выберите тип сортировки (1-по возрастанию, 2-по убыванию):\n");
    p1 = get_valid_input(1, 2);
        
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int sort = 0;

            switch (p) {
            case 1: sort = strcmp(massiv[j].manufacturer, massiv[j + 1].manufacturer); break;
            case 2: sort = (massiv[j].power > massiv[j + 1].power) ? 1 : -1; break;
            default: break;
            }

            if ((p1 == 1 && sort > 0) || (p1 == 2 && sort < 0)) {
                ss_t temp = massiv[j];
                massiv[j] = massiv[j + 1];
                massiv[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("Производитель: %s, Мощность(Вт): %i, Умный помощник: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
    }
    return size;
}

// Ввод лимитов массива и его проверка 
int get_valid_input(int min, int max) {
    int input;
    char buffer[256];
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &input) == 1 && input >= min && input <= max) {
                return input;
            }
            else {
                printf("Пожалуйста, введите число от %d до %d: ", min, max);
            }
        }
    }
}

// Проверка наличия файла
int file_have(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}
