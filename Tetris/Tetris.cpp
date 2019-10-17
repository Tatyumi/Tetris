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
	// フィールド初期化
	Cf.Initialization();

	// ブロック生成
	CBlock Cb;
	// ブロック生成
	Cb.GeneratBlock();

	// 画面表示
	Display(&Cb, &Cf);

	// 計測時間
	time_t t = time(NULL);

	// 無限ループ
	while (1)
	{
		// ブロックの移動が行われたかどうか
		if (Cb.MoveBlock(&Cf))
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
			if (!Cb.FallBlock(&Cf))
			{
				// 底についた場合

				// ブロック固定
				Cb.PutBlock(&Cf);

				// 列確認
				Cf.CheckLine();

				// ゲーム終了かどうか判別
				if (Cf.isGameEnd())
				{
					break;
				}

				// ブロック生成
				Cb.GeneratBlock();
			}

			// 画面表示
			Display(&Cb, &Cf);
		}
	}


	// 画面クリア
	system("cls");

	printf("Thank You For Playing!");

	// 一時停止
	return 0;
}