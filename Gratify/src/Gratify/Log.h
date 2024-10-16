#pragma once
#include "Core.h"
#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Gratify {

	class GFAPI Log
	{
	public:
		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() {
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger > GetClientLogger() {
			return s_ClientLogger;
		}

		static void Init();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define GF_CORE_TRACE(...)		::Gratify::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GF_CORE_INFO(...)		::Gratify::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GF_CORE_WARN(...)		::Gratify::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GF_CORE_CRITICAL(...)	::Gratify::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define GF_CORE_ERROR(...)		::Gratify::Log::GetCoreLogger()->error(__VA_ARGS__)

#define GF_TRACE(...)			::Gratify::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GF_INFO(...)			::Gratify::Log::GetClientLogger()->info(__VA_ARGS__)
#define GF_WARN(...)			::Gratify::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GF_CRITICAL(...)		::Gratify::Log::GetClientLogger()->critical(__VA_ARGS__)
#define GF_ERROR(...)			::Gratify::Log::GetClientLogger()->error(__VA_ARGS__)


