#include "Vector_Template.h"
//使用目的
//ゲーム制作として使用できることが目的なので
//最低限普段使用している関数が使えるようにする

/*
回転行列への変換
クォータニオン同士の乗算
identity
任意軸回転
正規化
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