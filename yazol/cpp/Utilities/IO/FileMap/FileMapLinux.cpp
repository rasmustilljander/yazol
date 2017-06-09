#include <Utilities/IO/FileMap/FileMap.hpp>

#include <Utilities/String/StringHelper.hpp>

namespace Yazol
{
    namespace Utilities
    {
        namespace IO
        {
            FileMap::FileMap() : m_mapHandle(nullptr), m_fileMapSize(0), m_rawMemoryOfMappedFile(nullptr) {}

            FileMap::~FileMap()
            {
                // TODORT Linux / Windows
            }

            void* FileMap::Initialize(const std::string& p_name, const std::size_t& p_fileMapSize)
            {
                // TODORT Linux / Windows
                return nullptr;
            }

            bool FileMap::OpenFileMap()
            {
                // TODORT Linux / Windows
                return false;
            }

            bool FileMap::MapFileMapIntoMemory()
            {
                // TODORT Linux / Windows
                return false;
            }
        }
    }
}