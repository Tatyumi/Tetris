#pragma once

// �t�B�[���h�̉���
#define FIELD_WIDTH 12
// �t�B�[���h�̏c��
#define FIELD_HEIGHT 22

typedef char charFieldWeight[FIELD_WIDTH];

class  CField
{
	// �R���X�g���N�^�A�f�X�g���N�^
public:
	CField();
	~CField();

	// �����o�ϐ�
private:
	// �t�B�[���h
	char field[FIELD_HEIGHT][FIELD_WIDTH];

	//�����o�֐�
public:
	// field�A�N�Z�T
	charFieldWeight* GetField() { return field; }
	void SetField(int vecY, int vecX, char block) { field[vecY][vecX] = block; };
};