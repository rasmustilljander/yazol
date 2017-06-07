#pragma once

#include <string>
#include <yazol/hpp/Utilities/IO/Mutex/Mutex.hpp>
#include <cstdint>

namespace Yazol
{
    namespace Utilities
    {
        namespace IO
        {
            class FileMapMutex : public Mutex
            {
            public:
                FileMapMutex();

                virtual ~FileMapMutex();

                /**
                Returns true if successful
                */
                bool Initialize(const std::string& p_name);

                /**
                TODO docs
                */
                bool try_lock() override;

                /**
                TODO docs
                */
                bool try_lock(const std::uint32_t& p_timeout) override;

                /**
                    Will only return if locked.
                */
                void lock() override;

                /**
                    TODO docs
               */
                void unlock() override;

            protected:
                bool InitializeExternalMutex();

                std::string m_name;
                void* m_handle;
            };
        }
    }
}
