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

//#define Old_vec
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
	VECTORBASE(T* val){};
};

template<typename T, size_t I>
class VECTOR :public VECTORBASE<T, I>
{
public:
	//初期化は数字の順番を入れ替えてポインタで処理？
	VECTOR(){};
	template< T... Vals>
	VECTOR(Vals&... vals) :VECTORBASE< T, I >((&(&vals)[I - 1])){};
	inline VECTOR& operator *= (T val) { VECTOR<T, I>::mul(val); return *this; }
	inline VECTOR operator * (T val){ VECTOR<T, I> tmp(*this); tmp *= val; return tmp; }
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
	VECTORBASE(T* val):VECTORBASE<T, num - 1>(&val[-1]),ValName((T)*val){};\
	inline void mul(T& val){ValName *= val; VECTORBASE<T, num - 1>::mul(val);}\
};

template<typename T>
class VECTORBASE<T, 0>
{
public:
	inline void mul(T& val) {};
	VECTORBASE<T, 0>(){};
	VECTORBASE(T* val){};
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
template<typename T, size_t Max, size_t Num>
class VECTORBASE
{
public:
	void mul(T& val) { /*VECTOR<T, I>::mul(val); */};
	template<typename First , typename... Vals>
	VECTORBASE(First& first, Vals&... val){};
	template<typename DifType, size_t DifMax>
	inline void Assign(VECTORBASE<DifType, DifMax, Num>& v){};
	VECTORBASE(){};
};

template<typename T, size_t Max>
class VECTOR :public VECTORBASE<T, Max,1>
{
public:
	//初期化は数字の順番を入れ替えてポインタで処理？
	VECTOR(){};
	template< typename... Vals>
	VECTOR(Vals... val) :VECTORBASE<T, Max, 1>(val...){};
	template<typename DifType,size_t DifMax>
	void Assign (VECTOR<DifType, DifMax>& v){ VECTORBASE<T, Max, 1>::Assign(v);  }
	template<typename DifType, size_t DifMax>
	inline VECTOR& operator = (VECTOR<DifType, DifMax>& v){ VECTORBASE<T, Max, 1>::Assign(v); return *this; }
	template<typename DifType, size_t DifMax>
	VECTOR (VECTOR<DifType, DifMax>& v){ VECTORBASE<T, Max, 1>::Assign(v); }
	inline VECTOR& operator *= (T val)
	{
		for (size_t i = 0; i < Max; i++)
		{
			(&x)[-i] *= val;
		}
		return *this;
	}
	inline void mul (T val)
	{
		T* data = &x;
		for (size_t i = 0; i < Max; i++)
		{
			data[-i] *= val;
		}
	}
	template<typename DifType, size_t DifMax>
	inline void Assign2(VECTOR<DifType, DifMax>& v)
	{
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&x)[-i] = (&v.x)[-i];
		}
	}

};
//
//template<typename T>
//class VECTORBASE<T, 1>
//{
//public:
//	T x;
//
//};

#define makeVectorClass(num,ValName) template<typename T,size_t Max>\
class VECTORBASE<T,Max, num> :public VECTORBASE<T,Max, num + 1>\
{\
public:\
	T ValName;\
	VECTORBASE<T,Max, num>():ValName((T)0){};\
	template<typename First,typename... Vals>\
	VECTORBASE<T,Max, num>(First& first, Vals&... val):VECTORBASE<T,Max, num + 1>(val...),ValName((T)first){};\
	inline void mul(T& val){ValName *= val; VECTORBASE<T,Max, num + 1>::mul(val);}\
	template<typename DifType,size_t DifMax>\
	inline void Assign (VECTORBASE<DifType, DifMax , num>& v){ValName = (T)v.ValName; VECTORBASE<T, Max, num + 1>::Assign(v); }\
};

#define makeStopperVectorClass(num) template<typename T>\
class VECTORBASE<T, num, num + 1>\
{\
public:\
	inline void mul(T& val) {};\
	VECTORBASE<T, num, num + 1>(){};\
	template<typename DifType,size_t DifMax>\
	inline void Assign (const VECTORBASE<DifType, DifMax , num>& v){};\
};
makeStopperVectorClass(1)
makeStopperVectorClass(2)
makeStopperVectorClass(3)
makeStopperVectorClass(4)


makeVectorClass(4, w)
makeVectorClass(3, z)
makeVectorClass(2, y)
makeVectorClass(1, x)

#endif
#endif