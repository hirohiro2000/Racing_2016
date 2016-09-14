#pragma once
//TODO: 汎用的なライブラリを作成中だが、目的は挙動の確認なので、スキンメッシュは今要らない（実装において考慮する必要はない）
#define USE_IEX

//#define USE_NL
#include "Vector_Template.h"

#ifdef USE_IEX

#include"iextreme.h"

#else
#ifdef USE_NL


#endif
#endif

namespace GeneralLib
{
//	//Tはデータ型専用
//	template<typename T,int I>
//	struct Vector
//	{
//	private:
//		BYTE val[sizeof(T) * I];
//	public:
//		property T x()
//		{
//			get()
//
//		}
//	};
//#include"Vector_Template.h"
//
	//template<typename T>
	//struct BaseVector
	//{
	//protected:
	//	BYTE* val;
	//	BaseVector(int SumArray)
	//	{
	//		val = new BYTE[sizeof(T) * SumArray];
	//	}
	//	T& GetVal(int index)
	//	{
	//		return (T&)val[sizeof(T) * index];
	//	}
	//};

	//class VectorX<>
	//{
	//public:
	//	__declspec(property(get = getX, put = putX)) x;
	//};
	//3Dモデル
	class Model3D
	{
	#ifdef USE_IEX
	protected:
		iexMesh* model;
	#else
	#ifdef USE_NL


	#endif
	#endif 
	public:
		Model3D(char* filename);
		Model3D(){};
		void Update();//行列の更新
		void Render();

	};


	//3Dスキンメッシュモデル
	class SkinMeshModel3D :public Model3D
	{
	#ifdef USE_IEX
	private:
		iex3DObj* skinMeshModel;
	#else
	#ifdef USE_NL


	#endif
	#endif 
	public:
		SkinMeshModel3D(char* filename);
		void Update();





	};
}
