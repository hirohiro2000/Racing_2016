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
	VECTORBASE(){};
};

template<typename T, size_t Max>
class VECTOR :public VECTORBASE<T, Max,1>
{
public:
	VECTOR(){};
	#define Vector_Assign \
	for (size_t i = 0; i < Max && i < DifMax; i++)\
	{\
		(&x)[-i] = (&v.x)[-i];\
	}
	template<typename DifType,size_t DifMax>
	inline VECTOR& operator = (const VECTOR<DifType, DifMax>& v)
	{
		Vector_Assign
		return *this;
	}
	template<typename DifType, size_t DifMax>
	inline VECTOR (VECTOR<DifType, DifMax>& v)
	{
		Vector_Assign
	}
	template< typename... Vals>
	inline VECTOR(Vals... val) :VECTORBASE<T, Max, 1>(val...){};
	inline VECTOR& operator *= (T val)
	{
		for (size_t i = 0; i < Max; i++)
		{
			(&x)[-i] *= val;
		}
		return *this;
	}

	inline VECTOR operator * (T val)
	{
		VECTOR tmp(*this);
		for (size_t i = 0; i < Max; i++)
		{
			(&tmp.x)[-i] *= val;
		}
		return tmp;
	}
	inline VECTOR& operator /= (T val)
	{
		for (size_t i = 0; i < Max; i++)
		{
			(&x)[-i] /= val;
		}
		return *this;
	}

	inline VECTOR operator / (T val)
	{
		VECTOR tmp(*this);
		for (size_t i = 0; i < Max; i++)
		{
			(&tmp.x)[-i] /= val;
		}
		return tmp;
	}
	template<typename DifType, size_t DifMax>
	inline VECTOR operator + (const VECTOR<DifType, DifMax>& v)
	{
		VECTOR tmp(*this);
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&tmp.x)[-i] += (T)(&v.x)[-i];
		}
		return tmp;
	}

	template<typename DifType, size_t DifMax>
	inline VECTOR& operator += (const VECTOR<DifType, DifMax>& v)
	{
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&x)[-i] += (T)(&v.x)[-i];
		}
		return *this;
	}

	template<typename DifType, size_t DifMax>
	inline VECTOR operator - (const VECTOR<DifType, DifMax>& v)
	{
		VECTOR tmp(*this);
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&tmp.x)[-i] -= (T)(&v.x)[-i];
		}
		return tmp;
	}

	template<typename DifType, size_t DifMax>
	inline VECTOR& operator -= (const VECTOR<DifType, DifMax>& v)
	{
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&x)[-i] -= (T)(&v.x)[-i];
		}
		return *this;
	}

	inline float Lengthf()
	{
		float tmp = .0f;
		for (size_t i = 0; i < Max; i++)
		{
			tmp += (float)(&x)[-i] * (float)(&x)[-i];
		}
		return sqrtf(tmp);
	}

	inline double Lengthd()
	{
		double tmp = 0.0;
		for (size_t i = 0; i < Max; i++)
		{
			tmp += (double)(&x)[-i] * (double)(&x)[-i];
		}
		return sqrt(tmp);
	}

	inline T LengthSq()
	{
		T tmp = ( T)0;
		for (size_t i = 0; i < Max; i++)
		{
			tmp += (&x)[-i] * (&x)[-i];
		}
		return tmp;
	}
	
	void Normalize()
	{
		T l = Lengthf();
		if (l != 0)
			for (size_t i = 0; i < Max; i++)
			{
				(&x)[-i] /= l;
			}
	}
	VECTOR Normalized()
	{
		VECTOR tmp(*this);
		T l = Length<T>();
		if (l != 0)
			for (size_t i = 0; i < Max; i++)
			{
				(&tmp.x)[-i] /= l;
			}
		return tmp;
	}

	bool operator ==(const VECTOR<T,Max>& v)
	{
		for (size_t i = 0; i < Max ; i++)
		{
			if ((&x)[-i] != (&v.x)[-i])
				return false;
		}
		return true;
	}


	bool operator !=(const VECTOR<T, Max>& v)
	{
		for (size_t i = 0; i < Max; i++)
		{
			if ((&x)[-i] != (&v.x)[-i])
				return true;
		}
		return false;
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
	inline VECTORBASE<T,Max, num>(First& first, Vals&... val):VECTORBASE<T,Max, num + 1>(val...),ValName((T)first){};\
};

#define makeStopperVectorClass(num) template<typename T>\
class VECTORBASE<T, num, num + 1>\
{\
public:\
	VECTORBASE<T, num, num + 1>(){};\
};
makeStopperVectorClass(1)
makeStopperVectorClass(2)
makeStopperVectorClass(3)
makeStopperVectorClass(4)

makeVectorClass(4, w)
makeVectorClass(3, z)
makeVectorClass(2, y)
makeVectorClass(1, x)

typedef VECTOR<int, 1> Vector1i;
typedef VECTOR<int, 2> Vector2i;
typedef VECTOR<int, 3> Vector3i;
typedef VECTOR<int, 4> Vector4i;
typedef VECTOR<float, 1> Vector1f;
typedef VECTOR<float, 2> Vector2f;
typedef VECTOR<float, 3> Vector3f;
typedef VECTOR<float, 4> Vector4f;
typedef VECTOR<double, 1> Vector1d;
typedef VECTOR<double, 2> Vector2d;
typedef VECTOR<double, 3> Vector3d;
typedef VECTOR<double, 4> Vector4d;
#endif
#endif