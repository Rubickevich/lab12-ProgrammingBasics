#include <iostream>
#include <string>
#include "windows.h"
using namespace std;
struct product {
	string productName;
	string country;
	int amount;
};
void generateProducts(product* productsArray, string* firstNameArray, string* secondNameArray)
{
	int x = 0;
	for (int i = 0; i < 5; i++) // генеруємо 25 назв з 2 масивів
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				productsArray[x].productName = firstNameArray[i] + secondNameArray[j];
				x++;
			}
		}
	}
	int randomFactor;
	string tmp;
	for (int i = 0; i < 125; i++) //Перемішаємо массив продуктів (насправді немає необхідності, але так вони будуть більш природно виглядати)
	{
		randomFactor = rand() % 125;
		tmp = productsArray[randomFactor].productName;
		productsArray[randomFactor].productName = productsArray[i].productName;
		productsArray[i].productName = tmp;
	}
};
void generateAmount(product* productsArray)
{
	for (int i = 0; i < 125; i++) //теж саме для поставок
	{
		productsArray[i].amount = rand() % 1001; //від 0 до 1000
	}
};
void giveInfo(product* productsArray)
{
	string answer;
	double averageAmount = 0;
	int allAmount = 0;
	bool success = false;
	int counter = 0;
	while (success != true)
	{
		cout << "Який ви хочете переглянути товар?" << endl;
		getline(cin, answer); //Так можна буде використовувати пробіли
		for (int i = 0; i < 125; i++)
		{
			if (productsArray[i].productName == answer)
			{
				cout << "Товар экспортуеться у країну " << productsArray[i].country << ", обсяг складає: " << productsArray[i].amount << " партій" << endl;
				allAmount += productsArray[i].amount;
				success = true;
				counter++;
			}

		}
		if (success == true)
		{
			averageAmount = allAmount / counter;
			cout << "Середній обсяг експорту товару складає: " << averageAmount << " партій" << endl;
		}
		else
		{
			cout << "Такого товару не існує!" << endl;
		}
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	product productsArray[125];
	string firstNameArray[5] = { "величезний","дорогий","унікальний","чарівний","універсальний" };
	string secondNameArray[5] = { " комп'ютер"," автомобіль"," дім"," торт"," олівець" };
	string firstCountryArray[5] = { "Республіка","Імперія","Автономний округ","Демократична держава","Соціалістична держава" };
	string secondCountryArray[5] = { " \"Новий"," \"Об'єднанний"," \"Червоний"," \"Новітній"," \"Стародавній" };
	string thirdCountryArray[5] = { " Світ\""," Спокій\""," Рух\""," Принцип\""," Ідеал\"" };
	generateProducts(productsArray, firstNameArray, secondNameArray);
	generateAmount(productsArray);
	giveInfo(productsArray);
}