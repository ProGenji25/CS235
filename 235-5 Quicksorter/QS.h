#pragma once
#include "QSInterface.h"
#include <sstream>
#include <algorithm>
#include <fstream>

class QS : public QSInterface
{
public:
	QS();
	~QS();

	void sortAll();
	void quicksort(int left, int right);
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray() const;
	int getSize() const;
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear();

protected:
	int* Array;
	int capacity;
	size_t size = 0;
	int value;
	int left;
	int right;
	int pivotIndex;
	int bound;
};

