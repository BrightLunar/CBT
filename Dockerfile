# 1. 가볍고 빠른 Alpine Linux를 운영체제로 사용
FROM alpine:3.18

# 2. Linux용 C++ 컴파일러(g++) 설치
RUN apk add --no-cache g++ make

# 3. 도커 컨테이너 안의 작업 폴더를 /app으로 설정
WORKDIR /app

# 4. 내 PC의 모든 파일(main.cpp, web폴더, questions폴더 등)을 도커 안으로 복사
COPY . .

# 5. Linux 환경에 맞춰서 C++ 빌드 
# (윈도우용 ws2_32 대신 Linux 표준 네트워크인 pthread를 연결합니다)
RUN g++ -std=c++17 -Wall -O2 main.cpp -o MathCBT_Web -lpthread

# 6. 호스팅 서버에 8080 포트를 열어주겠다고 선언
EXPOSE 8080

# 7. 컨테이너가 켜지면 실행할 명령어
CMD ["./MathCBT_Web"]
