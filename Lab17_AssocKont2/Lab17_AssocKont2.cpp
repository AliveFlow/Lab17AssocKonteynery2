#include "pch.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	multimap<string, int> rat;
	vector<string> lit{ "a_1", "a_2", "a_3",
						"b_1", "b_2", "b_3",
						"c_1", "c_2", "c_3" };

	default_random_engine rnd(time(0));
	uniform_int_distribution<int> d(-10, 20);
	uniform_int_distribution<int> c(0, 8);

	//Заполнение словаря (каждому элементу рандомное значение)

	int n;
	cout << "Введите количество элементов словаря: ";
	cin >> n;
	while (n--) {
		string S = lit[c(rnd)];
		int D = d(rnd);
		pair<string, int> tpr = make_pair(S, D);
		rat.insert(tpr);
	}

	//Добавление элементов 3-мя способами

	rat.emplace("d_1", 10);

	rat.insert({ "d_2", -5 });

	rat.insert(pair<const string, int>("d_3", 6));

	
	// Вывод всех элементы между ключами (диапазон вводится)                                       
	
	string n1, n2;
	cout << "Введите ключи:\n";
	cout << "1-ый: "; 
	cin >> n1;
	cout << "2-ой: ";
	cin >> n2;

	auto F = rat.lower_bound(n1);
	auto L = rat.upper_bound(n2);
	while (F != L) {
		cout << F->first
			<< " => "
			<< F->second
			<< endl;
		F++;
	}
	
	return 0;
}