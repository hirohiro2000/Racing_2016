#pragma once
//TODO: �ėp�I�ȃ��C�u�������쐬�������A�ړI�͋����̊m�F�Ȃ̂ŁA�X�L�����b�V���͍��v��Ȃ��i�����ɂ����čl������K�v�͂Ȃ��j
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
//	//T�̓f�[�^�^��p
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
	//3D���f��
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
		void Update();//�s��̍X�V
		void Render();

	};


	//3D�X�L�����b�V�����f��
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
