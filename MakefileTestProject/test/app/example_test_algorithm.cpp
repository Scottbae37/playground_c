/*
 * Calculator.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: scottbae37
 */
#include "gtest/gtest.h"

extern "C"{
#include "../../src/app/example_algorithm1.h"
}

class Calculator {
	int value;
public:
	Calculator() :
			value(0) {
	}
	void plus(int n) {
		value += n;
	}
	void minus(int n) {
		value -= n;
	}
	int display() {
		return value;
	}
	;
};
// Fixture
//  정의: xUnit Test Pattern에서 SUT를 실행하기 위해 준비해야 하는 모든 것
//    픽스쳐를 구성하는 모든 로직 부분을 '픽스쳐 설치'라고 합니다.

/*  필스쳐 설치 방법 1. 인라인 픽스쳐 설치 */
//  : 모든 픽스쳐 설치를 테스트 함수 안에서 처리한다.
// Pros: 픽스쳐의 설치와 검증 로직이 하나의 함수 안에 존재하기 때문에 인과 관계를 쉽게 파악할 수 있음.
// Cons: 코드 중복의 이슈가 발생함
//       픽스쳐의 설치자체가 복잡하다면, 테스트 코드를 이해하기 어렵게 만든다.

// 코드 중복 - 테스트 냄새
//  1. 깨지기 쉬운 테스트

/*TEST(CalculatorTest, plusTest2) {
    Calculator * cal = new Calculator;

	cal->plus(2);
	cal->plus(2);

	ASSERT_EQ(4, cal->display())<< "2+2 = 4";
}
TEST(CalculatorTest, minusTest){
    Calculator * cal = new Calculator;

    cal->minus(2);
    cal->minus(2);

    ASSERT_EQ(-4, cal->display())<< "2-2 = 4";
}*/
#if 1
/* 픽스쳐 설치 방법 2. Delegate setup */
//	1. 동일한 픽스쳐를 가진 테스트 함수를 클래스로 묶는다.
//		=> Testcase Clase
//	2. 픽스쳐 설치에 관한 중복되는 코드를 함수로 제공한다.

// Testcase class를 만드는 방법
class CalculatorTest:public ::testing::Test{
	//gtest에서는 test utility method의 접근 지정자는 반드시 protected로 만들어야 함
protected:
	// creation method
	//	=> SUT의 생성 방법이 변겨오디어도, create()함수 하나만 수정하면 됨.
	Calculator* create(){
		return new Calculator;
	}
};

TEST_F(CalculatorTest, plusTest2) {
    Calculator * cal = create();

	cal->plus(2);
	cal->plus(2);

	ASSERT_EQ(4, cal->display())<< "2+2 = 4";
}
TEST_F(CalculatorTest, minusTest){
    Calculator * cal = create();

    cal->minus(2);
    cal->minus(2);

    ASSERT_EQ(-4, cal->display())<< "2-2 = 4";
}
#endif



#if 0
/* 픽스쳐 설치 방법 3. 암묵적 설치 */
//	:여러 테스트에서 같은 테스트 픽스쳐를 setup()함수를 통해 생성함.
//	=> xUnit Test Framework가 지원하는 기능
//	Pros: 테스트 코드 중복을 제거하고, 꼭 필요하지 않은 상호작용을 캡슐화 할 수 있다.
//	Cons: 픽스쳐의 설치 코드가 테스트 함수 밖에 존재하기 때문에 테스트의 함수 만으로
//			코드 이해가 어려울 수 있음

//3A(Arrange, Act, Assert)
//	=> 4단계 테스트
// 	1단계 : 테스트의 픽스쳐를 설치하거나, 실제 결과를 관찰하기 위해 필요한 것을 집어넣는 작업
// 	2단계 : SUT와 상호작용한다.
// 	3단계 : 기대 결과를 확인한다.
// 	4단계 : 테스트 픽스쳐를 해체해서, 테트ㅡ 시작 상태로 돌려놓는다.

// 대부분의 xUnit Test Framewok은 테스트 함수를 수행하기 이전에 새롭게 생성한 TestCase 클래스를 사용
// 	=> 신선한 픽스쳐 전략
// TestCase tc = new TestCase();
// tc.SetUp
// tc.TearDown
//
// TestCase tc = new TestCase();
// tc.SetUp
// tc.TearDown
//
#include <stdio.h>
#include <memory>
class CalculatorTest:public ::testing::Test{
public:
	CalculatorTest(){
		printf("Constructor()\n");
	}
protected:
	Calculator * cal;
//	shared_ptr<Calculator> cal; //c++14

	//JUNIT @BeforeEach - JUNUT5 @Before
	virtual void SetUp(){ //Upper char means Public normally,
		printf("SetUP();\n");
		cal = new Calculator;
	}
	//JUNIT @AfterEach - JUNUT5 @After
	virtual void TearDown(){
		printf("TearDown();\n");
		delete cal;
	}
};

TEST_F(CalculatorTest, plusTest) {
//    Calculator * cal = create();
	printf("plusTest();\n");

	cal->plus(2);
	cal->plus(2);

	ASSERT_EQ(4, cal->display())<< "2+2 = 4";
}
TEST_F(CalculatorTest, minusTest){
	printf("minusTest();\n");
//    Calculator * cal = create();

    cal->minus(2);
    cal->minus(2);

    ASSERT_EQ(-4, cal->display())<< "2-2 = 4";
}
#endif
