#pragma once
#include <gtest/gtest.h>
#include <yazol/hpp/Utilities/IO/FileMap/FileMap.hpp>

using namespace Yazol::Utilities::IO;

class FileMapTest : public testing::Test
{
public:
    FileMapTest() : m_fileMap(nullptr) {}
    virtual ~FileMapTest() {}

    FileMap* m_fileMap;

    void SetUp() override { m_fileMap = new FileMap(); }

    void TearDown() override { delete m_fileMap; }
};