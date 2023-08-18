#ifndef KEYBOARDINPUT_HPP
#define KEYBOARDINPUT_HPP


class KeyboardInput final {
public:
	KeyboardInput() = default;
	KeyboardInput(const KeyboardInput&) = delete;
	KeyboardInput(KeyboardInput&&) = delete;
	KeyboardInput& operator=(const KeyboardInput&) = delete;
	KeyboardInput& operator=(KeyboardInput&&) = delete;
	~KeyboardInput();

	void ToggleKeyboardInput(const bool enabled);
};

#endif
