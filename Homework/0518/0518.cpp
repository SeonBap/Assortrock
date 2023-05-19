int StringCount(char* _Arr)
{
    //int ChCount = 0;
    //while (Arr[ChCount])
    //{
    //    char PrintCh = Arr[ChCount];
    //    putchar(PrintCh);
    //    ++ChCount;
    //}
    // 위쪽 예제코드를 참고하세요

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
    // 한글은 들어가지 않습니다.
    
    {
        // 글자 수를 세는 함수입니다.
        // 5가 나와야 합니다.
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