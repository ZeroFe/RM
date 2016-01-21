#pragma once
/**
파일 경로 등 변하기 쉬운 변수는 여기에 선언한다
사용법 : 이 헤더를 인클루드 하고 resData::resources[resData::enum으로 정의한 이름] 
*/
namespace resData {
	enum { SPLASH_IMAGE };
	const char * recources[] = {
		"misc/splash-800x600.png"
	};
}