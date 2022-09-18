# StandLight
라즈베리파이를 이용한 탁상용 스탠드 개발 코드
![image](https://user-images.githubusercontent.com/82801399/190896582-d64b5977-4c5b-4a55-ab0d-1395d03b1fc0.png)

스탠드 : 5단계로 밝기조절. 버튼에 의해 Light1 -> Light2 -> Light3 -> Light4 -> Light5 -> Light off -> Light1 ...으로 반복됨


시계 : 현재 시각 또는 스탑워치 LCD 출력. 버튼에 의해 현재 시간 -> 스탑워치 -> 스탑워치 중지 -> 현재 시간 ... 으로 반복됨


온습도 센서 : 2초마다 현재 온도 및 습도 LCD에 출력. 일정 온도 이상이면 안전 모드로 모든 동작 멈춤과 동시에 LCD에 warning message 출력. 온도가 떨어지면 이전 상태로 다시 실행.


초음파 센서 : 1초마다 거리를 측정하여 일정 거리 내에 물체가 없으면 자리비움 상태로 보고 카운트 시작. 10초까지 센 후 모든 동작 멈춤. 다시 인식되면 이전 상태로 다시 실행.


모터 : PWM을 통해 3단계로 모터 작동. 온도 설정을 통해 일정 온도 이상일 때 모터가 돌도록 설정 가능. 온도는 5단계까지 state가 존재.


선풍기의 세기는 한 버튼에 의해 off -> motor1 -> motor2 -> motor3 -> off ...으로 반복됨.


온도 설정은 다른 하나의 버튼에 의해 23 -> 24 -> 25 -> 26 -> 27 -> 23...으로 반복됨.


//온습도 센서와 모터의 일정 온도라 함은 define되어 Temp.h에 존재함. 각각 warning temp 29, motor temp 23이다.
