#pragma once
#include <yazol/hpp//Utilities/Memory/Stack/MemoryMarker.hpp>
#include <yazol/hpp//Utilities/Memory/MemoryAllocator.hpp>

namespace Yazol
{
    namespace Utilities
    {
        namespace Memory
        {
            class StackAllocator : public MemoryAllocator
            {
            public:
                /**
                    Constructor
                */
                StackAllocator();

                /**
                    Initializes the stack allocator with a given memorysize. Should not be called twice.
                */
                void Initialize(const std::size_t& p_memorySize);

                /**
                Allocates and returns a pointer to a memory chunk with the size of T.
                Executes the default constructor.
                */
                template <typename T> T* Allocate(const std::uint8_t& p_alignment = 4)
                {
                    T* object = static_cast<T*>(AllocateAligned(sizeof(T), p_alignment));
                    *object = T();
                    return object;
                }

                /**
                    Clears the entire stack.
                */
                void Clear() override;

                /**
                    Get a marker which can be used to rollback memory.
                */
                MemoryMarker GetMarker();

                /**
                    Rollback stack to a specific location in the stack.
                */
                void FreeToMarker(const MemoryMarker& p_marker);

            protected:
                /**
                The current top of the stack, aka, the currently first available memory in this stack.
                */
                void* m_top;

                void* AllocateAligned(const std::size_t& p_memorySize, const std::uint8_t& p_alignment);
                void* AllocateUnaligned(const std::size_t& p_newMemorySize);
            };
        }
    }
}