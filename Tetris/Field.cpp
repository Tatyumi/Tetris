#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Field.h"

using namespace std;

// �R���X�g���N�^
CField::CField()
{
	// �t�B�[���h�̏�����
	memset(field, 0, sizeof(field));

	// ���E�̕�
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		// ����
		field[i][0] = 1;

		// �E��
		field[i][FIELD_WIDTH - 1] = 1;
	}

	// ��̕\��
	for (int i = 0; i < FIELD_WIDTH; i++)
	{
		field[FIELD_HEIGHT - 1][i] = 1;
	}
}

// �f�X�g���N�^
CField::~CField()
{
}

