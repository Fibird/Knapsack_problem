// Knapsack_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Thing
{
	int v;	// Value
	int w;	// Weight
};

void Knapsack(Thing *things, int **values, int n, int w);
void BackTrack(Thing *t, int **v, int n, int w);

int main()
{
	int num, capacity;
	Thing *t;
	int **values;

	cout << "Please Enter the number of thing: ";
	cin >> num;

	t = new Thing[num];

	cout << "Enter the value and weight of things: " << endl;
	for (int i = 0; i < num; ++i)
	{
		cin >> t[i].v >> t[i].w;
	}
	cout << "Enter the capacity of the Knapsack: ";
	cin >> capacity;

	// Allocate memory for values
	values = new int*[num];
	for (int i = 0; i < num; ++i)
		values[i] = new int[capacity];

	Knapsack(t, values, num, capacity);

	cout << "The solution is: " << endl;
	BackTrack(t, values, num - 1, capacity - 1);
	cout << endl;

    return 0;
}

void Knapsack(Thing * things, int ** values, int n, int w)
{
	for (int i = 0; i < w; ++i)
	{
		values[0][i] = 0;
		values[i][0] = 0;
	}
	for (int j = 1; j < w; ++j)
	{
		for (int i = 1; i < w; ++i)
		{
			if ((j - things[i].w) < 0)
				values[i][j] = values[i - 1][j];
			else
				values[i][j] = (values[i - 1][j] > (things[i].v + values[i - 1][j] - things[i].w) ? values[i - 1][j] : (things[i].v + values[i - 1][j] - things[i].w));
		}
	}
}

void BackTrack(Thing *t, int ** v, int n, int w)
{
	if (v[n][w] == v[n - 1][w])
	{
		cout << n << " ";
		BackTrack(t, v, n - 1, w - t[n].w);
	}
	else
	{
		BackTrack(t, v, n - 1, w);
	}
		

}

