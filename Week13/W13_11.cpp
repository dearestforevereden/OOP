#include <iomanip>
#include <iostream>

int main(){

  std::cout << std::endl;

  // 설명: 스트림 조작자의 사용 예시 시작
  std::cout << "std::setw, std::setfill and std::left, right and internal: " << std::endl;

  // 설명: std::cout.fill()는 출력에 사용될 문자를 설정한다.
  std::cout.fill('#');
  // 출력: -12345 (기본 출력)
  std::cout << -12345 << std::endl;
  // 설명: std::setw(10)은 출력 폭을 10으로 설정한다. 기본 정렬은 오른쪽.
  std::cout << std::setw(10) << -12345 << std::endl;
  // 설명: std::left는 왼쪽 정렬을 설정한다.
  std::cout << std::setw(10) << std::left << -12345 << std::endl;
  // 설명: std::right는 오른쪽 정렬을 설정한다.
  std::cout << std::setw(10) << std::right << -12345 << std::endl;
  // 설명: std::internal은 부호를 맨 앞에 두고 나머지를 오른쪽 정렬한다.
  std::cout << std::setw(10) << std::internal << -12345 << std::endl;

  std::cout << std::endl;

  // 설명: std::showpos는 양수 숫자 앞에 '+' 기호를 표시한다.
  std::cout << "std::showpos:" << std::endl;
  // 출력: 2011 (기본 출력)
  std::cout << 2011 << std::endl;
  // 출력: +2011 (std::showpos 사용)
  std::cout << std::showpos << 2011 << std::endl;

  // 설명: std::noshowpos는 양수 숫자 앞의 '+' 기호를 제거한다.
  std::cout << std::noshowpos << std::endl;

  // 설명: std::uppercase는 과학 표기법과 16진수에서 대문자를 사용한다.
  std::cout << "std::uppercase: "  << std::endl;
  // 출력: 12345678.9 (기본 출력)
  std::cout << 12345678.9 << std::endl;
  // 출력: 12345678.9 (대문자 형식으로 출력)
  std::cout << std::uppercase << 12345678.9 << std::endl;

  // 설명: std::nouppercase는 과학 표기법과 16진수에서 소문자를 사용한다.
  std::cout << std::nouppercase << std::endl;

  // 설명: std::showbase는 진수에 따라 접두사를 추가한다 (8진수: 0, 16진수: 0x).
  std::cout << "std::showbase and std::oct, dec and hex: " << std::endl;
  // 출력: 2011 (기본 출력)
  std::cout << 2011 << std::endl;
  // 출력: 3733 (8진수)
  std::cout << std::oct << 2011 << std::endl;
  // 출력: 7db (16진수)
  std::cout << std::hex << 2011 << std::endl;

  std::cout << std::endl;

  // 출력: 2011 (10진수, std::showbase 사용)
  std::cout << std::showbase;
  std::cout << std::dec << 2011 << std::endl;
  // 출력: 03733 (8진수, std::showbase 사용)
  std::cout << std::oct << 2011 << std::endl;
  // 출력: 0x7db (16진수, std::showbase 사용)
  std::cout << std::hex << 2011 << std::endl;

  // 설명: std::dec는 10진수 형식을 설정한다.
  std::cout << std::dec << std::endl;

  // 설명: std::setprecision는 부동 소수점 숫자의 소수점 이하 자리수를 설정한다.
  std::cout << "std::setprecision, std::fixed and std::scientific: " << std::endl;
  // 출력: 123.456789 (기본 출력)
  std::cout << 123.456789 << std::endl;
  // 설명: std::fixed는 고정 소수점 형식을 설정한다.
  std::cout << std::fixed << std::endl;
  // 출력: 123.457 (소수점 이하 3자리)
  std::cout << std::setprecision(3) << 123.456789 << std::endl;
  // 출력: 123.4568 (소수점 이하 4자리)
  std::cout << std::setprecision(4) << 123.456789 << std::endl;
  // 출력: 123.45679 (소수점 이하 5자리)
  std::cout << std::setprecision(5) << 123.456789 << std::endl;
  // 출력: 123.456789 (소수점 이하 6자리)
  std::cout << std::setprecision(6) << 123.456789 << std::endl;
  // 출력: 123.4567890 (소수점 이하 7자리)
  std::cout << std::setprecision(7) << 123.456789 << std::endl;
  // 출력: 123.45678900 (소수점 이하 8자리)
  std::cout << std::setprecision(8) << 123.456789 << std::endl;
  // 출력: 123.456789000 (소수점 이하 9자리)
  std::cout << std::setprecision(9) << 123.456789 << std::endl;

  std::cout << std::endl;
  // 출력: 123.456789 (기본 소수점 이하 6자리)
  std::cout << std::setprecision(6) << 123.456789 << std::endl;
  // 설명: std::scientific는 과학 표기법 형식을 설정한다.
  std::cout << std::scientific << std::endl;
  // 출력: 1.234568e+02 (과학 표기법, 소수점 이하 6자리)
  std::cout << std::setprecision(6) << 123.456789 << std::endl;
  // 출력: 1.235e+02 (과학 표기법, 소수점 이하 3자리)
  std::cout << std::setprecision(3) << 123.456789 << std::endl;
  // 출력: 1.2346e+02 (과학 표기법, 소수점 이하 4자리)
  std::cout << std::setprecision(4) << 123.456789 << std::endl;
  // 출력: 1.23457e+02 (과학 표기법, 소수점 이하 5자리)
  std::cout << std::setprecision(5) << 123.456789 << std::endl;
  // 출력: 1.234568e+02 (과학 표기법, 소수점 이하 6자리)
  std::cout << std::setprecision(6) << 123.456789 << std::endl;
  // 출력: 1.2345679e+02 (과학 표기법, 소수점 이하 7자리)
  std::cout << std::setprecision(7) << 123.456789 << std::endl;
  // 출력: 1.23456789e+02 (과학 표기법, 소수점 이하 8자리)
  std::cout << std::setprecision(8) << 123.456789 << std::endl;
  // 출력: 1.234567890e+02 (과학 표기법, 소수점 이하 9자리)
  std::cout << std::setprecision(9) << 123.456789 << std::endl;

  std::cout << std::endl;
}

