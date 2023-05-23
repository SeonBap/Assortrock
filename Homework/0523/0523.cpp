class Test
{
public:
	int A;
	__int64 B;
	char C;
	char D;
	short E;
	int F;
};

class Player
{
public:
	int HP;
	int ATT;
};


	// [H][H][H][H][A][A][A][A] [T][T][T][T][][][][]
void TestFunction(Player _Newplayer, int _Test)
{
	__int64 ptr0 = (__int64)&_Newplayer.HP;
	__int64 ptr1 = (__int64)&_Newplayer.ATT;
	__int64 ptr2 = (__int64)&_Test;
}

int main()
{
	size_t size = sizeof(Test);
	Test test{};
	// [A][A][A][A][][][][] [B][B][B][B][B][B][B][B] [C][D][E][E][F][F][F][F]

	__int64 ptr0 = (__int64)&test.A;
	__int64 ptr1 = (__int64)&test.B;
	__int64 ptr2 = (__int64)&test.C;
	__int64 ptr3 = (__int64)&test.D;
	__int64 ptr4 = (__int64)&test.E;
	__int64 ptr5 = (__int64)&test.F;


	
	Player NewPlayer{};
	TestFunction(NewPlayer, 20);
	// [H][H][H][H][A][A][A][A] [20][20][20][20][][][][]
}