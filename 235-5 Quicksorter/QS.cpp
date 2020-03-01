#include "QS.h"

QS::QS()
{
	Array = NULL;
}

QS::~QS()
{
	clear();
}

void QS::sortAll()
{
	if (size == 0) { return; }

	quicksort(0, size - 1);
}

void QS::quicksort(int left, int right)
{
	if (left < right)
	{
		int m = medianOfThree(left, right);
		if (m == -1) { return; }
		else
		{
			int part = partition(left, right, m);
			if (part == -1) { return; }
			else
			{
				quicksort(left, part - 1);
				quicksort(part + 1, right);
			}
		}
	}
}

int QS::medianOfThree(int left, int right)
{
	if (size == 0 || right <= left || left < 0 || right <= 0 || right > (size - 1) || left >= (size - 1))
	{
		return -1;
	}
	else
	{
		const int middle = (left + right) / 2;
		if (Array[middle] < Array[left])
		{
			swap(Array[left], Array[middle]);
		}
		if (Array[right] < Array[middle])
		{
			swap(Array[middle], Array[right]);
		}
		if (Array[middle] < Array[left])
		{
			swap(Array[left], Array[middle]);
		}
		if (Array[left] <= Array[middle] <= Array[right])
		{
			return middle;
		}
	}
}

int QS::partition(int left, int right, int pivotIndex)
{
	if (size == 0 || right <= left || left < 0 || right <= 0 || right > size - 1 || left >= size - 1 || pivotIndex < left || pivotIndex > right || pivotIndex < 0 || pivotIndex > size - 1)
	{
		return -1;
	}
	else
	{
		const int pivot = Array[pivotIndex];
		swap(Array[left], Array[pivotIndex]);
		int l = left + 1;
		int r = right;
		
		do {
			while ((l <= r) && (Array[l] <= pivot))
			{
				l++;
			}
			while ((l <= r) && (Array[r] > pivot))
			{
				r--;
			}
			if (l < r)
			{
				swap(Array[l], Array[r]);
			}
		} while (l <= r);
		swap(Array[l - 1], Array[left]);

		return l - 1;
	}
}

string QS::getArray() const
{
	stringstream ss;
	string s;
	for (int i = 0; i < size; i++)
	{
		ss << Array[i] << ",";
	}
	s = ss.str();
	s = s.substr(0, s.size() - 1);
	return s;
}

int QS::getSize() const
{
	return size;
}

bool QS::addToArray(int value)
{
	int input = value;
	if (size >= 0 && size < bound)
	{
		Array[size++] = input;
		return true;
	}
	else if (size >= bound)
	{
		return false;
	}

}

bool QS::createArray(int capacity)
{
	if (capacity > 0)
	{
		int* temp = new int[capacity];
		delete[] Array;
		Array = temp;
		size = 0;
		bound = capacity;
		return true;
	}
	else
	{
		return false;
	}

}

void QS::clear()
{
	if (Array != NULL)
	{
		delete[] Array;
		Array = NULL;
	}
	size = 0;
}
