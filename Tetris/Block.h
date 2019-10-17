#pragma once
#include "Field.h"

// ブロックの横幅
#define MINO_WIDTH 4
// ブロックの縦幅
#define MINO_HEIGHT 4

typedef char charFieldWeight[FIELD_WIDTH];

class CBlock
{

	// コンストラクタ、デストラクタ
public:
	CBlock();
	~CBlock();

	// メンバ関数
public:
	// ブロック描画
	void DrawBlock();
	// ブロック落下
	bool FallBlock(CField* cField);
	// ブロック移動
	bool MoveBlock(CField* cField);
	// ブロック設置
	void PutBlock(CField* cField);
	// 画面表示
	void Display();
	// ブロック生成
	void GeneratBlock();

	// displyBufferのアクセサ
	charFieldWeight* GetDispBuffer() { return displyBuffer; }
	void SetDispBuffer(charFieldWeight* List);

private:
	// 壁に当たるかどうか
	bool IsFieldHit(int minoX, int minoY, int minoType, int minoAngle,CField* cField);

private:

	// 画面ブロック表示
	char displyBuffer[FIELD_HEIGHT][FIELD_WIDTH];
	// X座標
	int vecX;
	// Y座標
	int vecY;
	// ブロックの形
	int minoType;
	// ブロックの角度
	int minoAngle;
};
