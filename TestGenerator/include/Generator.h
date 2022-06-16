#pragma once
#include <setjmp.h>
#include <iostream>

template<typename ReturnType>
struct Generator 
{

#define INIT_GENERATOR_EXECUTE int r;\

#define YIELD_VOID() r = setjmp(buffer_execution);\
if (r == 0) longjmp(buffer_start, ++i);

#define YIELD(v) value = v;\
r = setjmp(buffer_execution);\
if (r == 0) longjmp(buffer_start, ++i);

	protected:
		ReturnType value;
		jmp_buf buffer_execution, buffer_start;
		int i;
		bool executed = false;

	public:
		struct GeneratorArguments {};

		

		void init() 
		{
			int r = setjmp(buffer_start);
			if (r == 0) this->Execute();
		}

		ReturnType GetValue() { return value; };
		void next() 
		{
			int r;
			executed = false;
			
			if (!executed)
			{
				r = setjmp(buffer_start);
				if (r == 0) longjmp(buffer_execution, 1);
			}
		}

	private:
		virtual void Execute() {}
};

#define GENERATOR(name, returnType, comaSeparatedParameters)\
struct name : Generator<returnType>{\
	struct Arguments##name : GeneratorArguments {\
		comaSeparatedParameters;\
	};\
	virtual void Execute() override
#define END_GENERATOR };


GENERATOR(MyStruct, int)
{
	INIT_GENERATOR_EXECUTE
	int p = 0;

	//value = p;
	//executed = true;
	r = setjmp(buffer_execution);
	if (r == 0) longjmp(buffer_start, 1);
}
END_GENERATOR