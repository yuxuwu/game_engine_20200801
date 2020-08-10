
#include <gmock/gmock.h>

#include <chrono>

using namespace std::chrono;
using namespace testing;

class MainLoop {
public:
	bool running;
	int renderCount = 0;
	void run(){
		if(running == true) renderCount = 1;
	};
};

class BasicMainLoop : public Test {
public:
	MainLoop mainLoop;
};

TEST_F(BasicMainLoop, NotRunningWhenRunningStateFalse){
	mainLoop.running = false;

	mainLoop.run();

	ASSERT_THAT(mainLoop.renderCount, Eq(0));
}

TEST_F(BasicMainLoop, RunningWhenRunningStateTrue){
	mainLoop.running = true;

	mainLoop.run();

	ASSERT_THAT(mainLoop.renderCount, Gt(0));
}


int main(int argc, char** argv)
{
	InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}