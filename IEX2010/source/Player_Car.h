#pragma once

#include "General_Lib.h"

using namespace GeneralLib;

class PlayerCar
{
private:

	//�`�敔��
	Model3D* bodyModel;
	Model3D* tireModel;
	
	
	//�ʒu���
	Vector3f pos;
	
	//���x���

public:
	void Update();
	void Render();


};