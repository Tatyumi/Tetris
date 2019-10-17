#pragma once
#include "Field.h"

// �u���b�N�̉���
#define MINO_WIDTH 4
// �u���b�N�̏c��
#define MINO_HEIGHT 4

typedef char charFieldWeight[FIELD_WIDTH];

class CBlock
{

	// �R���X�g���N�^�A�f�X�g���N�^
public:
	CBlock();
	~CBlock();

	// �����o�֐�
public:
	// �u���b�N�`��
	void DrawBlock();
	// �u���b�N����
	bool FallBlock(CField* cField);
	// �u���b�N�ړ�
	bool MoveBlock(CField* cField);
	// �u���b�N�ݒu
	void PutBlock(CField* cField);
	// ��ʕ\��
	void Display();
	// �u���b�N����
	void GeneratBlock();

	// displyBuffer�̃A�N�Z�T
	charFieldWeight* GetDispBuffer() { return displyBuffer; }
	void SetDispBuffer(charFieldWeight* List);

private:
	// �ǂɓ����邩�ǂ���
	bool IsFieldHit(int minoX, int minoY, int minoType, int minoAngle,CField* cField);

private:

	// ��ʃu���b�N�\��
	char displyBuffer[FIELD_HEIGHT][FIELD_WIDTH];
	// X���W
	int vecX;
	// Y���W
	int vecY;
	// �u���b�N�̌`
	int minoType;
	// �u���b�N�̊p�x
	int minoAngle;
};
