int StringCount(const char* _Arr)
{
    //int ChCount = 0;
    //while (Arr[ChCount])
    //{
    //    char PrintCh = Arr[ChCount];
    //    putchar(PrintCh);
    //    ++ChCount;
    //}
    // ���� �����ڵ带 �����ϼ���

    int chCount = 0;

    if (_Arr != nullptr)
    {
        while (_Arr[chCount])
        {   
                ++chCount;
        }
    }

    return chCount;
}

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    if (_Arr == nullptr)
    {
        return;
    }

    for (int i = 0; _Arr[i]; ++i)
    {
        if (_Arr[i] == _PrevCh)
        {
            _Arr[i] = _NextCh;
        }
    }

    return;
}

int main()
{
    // �ѱ��� ���� �ʽ��ϴ�.
    
    {
        // ���� ���� ���� �Լ��Դϴ�.
        // 5�� ���;� �մϴ�.
        char Arr[100] = "aaaaa";
        int Result = StringCount(nullptr);

        int a = 0;
    }

    {
        char Arr[100] = "aaa bbb ccc";

        // "aaa bbb ccc"; => "aaa bbb ddd";
        ChangeCh(Arr, 'c', 'd');

        int a = 0;
    }
}