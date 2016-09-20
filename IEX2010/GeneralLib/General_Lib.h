#pragma once
#include "Vector_Template.h"
//TODO: �ėp�I�ȃ��C�u�������쐬�������A�ړI�͋����̊m�F�Ȃ̂ŁA�X�L�����b�V���͍��v��Ȃ��i�����ɂ����čl������K�v�͂Ȃ��j
#define USE_IEX

//#define USE_NL


#ifdef USE_IEX

#include"iextreme.h"

#else
#ifdef USE_NL


#endif
#endif

namespace GeneralLib
{

//3D���f��
#ifdef USE_IEX

	typedef iexMesh Model3D;

#else
#ifdef USE_NL

#endif
#endif

//3D�X�L�����b�V�����f��
#ifdef USE_IEX

	typedef iex3DObj SkinMeshModel3D;

#else
#ifdef USE_NL

#endif
#endif

//�e�N�X�`��
#ifdef USE_IEX

	typedef iex2DObj Texture;

#else
#ifdef USE_NL

#endif
#endif

//�J����
#ifdef USE_IEX

	typedef iexView Camera;

#else
#ifdef USE_NL

#endif
#endif

}
