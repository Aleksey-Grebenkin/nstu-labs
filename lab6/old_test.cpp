#include "Food.h"
#include "Bag.h"
#include <locale>

int main()
{
  setlocale(LC_ALL, "Russian");

  const double temp = 10.0, //°С
      min_temp = 0.0,       //°С
      max_temp = 20.0,      //°С
      capacity = 460.0,     //J·kg^−1·K^−1
      q = 45000.0,          // J
      weight = 0.11;        //kg

  const string name = "Test";

  try
  {
    cout << "Создание класса с отрицательным весом." << endl;
    Food error_food(name, -5.0, 1.0, 2.0, 3.0, 4.0);
  }
  catch (const invalid_argument &e)
  {
    cout << "Исключение: " << e.what() << endl;
  }

  cout << endl;

  try
  {
    Food test(name, weight, temp, max_temp, min_temp, capacity);

    cout << "Демонстрация методов:" << endl;
    cout << "Имя: " << test.GetName() << endl;
    cout << "Температура: " << test.GetTemperature() << endl;
    cout << "Мин. температура: " << test.GetMinTemperature() << endl;
    cout << "Макс. температура: " << test.GetMaxTemperature() << endl;
    cout << "Масса: " << test.GetWeight() << endl;
    cout << "Состояние: " << test.GetStatus() << endl;
    cout << "Температура, достижимая при передаче заданного количества тепловой энергии: " << test.GetPossibleTemperature(q) << endl;

    test.TransferThermalEnergy(q);
    cout << "Состояние после передачи тепловой энергии: " << test.GetStatus() << endl;
    cout << "Текущая температура: " << test.GetTemperature() << endl;

    Bag bag(1000);
    bag.PutFood(Food(name, weight, temp, max_temp, min_temp, capacity));

    int a = bag.GetNumberDamaged(),
        b = bag.GetNumberPossibleDamaged(99999999),
        c = bag.GetCount();
    double weight_of_bag = bag.GetWeight();
    bag.RemoveFood(0);
  }
  catch (const invalid_argument &e)
  {
    cout << "Произошла ошибка в работе программы: " << e.what();
  }

  return 0;
}
