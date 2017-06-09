#pragma once

#include <cstdint>
#include <string>

namespace Yazol
{
    namespace Utilities
    {
        namespace IO
        {
            class FileMap
            {
            public:
                /**
                TODO docs
                */
                FileMap();

                /**
                TODO docs
                */
                virtual ~FileMap();

                /**
                Returns the adress of the filemap
                */
                void* Initialize(const std::string& p_name, const std::size_t& p_fileMapSize);

            protected:
                bool OpenFileMap();

                bool MapFileMapIntoMemory();

            private:
                void* m_mapHandle;
                std::string m_name;
                std::size_t m_fileMapSize;
                void* m_rawMemoryOfMappedFile;
            };
        }
    }
}
