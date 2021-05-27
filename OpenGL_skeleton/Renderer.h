#pragma once
class Renderer
{
	
public:
	virtual void Draw();

	Renderer() = default;
	Renderer(const Renderer&) = default;
	Renderer(Renderer&&) = default;
	Renderer& operator=(const Renderer&) = default;
	Renderer& operator=(Renderer&&) = default;
};

