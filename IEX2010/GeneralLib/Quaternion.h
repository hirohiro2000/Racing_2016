#include "Vector_Template.h"
//�g�p�ړI
//�Q�[������Ƃ��Ďg�p�ł��邱�Ƃ��ړI�Ȃ̂�
//�Œ�����i�g�p���Ă���֐����g����悤�ɂ���

/*
��]�s��ւ̕ϊ�
�N�H�[�^�j�I�����m�̏�Z
identity
�C�ӎ���]
���K��
*/

#define QUATERNION_ZERO .0f
#define QUATERNION_ONE 1.0f

class Quaternion :public Vector4f
{
public:
	Quaternion() { Identity(); };
	void Identity()
	{
		x = QUATERNION_ZERO;
		y = QUATERNION_ZERO;
		z = QUATERNION_ZERO;
		w = QUATERNION_ONE;
	}
};