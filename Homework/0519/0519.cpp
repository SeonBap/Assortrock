#include <iostream>

int ChCount(const char* const _string, char Ch)
{
	// Ch�� ���� ���ڰ� �� �� ����ִ��� ��� �������ִ� �Լ�
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
	if (_Left == nullptr || _Right == nullptr)
	{
		return;
	}

	for (int i = 0; _Left[i]; ++i)
	{
		_Right[i] = _Left[i];
	}

	return;
}

void NumberToString(int _Number, char* Right)
{
	if (_Number == 0)
	{
		Right[0] = '0';
		return;
	}
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

	return;
}



int main()
{

	{
		// ���ڿ��� �������� ���� 0�� ���ڷ� ġ�� �ʽ��ϴ�.
		int Result = ChCount("ab aaa ccc ddd eee", 'a');
		// 4�� ���ϵǾ�� �մϴ�.
	}

	{
		char Arr[256] = "aa b c dd ee";

		TrimDelete(Arr);
		// Arr "aabcddee";

	}

	{
		// �ڸ����� ���ϵǾ�� �մϴ�.
		int Result = DigitsCount(100);
		// 3�� ���ϵǾ�� �մϴ�.
	}

	{
		// ArrCopyText�� �����ϱ�
		char ArrCopyText[256]{};

		StrCopy("aaaa bbb ccc", ArrCopyText);
	}

	{
		// int�� char�� ����ȯ
		char Result[256]{};

		NumberToString(0, Result);
		// Result = "312312";

		int i = 0;
	}
}