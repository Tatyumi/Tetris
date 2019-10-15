#include "stdio.h"
#include "conio.h"
#include <string>
#include "Block.h"

// �u���b�N�̃^�C�v
enum MINO_TYPE
{
	I,
	O,
	S,
	Z,
	J,
	L,
	T
};

// �u���b�N�̉�]�x
enum MINO_ANGLE
{
	ZERO,                           // 0
	NINETY,                         // 90
	ONE_HANDRED_EIGHTY,             // 180
	TWO_HANDRED_SEVENTY            // 270
};

// �u���b�N�̎��
int const MinoTypes = T + 1;

// �u���b�N�̉�]���
int const MinoAngles = TWO_HANDRED_SEVENTY + 1;

// �u���b�N�̕ό`���
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
	//Z
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
	//J
	{
		//ZERO
		{
				0,1,0,0,
				0,1,0,0,
				0,1,0,0,
				0,1,0,0,
	},
	//NINETY
	{},
	//ONE_HANDRED_EIGHTY
	{},
	//TWO_HANDRED_SEVENTY
	{},
	},
	//L
		{
			//ZERO
			{
					0,1,0,0,
					0,1,0,0,
					0,1,0,0,
					0,1,0,0,
		},
		//NINETY
		{},
		//ONE_HANDRED_EIGHTY
		{},
		//TWO_HANDRED_SEVENTY
		{},
		},
		//T
			{
				//ZERO
				{
						0,1,0,0,
						0,1,0,0,
						0,1,0,0,
						0,1,0,0,
			},
			//NINETY
			{},
			//ONE_HANDRED_EIGHTY
			{},
			//TWO_HANDRED_SEVENTY
			{},
			}
};

// �R���X�g���N�^
CBlock::CBlock()
{
	minoType = 0;
	minoAngle = 0;
	vecX = 5;
	vecY = 0;
}

// �f�X�g���N�^
CBlock::~CBlock()
{
}

// �u���b�N�`��
void CBlock::DrawBlock()
{
	// �u���b�N�`��
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			// 
			displyBuffer[vecY + i][vecX + j] |= minoShapes[minoType][minoAngle][i][j];
		}
	}
}

// �u���b�N����
bool CBlock::FallBlock()
{
	// �t�B�[���h�ڐG����
	if (!IsFieldHit(vecX, vecY + 1, minoType, minoAngle))
	{
		// �ڐG���Ȃ��ꍇ

		vecY++;
		return true;
	}
	else
	{
		// �ڐG�����ꍇ

		return false;
	}
}

// �u���b�N�ړ�
bool CBlock::MoveBlock()
{
	// �L�[���͔���
	if (_kbhit())
	{
		switch (_getch())
		{
			//�uA�v�L�[
			case 'a':

				// �t�B�[���h�ڐG����
				if (!IsFieldHit(vecX - 1, vecY, minoType, minoAngle))
				{
					// ���Ɉړ�
					vecX--;
					return true;
				}
				break;

			//�uD�v�L�[
			case 'd':

				// �t�B�[���h�ڐG����
				if (!IsFieldHit(vecX + 1, vecY, minoType, minoAngle))
				{
					// �E�Ɉړ�
					vecX++;
					return true;
				}
				break;

			// �X�y�[�X�L�[
			case 0x20:

				// �t�B�[���h�ڐG����
				if (!IsFieldHit(vecX, vecY, minoType, (minoAngle + 1) % MinoAngles))
				{
					// �ό`
					minoAngle = (minoAngle + 1) % MinoAngles;
					return true;
				}
				break;
		}
	}
	return false;
}

// �t�B�[���h�ڐG����
bool CBlock::IsFieldHit(int minoX, int minoY, int minoType, int minoAngle)
{
	CField* Cf;
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			// �u���b�N���t�B�[���h�ɐڐG���邩�ǂ���
			if (minoShapes[minoType][minoAngle][i][j] && Cf->GetField()[minoY + i][minoX + j])
			{
				// �ڐG����ꍇ

				return true;
			}
		}
	}

	return false;
}

// �\���u�@�b�t�@�ݒ菈��
void CBlock::SetDispBuffer(charFieldWeight* List)
{
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		memcpy(displyBuffer[i], List[i], sizeof(List[i]));
	}
}

// �\���֐�
void CBlock::Display()
{
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			// �z����̒l���P�̏ꍇ���A����ȊO�̏ꍇ�󔒂�\������
			printf(displyBuffer[i][j] ? "��" : "�@");
		}
		printf("\n");
	}
}

// �u���b�N����
void CBlock::GeneratBlock()
{
	vecX = 5;
	vecY = 0;
	//minoType = rand() % MinoTypes;
	minoType = I;
	minoAngle = rand() % MinoAngles;
}

void CBlock::PutBlock(CField* cField)
{
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			// �t�B�[���h�Ƀu���b�N��u��
			char block =  cField->GetField()[vecY + i][vecX + j] |= minoShapes[minoType][minoAngle][i][j];
			cField->SetField(vecY + i, vecX + j, block);
		}
	}
}