#pragma once
#include<cstdarg>

namespace Engine
{
	enum class SystemSignal { None = 0 };

	class System
	{
	public:
		virtual ~System() {};
		virtual void start(SystemSignal init = SystemSignal::None, ...) = 0;
		virtual void stop(SystemSignal close = SystemSignal::None, ...) = 0;
	};
}