#pragma once

template<typename T>
class SGX_V
{
private:
	T m_DebugValue;
public:
	void operator =(T Value);
	void operator +=(T Value);
	void operator -=(T Value);
	void operator /=(T Value);
	void operator *=(T Value);
	void operator %=(T Value);
	void operator <<=(T Value);
	void operator >>=(T Value);
	void operator &=(T Value);
	void operator |=(T value);
	void operator ^=(T Value);

	void operator =(SGX_V<T>& Src);

	bool operator <(T Value);
	bool operator >(T Value);
	bool operator <=(T Value);
	bool operator >=(T Value);
	bool operator ==(T Value);
	bool operator !=(T Value);

	operator T();
};

template<typename T>
void SGX_V<T> :: operator =(T Value)
{
	int ReturnValue;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&Value, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator +=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue += Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator -=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue -= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator /=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue /= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator *=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue *= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator %=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue %= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator <<=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue <<= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator >>=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue >>= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator &=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue &= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator |=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue |= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator ^=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue ^= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator =(SGX_V<T>& Src)
{
	T Value = Src;
	int ReturnValue;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&Value, sizeof(T));
}

template<typename T>
bool SGX_V<T> :: operator <(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue < Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator >(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue > Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator <=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue <= Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator >=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue >= Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator ==(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue == Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator !=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue != Value)
		return true;
	else
		return false;
}

template<typename T>
SGX_V<T> :: operator T()
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	return TempValue;
}
