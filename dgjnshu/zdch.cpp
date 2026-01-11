Дан массив из 10 целых чисел и целое число а. 
Выполни сдвиг всех элементов массива на а позиции вправо или лево (если а<0). 
Если элемент выходит заграницу массива, то он должен попасть на его противоположную сторону.

Формат ввода:
В первой строке входных данных указано целое число а по модулю не превышающей 10^9. 
Во второй строке перечислены 10 целых чисел в диапазоне от 10^(-9) до 10^9. Числа разделены пробелом. 

Формат вывода:
10 целых чисел разделенные пробелом.
#include <iostream>
using namespace std;

int main() {
    long long a;
    cin >> a;

    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    a = a % 10;
    if (a < 0) {
        a += 10;
    }

    int result[10];

    for (int i = 0; i < 10; i++) {
        result[(i + a) % 10] = arr[i];
    }

    for (int i = 0; i < 10; i++) {
        cout << result[i];
        if (i < 9) cout << " ";
    }
    cout << endl;

    return 0;
}

Дана последовательность целых чисел. Определите и выведите на экран числа, которые встречаются в этой последовательности более одного раза. Если таких чисел нет, выведите 0.
В выводе числа должны быть отсортированы в следующем порядке:
• чем чаще встречалось число, тем раньше оно в выводе;
• если числа встречались одинаковое количество раз, то раньше то, которое больше.

Формат ввода:
В первой строке входных данных указано количество чисел в последовательности 1 ≤ n ≤ 1000.
Во второй строке входных данных указано и целых чисел 10^(-9) ≤ ai ≤ 10^9. Числа разделены пробелами.
Формат вывода:
Последовательность чисел, через пробел.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    map<long long, int> count;
    for (long long num : numbers) {
        count[num]++;
    }

    vector<pair<int, long long>> duplicates; 
    for (auto& p : count) {
        if (p.second > 1) {
            duplicates.push_back({p.second, p.first});
        }
    }

    if (duplicates.empty()) {
        cout << 0 << endl;
        return 0;
    }

    sort(duplicates.begin(), duplicates.end(), [](const pair<int, long long>& a, const pair<int, long long>& b) {
        if (a.first != b.first) {
            return a.first > b.first;   
        }
        return a.second > b.second; 
    });

    for (int i = 0; i < duplicates.size(); i++) {
        if (i > 0) cout << " ";
        cout << duplicates[i].second;
    }
    cout << endl;

    return 0;
}

Дана матрица целых чисел размером n строк и n столбцов. Замените обратную диагональ
матрицы на сумму индексов элемента равного среднему арифметическому элементов
расположенных одновременно над главной и под обратной диагоналями. Гарантируется, что таких элементов матрице не больше одного. Если элементов, удовлетворяющих требованиям в матрице не нашлось, то для замены используйте -1.

Формат ввода: 
В первой строке входных данных указано целое число 3 ≤ n ≤ 1000.
В следующих n строках перечислены элементы матриц - целые числа 10^(-9) ≤ ai ≤ 10^9.
Числа разделены пробелами. В конце каждой строки символ \n.

Формат вывода: 
n строк по n элементов разделенных пробелами.

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> matrix(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<long long> candidates;
    long long sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j && i + j > n - 1) {
                candidates.push_back(matrix[i][j]);
                sum += matrix[i][j];
                count++;
            }
        }
    }

    double average = (count == 0) ? 0.0 : static_cast<double>(sum) / count;

    long long target_value = -1;
    bool found = false;

    if (count > 0) {
        if (average == static_cast<long long>(average)) {
            long long avg_int = static_cast<long long>(average);
            for (long long x : candidates) {
                if (x == avg_int) {
                    target_value = avg_int;
                    found = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        matrix[i][n - 1 - i] = (found ? (i + (n - 1 - i)) : -1);
    }

    long long replacement = -1;
    if (found) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j && i + j > n - 1 && matrix[i][j] == target_value) {
                    replacement = i + j;
                    break;
                }
            }
            if (replacement != -1) break;
        }
    }

    for (int i = 0; i < n; i++) {
        matrix[i][n - 1 - i] = replacement;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) cout << " ";
            cout << matrix[i][j];
        }
        cout << "\n";
    }

    return 0;
}

Дан массив из 10 целых чисел и целое число а. Выполните сдвиг всех элементов массива на а позиций вправо или влево (если а < 0). Если элемент выходит за границу массива, то он должен попасть на его противоположную сторону.

Формат ввода:
В первой строке входных данных указано целое число а по модулю не превышающее 10^9. Во второй строке перечислены 10 целых чисел в диапазоне от 10^(-9) до 10^9. Числа разделены
пробелом.
Формат вывода:
10 целых чисел разделённые пробелами.

#include <iostream>
using namespace std;

int main() {
    long long a; 
    cin >> a;

    long long arr[10]; 
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    a = a % 10;
    if (a < 0) {
        a += 10; 
    }

    long long result[10];

    for (int i = 0; i < 10; i++) {
        result[(i + a) % 10] = arr[i];
    }

    for (int i = 0; i < 10; i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}