#include <iostream>
// patern Comand 
enum KeyPress
{
	KeyA
	, KeyB
	,KeyC
};

class Comand
{
public:
	virtual ~Comand() = default;
	virtual void execute()
	{
		std::cout << "My command" << std::endl;
	}
	virtual void Undo()
	{
		std::cout << "UNNDO" << std::endl;
	}
};
class Fire : public Comand
{
protected:
	
public:
	
	void execute()override
	{
		std::cout << "fire" << std::endl;
	}
};
class Jump : public Comand
{
protected:

public:
	
	void execute()override
	{
		std::cout << "jump" << std::endl;
	}
};
class MoveEntity : public Comand
{
public:
	MoveEntity() :
		x(0)
		,y(0)
		,PrevX(0)
		,PrevY(0)
	{}
	void execute() override
	{
		PrevX = x;
		PrevY = y;
		x += 10;
		y += 20;
		
 	}
	int x;
	int y;
	int PrevX;
	int PrevY;
};
class InputHandler
{
public:
	InputHandler() : m_buttonA(nullptr), m_buttonB(nullptr), m_buttonC(nullptr){}
	~InputHandler()
	{
		if (m_buttonA)
			delete m_buttonA;
		if (m_buttonB)
			delete m_buttonB;
		m_buttonA = nullptr;
		m_buttonB = nullptr;
	}
	Comand* handle(KeyPress key)
{
	switch (key)
	{

	case KeyPress::KeyA:

		return m_buttonA;
	case KeyPress::KeyB:

		return m_buttonB;
	case KeyPress::KeyC:
		return m_buttonC;
	}
}
	void setMapA(Comand* comand)
	{
		m_buttonA = comand;
	}
	void setMapB(Comand* comand)
	{
		m_buttonB = comand;
	}
	void setMapC(Comand* comand)
	{
		m_buttonC = comand;
	}
private : 
	Comand* m_buttonA;
	Comand* m_buttonB;
	Comand* m_buttonC;
};


int main()
{
	InputHandler input;
	input.setMapA(new Jump);
	input.setMapB(new Fire);
	input.setMapC(new MoveEntity);

	Comand* comand = input.handle(KeyPress::KeyC);
	std::cout << dynamic_cast<MoveEntity*>(comand)->x;
	comand->execute();
	
	comand->execute();


	return 0;
}
