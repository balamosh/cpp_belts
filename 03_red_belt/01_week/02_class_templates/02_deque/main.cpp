#include "deque.cpp"

#include <iostream>
using namespace std;

int	main() {
	Deque<int>	d;
	d.PushBack(0);
	d.PushBack(1);
	d.PushBack(2);
	d.PushFront(-1);
	d.PushFront(-2);
	d.PushFront(-3);
	
	cout << d.Back() << endl;
	cout << d.Front() << endl;

	for (int i = 0; i < d.Size(); i++) {
		cout << d.At(i) << ' ';
	}
	cout << endl;
	for (int i = 0; i < d.Size(); i++) {
		cout << d[i] << ' ';
	}
	cout << endl;
}