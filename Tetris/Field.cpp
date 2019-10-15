#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Field.h"

using namespace std;

// コンストラクタ
CField::CField()
{
	// フィールドの初期化
	memset(field, 0, sizeof(field));

	// 左右の壁
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		// 左側
		field[i][0] = 1;

		// 右側
		field[i][FIELD_WIDTH - 1] = 1;
	}

	// 底の表示
	for (int i = 0; i < FIELD_WIDTH; i++)
	{
		field[FIELD_HEIGHT - 1][i] = 1;
	}
}

// デストラクタ
CField::~CField()
{
}

