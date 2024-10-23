#include <iostream>
#include <vector>

int sumOfDigits(int number) { // Функция для расчёта суммы цифр
    int sum = 0;
    number = std::abs(number); // Убедимся, что число положительное
    while (number > 0) {
        sum += number % 10; // Добавляем последнюю цифру к сумме
        number /= 10;       // Убираем последнюю цифру
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "RUS"); // Подключаем русский язык(для удобства)
    std::vector<int> numbers; // Создаём динамический массив для получаемых цифр
    int input; // Переменная для ввода цифр
    int maxSum = 0; // Обнуляем максимальную сумму
    int numberWithMaxSum = 0; // Обнуляем цисло с максимальной суммой

    std::cout << "Введите целые числа (введите 0 для завершения ввода):" << std::endl; // Вывод в консоль

    while (true) { // Создаём цикл
        std::cin >> input; // Ждём ввода числа
        if (input == 0) {
            break; // Завершаем ввод, если введен 0
        }
        numbers.push_back(input); // Сохраняем введенное число

        if (numbers.empty()) {
            std::cout << "Не было введено ни одного числа." << std::endl;
            return 0;
        } // Если не было ни одного числа завершаем выполнение программы

        for (int number : numbers) { // заменяем значения если сумма цифр в числе больше чем в предыдущем
            int currentSum = sumOfDigits(number);
            if (currentSum > maxSum) {
                maxSum = currentSum;
                numberWithMaxSum = number;
            }
        }
    }

        std::cout << "Число с максимальной суммой цифр: " << numberWithMaxSum << std::endl;
        std::cout << "Сумма его цифр: " << maxSum << std::endl;

        return 0;
}
