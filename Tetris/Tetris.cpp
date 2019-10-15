#include <string>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
#include "Field.h"
#include "Block.h"

// 画面表示
void Display(CBlock * cBlock,CField * cField)
{
	// 配列をコピー
	cBlock->SetDispBuffer(cField->GetField());

	// ブロック描画
	cBlock->DrawBlock();

	// 画面クリア
	system("cls");

	// ブロック描画
	cBlock->Display();
}

int main()
{
	// フィールド生成
	CField Cf;

	// ブロック生成
	CBlock Cb;

	// 計測時間
	time_t t = time(NULL);

	// 無限ループ
	while (1)
	{
		// ブロックの移動が行われたかどうか
		if (Cb.MoveBlock())
		{
			// 行われた場合

			// 画面表示
			Display(&Cb,&Cf);
		}

		// 時間が更新(1秒経過)したか判別
		if (t != time(NULL))
		{
			// 更新された場合

			// 計測時間の更新
			t = time(NULL);

			// ブロック落下処理
			if (!Cb.FallBlock())
			{
				// 底についた場合

				// ブロック固定処理
				Cb.PutBlock(&Cf);

				// ブロック生成
				Cb.GeneratBlock();
			}

			// 画面表示
			Display(&Cb, &Cf);
		}
	}

	// 一時停止
	return 0;
}