#pragma once

using DataType = int;

class HVector
{
public:
	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	DataType& operator=(HVector)
	{

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
		// 같은 주소를 가르킨다.
		DataType* PrevPtr = ArrPtr;

		// 같은 주소를 가르키고 같은 데이터를 가지고 있는데 지워버리면 두개가 같이 날아가서 주소와 데이터가 없어짐
		if (nullptr != ArrPtr)
		{
			delete ArrPtr;
			ArrPtr = nullptr;
		}

		// 1회의 new가 일어났다면 1회의 delete가 어딘가에 존재해야 한다.

		ArrPtr = new DataType[_capacity];

		if (nullptr != PrevPtr)
		{
			for (size_t i = 0; i < sizeValue; i++)
			{
				ArrPtr[i] = PrevPtr[i];
			}

		}

		capacityValue = _capacity;
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
