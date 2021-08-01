#pragma once

#include "QAQ.h"

class TestingLayer : public QAQ::Layer
{
public:
	TestingLayer();
	virtual ~TestingLayer() = default;


	void OnUpdate(QAQ::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(QAQ::Event& e) override;

    void TestDynamicConstant();
};