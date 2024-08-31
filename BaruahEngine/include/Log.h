#pragma once

#include  "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

 namespace Baruah {
	class BARUAH_API Log
	{
	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log Marcos
#define BE_CORE_ERROR(...)	::Baruah::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BE_CORE_WARN(...)	::Baruah::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BE_CORE_INFO(...)	::Baruah::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BE_CORE_TRACE(...)	::Baruah::Log::GetCoreLogger()->trace(__VA_ARGS__)
							
//Client Log Marcos			
#define BE_ERROR(...)		::Baruah::Log::GetClientLogger()->error(__VA_ARGS__)
#define BE_WARN(...)		::Baruah::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BE_INFO(...)		::Baruah::Log::GetClientLogger()->info(__VA_ARGS__)
#define BE_TRACE(...)		::Baruah::Log::GetClientLogger()->trace(__VA_ARGS__)
