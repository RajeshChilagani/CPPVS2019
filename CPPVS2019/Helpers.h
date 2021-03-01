#pragma once

struct Color
{
	constexpr Color() :R(0.0f), G(0.0f), B(0.0f), A(1.0f) {}
	constexpr Color(float i_R, float i_G, float i_B, float i_A) :R(i_R), G(i_G), B(i_B), A(i_A) {}
	float R, G, B, A;
};
namespace ColorName
{
	constexpr Color Red(1.0f, 0.0f, 0.0f, 1.0f);
}