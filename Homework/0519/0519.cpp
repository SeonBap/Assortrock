#include <iostream>

int ChCount(const char* const _string, char Ch)
{
	// Ch와 같은 문자가 몇 개 들어있는지 세어서 리턴해주는 함수
	int chCount = 0;
	if (_string == nullptr)
	{
		return 0;
	}

	for (int i = 0; _string[i]; ++i)
	{
		if (_string[i] == Ch)
		{
			++chCount;
		}
	}

	return chCount;
}

void TrimDelete(char* _string)
{
	int index{}, strCount{};

	if (_string == nullptr)
	{
		return;
	}

	while (_string[strCount])
	{
		++strCount;
	}
	

	for (int i = 0; _string[i] && i < strCount; ++i)
	{
			index = i;
			
			while (_string[index] == ' ' && index < strCount)
			{
				++index;

				if (index == strCount)
				{
					strCount = i;
				}
			}

			if (index != i)
			{
				_string[i] = _string[index];
				_string[index] = ' ';
			}
	}
}

int DigitsCount(int _Number)
{
	int count{};

	while (_Number)
	{
		_Number /= 10;
		++count;
	}

	return count;
}

void StrCopy(const char* const _Left, char* _Right)
{
	for (int i = 0; _Left[i]; ++i)
	{
		_Right[i] = _Left[i];
	}
}

void NumberToString(int _Number, char* Right)
{
	int i{};
	
	for (i = 0; _Number; ++i)
	{
		Right[i] = (char)(_Number % 10) + '0';
		_Number /= 10;
	}

	char temp{};

	for (int j = 0; j * 2 < i; ++j)
	{
		temp = Right[j];
		Right[j] = Right[i - j - 1];
		Right[i - j - 1] = temp;
	}
}



int main()
{

	{
		// 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
		int Result = ChCount("ab aaa ccc ddd eee", 'a');
		// 4가 리턴되어야 합니다.
	}

	{
		char Arr[256] = "aa b c dd ee";

		TrimDelete(Arr);
		// Arr "aabcddee";

	}

	{
		// 자릿수를 리턴되어야 합니다.
		int Result = DigitsCount(100);
		// 3이 리턴되어야 합니다.
	}

	{
		// ArrCopyText에 복사하기
		char ArrCopyText[256]{};

		StrCopy("aaaa bbb ccc", ArrCopyText);
	}

	{
		// int를 char로 형변환
		char Result[256]{};

		NumberToString(312312, Result);
		// Result = "312312";
	}
}