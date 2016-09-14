#include "General_Lib.h"


#ifdef USE_IEX
	Model3D::Model3D(char * filename)
	{
		model = new iexMesh(filename);

	}

	void Model3D::Update()
	{
		model->Update();
	}

	void Model3D::Render()
	{
		model->Render();
	}

#else
#ifdef USE_NL


#endif
#endif 
