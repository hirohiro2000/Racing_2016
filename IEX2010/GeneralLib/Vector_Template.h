#ifndef _VECTOR_TEMPLATE_H_
#define _VECTOR_TEMPLATE_H_
//template<typename T, int I>
//struct VECTOR
//{
//public:
//VECTOR()
//{
//	val = new BYTE[sizeof(T) * I];
//
//}

//理想
//#define Vector3i VECTOR<int,3>

#define Old_vec
#ifdef Old_vec

template<typename T>
class VECTORVALUE
{
	T val;
public:
	
};


template<typename T, size_t I>
class VECTORBASE
{
public:
	void mul(T& val) { /*VECTOR<T, I>::mul(val); */};

};

template<typename T, size_t I>
class VECTOR :public VECTORBASE<T, I>
{
public:
	//初期化は数字の順番を入れ替えてポインタで処理？
	VECTOR(){};
	inline VECTOR& operator *= (T val) { VECTOR<T, I>::mul(val); return *this; }
};
//
//template<typename T>
//class VECTORBASE<T, 1>
//{
//public:
//	T x;
//
//};

#define makeVectorClass(num,ValName) template<typename T>\
class VECTORBASE<T, num> :public VECTORBASE<T, num - 1>\
{\
public:\
	T ValName;\
	VECTORBASE<T, num>():ValName((T)0){};\
	inline void mul(T& val){ValName *= val; VECTORBASE<T, num - 1>::mul(val);}\
};

template<typename T>
class VECTORBASE<T, 0>
{
public:
	inline void mul(T& val) {};
	VECTORBASE<T, 0>(){};

};
makeVectorClass(1, x)
makeVectorClass(2, y)
makeVectorClass(3, z)
makeVectorClass(4, w)


//template<typename T>
//class VECTORBASE<T, 2> :public VECTORBASE<T, 1>
//{
//public:
//	T y;
//
//};
#else
template<typename T, int I>
class VECTOR
{

};

class VECTOR<T, 0>
{
public:
	T z;

};
#endif


#endif