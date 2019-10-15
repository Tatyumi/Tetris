#pragma once

// フィールドの横幅
#define FIELD_WIDTH 12
// フィールドの縦幅
#define FIELD_HEIGHT 22

typedef char charFieldWeight[FIELD_WIDTH];

class  CField
{
	// コンストラクタ、デストラクタ
public:
	CField();
	~CField();

	// メンバ変数
private:
	// フィールド
	char field[FIELD_HEIGHT][FIELD_WIDTH];

	//メンバ関数
public:
	// fieldアクセサ
	charFieldWeight* GetField() { return field; }
	void SetField(int vecY, int vecX, char block) { field[vecY][vecX] = block; };
};