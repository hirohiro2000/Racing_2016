#pragma once

#include "General_Lib.h"

using namespace GeneralLib;

class PlayerCar
{
private:

	//•`‰æ•”•ª
	Model3D* bodyModel;
	Model3D* tireModel;
	
	
	//ˆÊ’uî•ñ
	Vector3f pos;
	
	//‘¬“xî•ñ

public:
	void Update();
	void Render();


};