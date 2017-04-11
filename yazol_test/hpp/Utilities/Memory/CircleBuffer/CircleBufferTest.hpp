#pragma once
#include <gtest/gtest.h>
#include <Utilities/Memory/Circlebuffer/Circlebuffer.hpp>
#include <Utilities/Memory/TestStruct64.hpp>

using namespace Yazol::Utilities::Memory;

class CircleBufferTest : public testing::Test
{
public:
    CircleBufferTest() {}
    virtual ~CircleBufferTest() {}

    CircleBuffer<TestStruct64>* m_circleBuffer;

    void SetUp() override { m_circleBuffer = new CircleBuffer<TestStruct64>(); }

    void TearDown() override { delete m_circleBuffer; }
};