#pragma once

using DataType = int;

class HVector
{
public:
	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void operator=(HVector& _Other)
	{
		this->sizeValue = _Other.sizeValue;
		this->ArrPtr = new DataType[_Other.capacityValue];
		this->capacityValue = (DataType)_Other.capacityValue;

		for (size_t i = 0; i < _Other.sizeValue; ++i)
		{
			this->ArrPtr[i] = _Other.ArrPtr[i];
		}
	}

	size_t size()
	{
		return sizeValue;
	}

	size_t capacity()
	{
		return capacityValue;
	}

	void push_back(const DataType& _Data)
	{
		if (sizeValue + 1 > capacityValue)
		{
			reserve((int)((capacityValue + 1) * 1.5));
		}

		ArrPtr[sizeValue] = _Data;
		++sizeValue;
	}

	void reserve(size_t _capacity)
	{
		DataType* PrevPtr = ArrPtr;

		ArrPtr = new DataType[_capacity];

		if (nullptr != PrevPtr)
		{
			for (size_t i = 0; i < sizeValue; i++)
			{
				ArrPtr[i] = PrevPtr[i];
			}

		}

		capacityValue = _capacity;

		if (nullptr != PrevPtr)
		{
			delete PrevPtr;
			PrevPtr = nullptr;
		}
	}

	~HVector()
	{
		if (nullptr != ArrPtr)
		{
			delete ArrPtr;
			ArrPtr = nullptr;
		}

	}

private:
	int sizeValue = 0;
	int capacityValue = 0;
	DataType* ArrPtr = nullptr;
};
