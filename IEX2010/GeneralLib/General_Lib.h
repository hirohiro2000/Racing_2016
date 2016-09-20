#pragma once
#include "Vector_Template.h"
//TODO: 汎用的なライブラリを作成中だが、目的は挙動の確認なので、スキンメッシュは今要らない（実装において考慮する必要はない）
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

//3Dモデル
#ifdef USE_IEX

	typedef iexMesh Model3D;

#else
#ifdef USE_NL

#endif
#endif

//3Dスキンメッシュモデル
#ifdef USE_IEX

	typedef iex3DObj SkinMeshModel3D;

#else
#ifdef USE_NL

#endif
#endif

//テクスチャ
#ifdef USE_IEX

	typedef iex2DObj Texture;

#else
#ifdef USE_NL

#endif
#endif

//カメラ
#ifdef USE_IEX

	typedef iexView Camera;

#else
#ifdef USE_NL

#endif
#endif

}
