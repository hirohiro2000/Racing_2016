#pragma once

#include "General_Lib.h"

using namespace GeneralLib;

class PlayerCar
{
private:

	//描画部分
	Model3D* bodyModel;
	Model3D* tireModel;
	
	
	//位置情報
	Vector3f pos;
	
	//速度情報

public:
	void Update();
	void Render();


};