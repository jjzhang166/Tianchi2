/// ********************************************************************************************************************
/// @copyright Tianchi C++ source library for Qt5 (天池共享源码库)\n
/// 天池共享源码库开发组(www.qtcn.org)\n
/// @license 授权协议：请阅读天池共享源码库附带的授权协议(LICENSE.LGPLv2.1)\n
/// ********************************************************************************************************************
/// @file tcsingleton.hpp
/// @brief 用指针实现的单例模式的模版类
/// @version 1.0
/// @date 2013.05.25
/// @author 南果梨(cnhemiya@gmail.com)
///
/// ====================================================================================================================

#pragma once
#ifndef TIANCHI_TCSINGLETON_HPP
#define TIANCHI_TCSINGLETON_HPP

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

#include <cassert>


/// @par 示例:
/// @code
/// .h文件
///
/// class demo
/// {
/// public:
/// 	int value;
/// }
///
/// typedef TcSingleton<demo> demo_singleton;
///
/// .cpp文件
///
/// 初始化宏
/// TC_SINGLETON_INIT(demo)
/// @endcode
template<typename T>
class TIANCHI_API TcSingleton
{
	typedef TcSingleton<T> this_type;

public:
	/// @brief 构造函数
	TcSingleton()
	{
		if (m_count == 0)
			m_pointer = new T;

		++m_count;
	}

	/// @brief 构造函数
	TcSingleton(const this_type &)
	{
		++m_count;
	}

	/// @brief 析构函数
	~TcSingleton()
	{
		--m_count;

		if (m_count == 0)
		{
			delete m_pointer;
			m_pointer = 0;
		}
	}

	/// @brief 返回 T *
	inline T * get() const
	{
		assert(m_pointer != 0);
		return m_pointer;
	}

	/// @brief operator *
	inline const T & operator *() const
	{
		assert(m_pointer != 0);
		return *m_pointer;
	}

	/// @brief operator ->
	inline T * operator ->() const
	{
		assert(m_pointer != 0);
		return m_pointer;
	}

	/// @brief operator =
	inline this_type & operator =(const this_type &)
	{
		return *this;
	}

private:
	static T *m_pointer;
	static int m_count;
};

/// @brief 初始化宏
#define TC_SINGLETON_INIT(__t) \
template<> int TcSingleton< __t >::m_count = 0; \
template<> __t * TcSingleton< __t >::m_pointer = 0;


#endif // TIANCHI_TCSINGLETON_HPP
