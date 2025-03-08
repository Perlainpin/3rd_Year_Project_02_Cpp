#pragma once

class WindowRender
{
public:
	WindowRender();
	virtual ~WindowRender();

	virtual bool Initialize(HWND hwnd) = 0;
	virtual void Render() = 0;

};

