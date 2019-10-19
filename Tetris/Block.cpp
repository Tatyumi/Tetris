#include "stdio.h"
#include "conio.h"
#include <string>
#include "Block.h"

// ブロックの種類
int const MinoTypes = T + 1;

// ブロックの回転種類
int const MinoAngles = TWO_HANDRED_SEVENTY + 1;

// ブロックの変形種類
char minoShapes[MinoTypes][MinoAngles][MINO_HEIGHT][MINO_WIDTH] = {
	//I
	{
		//ZERO
		{
			0,1,0,0,
			0,1,0,0,
			0,1,0,0,
			0,1,0,0,
		},
		//NINETY
		{
			0,0,0,0,
			0,0,0,0,
			1,1,1,1,
			0,0,0,0,
		},
		//ONE_HANDRED_EIGHTY
		{
			0,0,1,0,
			0,0,1,0,
			0,0,1,0,
			0,0,1,0,
		},
		//TWO_HANDRED_SEVENTY
		{
			0,0,0,0,
			1,1,1,1,
			0,0,0,0,
			0,0,0,0,
		},
	},
	//O
	{
		//ZERO
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		//NINETY
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		//ONE_HANDRED_EIGHTY
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		//TWO_HANDRED_SEVENTY
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
	},
	//S
	{
		//ZERO
		{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0,
		},
		//NINETY
		{
			0,1,0,0,
			0,1,1,0,
			0,0,1,0,
			0,0,0,0,
		},
		//ONE_HANDRED_EIGHTY
		{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0,
		},
		//TWO_HANDRED_SEVENTY
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,1,0,
		},
	},
	//Z
	{
		//ZERO
		{
			0,0,0,0,
			1,1,0,0,
			0,1,1,0,
			0,0,0,0,
		},
		//NINETY
		{
			0,0,0,0,
			0,0,1,0,
			0,1,1,0,
			0,1,0,0,
		},
		//ONE_HANDRED_EIGHTY
		{
			0,0,0,0,
			0,1,1,0,
			0,0,1,1,
			0,0,0,0,
		},
		//TWO_HANDRED_SEVENTY
		{
			0,0,1,0,
			0,1,1,0,
			0,1,0,0,
			0,0,0,0,
		},
	},
	//J
	{
		//ZERO
		{
				0,0,1,0,
				0,0,1,0,
				0,1,1,0,
				0,0,0,0,
	},
	//NINETY
	{
				0,0,0,0,
				0,1,0,0,
				0,1,1,1,
				0,0,0,0,
	},
	//ONE_HANDRED_EIGHTY
	{
				0,0,0,0,
				0,1,1,0,
				0,1,0,0,
				0,1,0,0,
	},
	//TWO_HANDRED_SEVENTY
	{
				0,0,0,0,
				1,1,1,0,
				0,0,1,0,
				0,0,0,0,
	},
	},
	//L
		{
			//ZERO
			{
					0,1,0,0,
					0,1,0,0,
					0,1,1,0,
					0,0,0,0,
		},
		//NINETY
		{
					0,0,0,0,
					0,1,1,1,
					0,1,0,0,
					0,0,0,0,},
		//ONE_HANDRED_EIGHTY
		{
					0,0,0,0,
					0,1,1,0,
					0,0,1,0,
					0,0,1,0,},
		//TWO_HANDRED_SEVENTY
		{
					0,0,0,0,
					0,0,1,0,
					1,1,1,0,
					0,0,0,0,},
		},
		//T
			{
				//ZERO
				{
						0,0,0,0,
						1,1,1,0,
						0,1,0,0,
						0,0,0,0,
			},
			//NINETY
			{
						0,1,0,0,
						1,1,0,0,
						0,1,0,0,
						0,0,0,0,},
			//ONE_HANDRED_EIGHTY
			{
						0,1,0,0,
						1,1,1,0,
						0,0,0,0,
						0,0,0,0,},
			//TWO_HANDRED_SEVENTY
			{
						0,1,0,0,
						0,1,1,0,
						0,1,0,0,
						0,0,0,0,},
			}
};

// コンストラクタ
CBlock::CBlock()
{
	minoType = 0;
	minoAngle = 0;
	vecX = 5;
	vecY = 0;
}

// デストラクタ
CBlock::~CBlock()
{
}

// ブロック描画
void CBlock::DrawBlock()
{
	// ブロック描画
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			// 
			displyBuffer[vecY + i][vecX + j] |= minoShapes[minoType][minoAngle][i][j];
		}
	}
}

// ブロック落下
bool CBlock::FallBlock(CField* cField)
{
	// フィールド接触判定
	if (!IsFieldHit(vecX, vecY + 1, minoType, minoAngle, cField))
	{
		// 接触しない場合

		vecY++;
		return true;
	}
	//else
	{
		// 接触した場合

		return false;
	}
}

// ブロック移動
bool CBlock::MoveBlock(CField* cField)
{
	// キー入力判別
	if (_kbhit())
	{
		switch (_getch())
		{
			//「A」キー
			case 'a':

				// フィールド接触判定
				if (!IsFieldHit(vecX - 1, vecY, minoType, minoAngle, cField))
				{
					// 左に移動
					vecX--;
					return true;
				}
				break;

				//「D」キー
			case 'd':

				// フィールド接触判定
				if (!IsFieldHit(vecX + 1, vecY, minoType, minoAngle, cField))
				{
					// 右に移動
					vecX++;
					return true;
				}
				break;

				//「S」キー
			case 's':

				// フィールド接触判定
				if (!IsFieldHit(vecX, vecY + 1, minoType, minoAngle, cField))
				{
					// ↓に移動
					vecY++;
					return true;
				}
				break;

				// スペースキー
			case 0x20:

				// フィールド接触判定
				if (!IsFieldHit(vecX, vecY, minoType, (minoAngle + 1) % MinoAngles, cField))
				{
					// 変形
					minoAngle = (minoAngle + 1) % MinoAngles;
					return true;
				}
				break;
		}
	}
	return false;
}

// フィールド接触判定
bool CBlock::IsFieldHit(int minoX, int minoY, int minoType, int minoAngle, CField* cField)
{
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			// ブロックがフィールドに接触するかどうか
			if (minoShapes[minoType][minoAngle][i][j] && cField->GetField()[minoY + i][minoX + j])
			{
				// 接触する場合


				return true;
			}
		}
	}

	return false;
}

// 表示ブァッファ設定処理
void CBlock::SetDispBuffer(charFieldWeight* List)
{
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		memcpy(displyBuffer[i], List[i], sizeof(List[i]));
	}
}

// 表示関数
void CBlock::Display()
{
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			// 配列内の値が１の場合■、それ以外の場合空白を表示する
			printf(displyBuffer[i][j] ? "■" : "　");
		}
		printf("\n");
	}
}

// ブロック生成
void CBlock::GeneratBlock()
{
	vecX = 5;
	vecY = 0;
	minoType = rand() % MinoTypes;
	//minoType = I;
	minoAngle = rand() % MinoAngles;
}

void CBlock::PutBlock(CField* cField)
{
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			// フィールドにブロックを置く
			char block = cField->GetField()[vecY + i][vecX + j] |= minoShapes[minoType][minoAngle][i][j];
			cField->SetField(vecY + i, vecX + j, block);
		}
	}
}