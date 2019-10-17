#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Field.h"

using namespace std;

// コンストラクタ
CField::CField()
{
}

// デストラクタ
CField::~CField()
{
}

// 初期化
void CField::Initialization()
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

// 列確認
void CField::CheckLine()
{
	for (int i = 0; i < FIELD_HEIGHT - 1; i++)
	{
		// 列がブロックでいっぱいか判別フラグ
		bool lineFill = true;
		for (int j = 1; j < FIELD_WIDTH - 1; j++)
		{
			// 列が全て"□"かどうか
			if (!field[i][j])
			{
				// ”□”の場合

				// フラグ更新
				lineFill = false;
			}
		}

		// ブロックでいっぱいの列の有無
		if (lineFill)
		{
			for (int j = i; 0 <j; j--)
			{
				// 上の行を下の行にコピーする
				memcpy(field[j], field[j - 1], FIELD_WIDTH);
			}
		}
	}
}

// ゲーム終了判別処理
bool CField::isGameEnd()
{
	bool isEnd = false;

	for (int i = 1; i < FIELD_WIDTH - 1 ; i++)
	{
		// 最上の列にブロックがあるかどうか
		if (field[0][i])
		{
			isEnd = true;
		}
	}
	return isEnd;
}


