#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Field.h"

using namespace std;

// �R���X�g���N�^
CField::CField()
{
}

// �f�X�g���N�^
CField::~CField()
{
}

// ������
void CField::Initialization()
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

// ��m�F
void CField::CheckLine()
{
	for (int i = 0; i < FIELD_HEIGHT - 1; i++)
	{
		// �񂪃u���b�N�ł����ς������ʃt���O
		bool lineFill = true;
		for (int j = 1; j < FIELD_WIDTH - 1; j++)
		{
			// �񂪑S��"��"���ǂ���
			if (!field[i][j])
			{
				// �h���h�̏ꍇ

				// �t���O�X�V
				lineFill = false;
			}
		}

		// �u���b�N�ł����ς��̗�̗L��
		if (lineFill)
		{
			for (int j = i; 0 <j; j--)
			{
				// ��̍s�����̍s�ɃR�s�[����
				memcpy(field[j], field[j - 1], FIELD_WIDTH);
			}
		}
	}
}

// �Q�[���I�����ʏ���
bool CField::isGameEnd()
{
	bool isEnd = false;

	for (int i = 1; i < FIELD_WIDTH - 1 ; i++)
	{
		// �ŏ�̗�Ƀu���b�N�����邩�ǂ���
		if (field[0][i])
		{
			isEnd = true;
		}
	}
	return isEnd;
}


