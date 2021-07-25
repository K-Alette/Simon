#ifndef __InputHandler__
#define __InputHandler__

#include <vector>
#include <utility>

#include "SDL.h"
#include "Vector.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}

	void update();
	void clean();

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}
	Vector* getMousePosition()
	{
		return m_mousePosition;
	}
	bool isKeyDown(SDL_Scancode key);

	void reset();

private:
	InputHandler();
	~InputHandler() { delete m_mousePosition; }

	static InputHandler* s_pInstance;

	std::vector<bool> m_mouseButtonStates;
	Vector* m_mousePosition;
	const Uint8* m_keystates;

	// handle keyboard events
	void onKeyDown();
	void onKeyUp();

	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);
};
typedef InputHandler IH;

#endif // __InputHandler__