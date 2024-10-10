#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <random>

static const int NUM = 1000000;

// writeToFile 함수는 주어진 데이터(map<int, int>)를 지정된 파일에 출력하는 함수이다.
void writeToFile(const char* fileName , const std::map<int, int>& data) {
  std::ofstream file(fileName);

  if (!file) {
    std::cerr << "Could not open the file " << fileName << ".";
    exit(EXIT_FAILURE);
  }

  // 데이터 포인트를 파일에 출력
  for (auto mapIt : data) file << mapIt.first << " " <<  mapIt.second << std::endl;
}

int main() {
  std::random_device seed;

  // 기본 랜덤 엔진
  std::mt19937 engine(seed());

  // 분포 설정

  // 균등 분포 (min = 0; max = 20)
  std::uniform_int_distribution<> uniformDist(0, 20);
  // 정규 분포 (mean = 50; sigma = 8)
  std::normal_distribution<> normDist(50, 8);
  // 포아송 분포 (mean = 6)
  std::poisson_distribution<> poiDist(6);
  // 감마 분포 (alpha = 1; beta = 1로 기본값 설정)
  std::gamma_distribution<> gammaDist(1, 1);

  // 분포별 빈도수를 저장할 맵
  std::map<int, int> uniformFrequency;
  std::map<int, int> normFrequency;
  std::map<int, int> poiFrequency;
  std::map<int, int> gammaFrequency;

  // NUM번 반복하여 각 분포에서 값을 생성하고 빈도수 맵에 추가
  for (int i = 1; i <= NUM; ++i) {
    ++uniformFrequency[uniformDist(engine)];
    ++normFrequency[round(normDist(engine))];
    ++poiFrequency[poiDist(engine)];
    ++gammaFrequency[round(gammaDist(engine))];
  }

  // 결과를 파일에 저장
  writeToFile("uniform_int_distribution.txt", uniformFrequency);
  writeToFile("normal_distribution.txt", normFrequency);
  writeToFile("poisson_distribution.txt", poiFrequency);
  writeToFile("gamma_distribution.txt", gammaFrequency);
}

